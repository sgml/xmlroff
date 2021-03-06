/* Fo
 * fo-id.h: Id datatype
 *
 * Copyright (C) 2001-2005 Sun Microsystems
 * Copyright (C) 2007 Menteith Consulting Ltd
 *
 * !See COPYING for the status of this software.
 */

#ifndef __FO_ID_H__
#define __FO_ID_H__

#include <libfo/fo-utils.h>

G_BEGIN_DECLS

#define FO_TYPE_ID              (fo_id_get_type ())
#define FO_ID(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), FO_TYPE_ID, FoId))
#define FO_ID_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), FO_TYPE_ID, FoIdClass))
#define FO_IS_ID(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), FO_TYPE_ID))
#define FO_IS_ID_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), FO_TYPE_ID))
#define FO_ID_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), FO_TYPE_ID, FoIdClass))


typedef struct _FoId      FoId;
typedef struct _FoIdClass FoIdClass;

GType        fo_id_get_type       (void) G_GNUC_CONST;
FoDatatype * fo_id_new_with_value (const gchar* value);

gchar*       fo_id_get_value      (FoDatatype  *id);

G_END_DECLS

#endif /* !__FO_ID_H__ */
