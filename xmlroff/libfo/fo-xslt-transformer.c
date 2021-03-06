/* Fo
 * fo-xslt-transformer.c: Wrapper for libxslt XSLT processor
 *
 * Copyright (C) 2003-2006 Sun Microsystems
 * Copyright (C) 2007-2009 Menteith Consulting Ltd
 *
 * See COPYING for the status of this software.
 */

#include <libxslt/xslt.h>
#include <libxslt/xsltInternals.h>
#include <libxslt/transform.h>
#include <libxslt/xsltconfig.h>
#include "libfo/fo-utils.h"
#include "fo-xml-doc-private.h"
#include "fo-xslt-transformer.h"

/**
 * SECTION:fo-xslt-transformer
 * @short_description: libxslt XSLT processor
 *
 * Wrapper for libxslt XSLT processor.
 */

extern int xmlLoadExtDtdDefaultValue;

const char *fo_xslt_transformer_error_messages [] = {
  N_("FoXsltTransformer error"),
  N_("XSLT transform failed"),
  N_("No input stylesheet specified"),
  N_("No input XML document"),
  N_("Parsing stylesheet as stylesheet failed"),
};

static LibfoVersionInfo version_info =
  {
    LIBFO_MODULE_XSLT_PROCESSOR,
    "libxslt",
    NULL,
    LIBXSLT_VERSION,
    LIBXSLT_VERSION_STRING,
    0,
    NULL
  };

/**
 * fo_xslt_transformer_error_quark:
 * 
 * Get the error quark for #FoXsltTransformer.
 *
 * If the quark does not yet exist, create it.
 * 
 * Return value: #GQuark associated with #FoXsltTransformer errors.
 **/
GQuark
fo_xslt_transformer_error_quark (void)
{
  static GQuark quark = 0;
  if (quark == 0)
    quark = g_quark_from_static_string ("FoXsltTransformer error");
  return quark;
}

const LibfoVersionInfo *
fo_xslt_transformer_version_info (void)
{
  version_info.runtime = xsltLibxsltVersion;
  version_info.runtime_string = xsltEngineVersion;

  return &version_info;
}


/**
 * fo_xslt_transformer_do_transform:
 * @xml_doc:        Input document.
 * @stylesheet_doc: Stylesheet document.
 * @error:          Indication of any error that occurred.
 * 
 * Apply @stylesheet_doc to @xml_doc and return the result.
 *
 * Frees @stylesheet_doc.
 *
 * Return value: A new result tree that is freed by the caller.
 **/
FoXmlDoc *
fo_xslt_transformer_do_transform (FoXmlDoc          *xml_doc,
				  FoXmlDoc          *stylesheet_doc,
				  GError           **error)
{
  g_return_val_if_fail (error == NULL || *error == NULL, NULL);

  if (stylesheet_doc == NULL)
    {
      g_set_error (error,
		   FO_XSLT_TRANSFORMER_ERROR,
		   FO_XSLT_TRANSFORMER_ERROR_NO_STYLESHEET_DOC,
		   "%s",
		   _(fo_xslt_transformer_error_messages[FO_XSLT_TRANSFORMER_ERROR_NO_STYLESHEET_DOC]));
      return NULL;
    }

  if (xml_doc == NULL)
		
    {
      g_set_error (error,
		   FO_XSLT_TRANSFORMER_ERROR,
		   FO_XSLT_TRANSFORMER_ERROR_NO_XML_DOC,
		   "%s",
		   _(fo_xslt_transformer_error_messages[FO_XSLT_TRANSFORMER_ERROR_NO_XML_DOC]));
      return NULL;
    }

  xsltStylesheetPtr stylesheet =
    xsltParseStylesheetDoc (fo_xml_doc_get_xml_doc (stylesheet_doc));

  if (stylesheet == NULL)
    {
      g_set_error (error,
		   FO_XSLT_TRANSFORMER_ERROR,
		   FO_XSLT_TRANSFORMER_ERROR_PARSE_FAILED,
		   "%s",
		   _(fo_xslt_transformer_error_messages[FO_XSLT_TRANSFORMER_ERROR_PARSE_FAILED]));

      return NULL;
    }
  else
    {
      xmlDocPtr result_doc =
	xsltApplyStylesheet (stylesheet,
			     fo_xml_doc_get_xml_doc (xml_doc),
			     NULL);

      if (result_doc == NULL)
	{
	  g_set_error (error,
		       FO_XSLT_TRANSFORMER_ERROR,
		       FO_XSLT_TRANSFORMER_ERROR_TRANSFORM_FAILED,
		       "%s",
		       _(fo_xslt_transformer_error_messages[FO_XSLT_TRANSFORMER_ERROR_TRANSFORM_FAILED]));

	  return NULL;
	}

      xsltFreeStylesheet (stylesheet);
      fo_xml_doc_set_xml_doc (stylesheet_doc,
			      NULL);
      fo_xml_doc_unref (stylesheet_doc);

      gchar *base = fo_xml_doc_get_base (xml_doc);

      FoXmlDoc *result_tree = fo_xml_doc_new_from_xml_doc (result_doc);

      fo_xml_doc_set_base (result_tree,
			   base);
      g_free (base);

      return result_tree;
    }
}

