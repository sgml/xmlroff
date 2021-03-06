/* Fo
 * fo-property-keep-together-within-line.h: 'keep-together-within-line' property
 *
 * Copyright (C) 2001 Sun Microsystems
 * Copyright (C) 2007-2008 Menteith Consulting Ltd
 *
 * See COPYING for the status of this software.
 */

#ifndef __FO_PROPERTY_KEEP_TOGETHER_WITHIN_LINE_H__
#define __FO_PROPERTY_KEEP_TOGETHER_WITHIN_LINE_H__

#include <libfo/fo-utils.h>
#include <libfo/property/fo-property.h>

G_BEGIN_DECLS

/* keep-together-within-line */
/* Inherited: TRUE */
/* Shorthand: FALSE */
/* <keep> | inherit */
/* Initial value: .within-line=auto, .within-column=auto, .within-page=auto */

#define FO_TYPE_PROPERTY_KEEP_TOGETHER_WITHIN_LINE              (fo_property_keep_together_within_line_get_type ())
#define FO_PROPERTY_KEEP_TOGETHER_WITHIN_LINE(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), FO_TYPE_PROPERTY_KEEP_TOGETHER_WITHIN_LINE, FoPropertyKeepTogetherWithinLine))
#define FO_PROPERTY_KEEP_TOGETHER_WITHIN_LINE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), FO_TYPE_PROPERTY_KEEP_TOGETHER_WITHIN_LINE, FoPropertyKeepTogetherWithinLineClass))
#define FO_IS_PROPERTY_KEEP_TOGETHER_WITHIN_LINE(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), FO_TYPE_PROPERTY_KEEP_TOGETHER_WITHIN_LINE))
#define FO_IS_PROPERTY_KEEP_TOGETHER_WITHIN_LINE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), FO_TYPE_PROPERTY_KEEP_TOGETHER_WITHIN_LINE))
#define FO_PROPERTY_KEEP_TOGETHER_WITHIN_LINE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), FO_TYPE_PROPERTY_KEEP_TOGETHER_WITHIN_LINE, FoPropertyKeepTogetherWithinLineClass))


typedef struct _FoPropertyKeepTogetherWithinLine      FoPropertyKeepTogetherWithinLine;
typedef struct _FoPropertyKeepTogetherWithinLineClass FoPropertyKeepTogetherWithinLineClass;

GType       fo_property_keep_together_within_line_get_type    (void) G_GNUC_CONST;
FoProperty* fo_property_keep_together_within_line_new         (void);
FoProperty* fo_property_keep_together_within_line_get_initial (void);

G_END_DECLS

#endif /* !__FO_PROPERTY_KEEP_TOGETHER_WITHIN_LINE_H__ */
