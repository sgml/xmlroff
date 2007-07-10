/* Fo
 * fo-token.h: Token datatype
 *
 * Copyright (C) 2001 Sun Microsystems
 * Copyright (C) 2007 Menteith Consulting Ltd
 *
 * See COPYING for the status of this software.
 */

#ifndef __FO_TOKEN_H__
#define __FO_TOKEN_H__

#include <libfo/fo-utils.h>

G_BEGIN_DECLS

#define FO_TYPE_TOKEN              (fo_token_get_type ())
#define FO_TOKEN(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), FO_TYPE_TOKEN, FoToken))
#define FO_TOKEN_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), FO_TYPE_TOKEN, FoTokenClass))
#define FO_IS_TOKEN(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), FO_TYPE_TOKEN))
#define FO_IS_TOKEN_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), FO_TYPE_TOKEN))
#define FO_TOKEN_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), FO_TYPE_TOKEN, FoTokenClass))


typedef struct _FoToken      FoToken;
typedef struct _FoTokenClass FoTokenClass;

GType         fo_token_get_type      (void) G_GNUC_CONST;
FoDatatype *fo_token_new           (void);

void fo_token_set_value (FoToken *token,
			  const gchar* new_value);
gchar* fo_token_get_value (FoToken *token);

G_END_DECLS

#endif /* !__FO_TOKEN_H__ */