/* Fo
 * fo-property-master-name.h: 'master-name' property
 *
 * Copyright (C) 2001 Sun Microsystems
 * Copyright (C) 2007-2008 Menteith Consulting Ltd
 *
 * See COPYING for the status of this software.
 */

#ifndef __FO_PROPERTY_MASTER_NAME_H__
#define __FO_PROPERTY_MASTER_NAME_H__

#include <libfo/fo-utils.h>
#include <libfo/property/fo-property.h>

G_BEGIN_DECLS

/* master-name */
/* <name> */
/* Initial value: an empty name */
/* NO ENUMERATED VALUE */

#define FO_TYPE_PROPERTY_MASTER_NAME              (fo_property_master_name_get_type ())
#define FO_PROPERTY_MASTER_NAME(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), FO_TYPE_PROPERTY_MASTER_NAME, FoPropertyMasterName))
#define FO_PROPERTY_MASTER_NAME_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), FO_TYPE_PROPERTY_MASTER_NAME, FoPropertyMasterNameClass))
#define FO_IS_PROPERTY_MASTER_NAME(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), FO_TYPE_PROPERTY_MASTER_NAME))
#define FO_IS_PROPERTY_MASTER_NAME_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), FO_TYPE_PROPERTY_MASTER_NAME))
#define FO_PROPERTY_MASTER_NAME_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), FO_TYPE_PROPERTY_MASTER_NAME, FoPropertyMasterNameClass))


typedef struct _FoPropertyMasterName      FoPropertyMasterName;
typedef struct _FoPropertyMasterNameClass FoPropertyMasterNameClass;

GType       fo_property_master_name_get_type    (void) G_GNUC_CONST;
FoProperty* fo_property_master_name_new         (void);
FoProperty* fo_property_master_name_get_initial (void);

G_END_DECLS

#endif /* !__FO_PROPERTY_MASTER_NAME_H__ */
