/* Fo
 * fo-table-caption-private.h: Structures private to 'table-caption' formatting object
 *
 * Copyright (C) 2001 Sun Microsystems
 * Copyright (C) 2007 Menteith Consulting Ltd
 *
 * See COPYING for the status of this software.
 */

#ifndef __FO_TABLE_CAPTION_PRIVATE_H__
#define __FO_TABLE_CAPTION_PRIVATE_H__

#include <libfo/fo/fo-marker-parent-private.h>
#include <libfo/fo/fo-table-caption.h>
#include <libfo/property/fo-property.h>

G_BEGIN_DECLS

struct _FoTableCaption
{
  FoMarkerParent parent_instance;

  FoProperty *background_color;
  FoProperty *background_image;
  FoProperty *block_progression_dimension;
  FoProperty *border_after_color;
  FoProperty *border_after_style;
  FoProperty *border_after_width;
  FoProperty *border_before_color;
  FoProperty *border_before_style;
  FoProperty *border_before_width;
  FoProperty *border_bottom_color;
  FoProperty *border_bottom_style;
  FoProperty *border_bottom_width;
  FoProperty *border_end_color;
  FoProperty *border_end_style;
  FoProperty *border_end_width;
  FoProperty *border_left_color;
  FoProperty *border_left_style;
  FoProperty *border_left_width;
  FoProperty *border_right_color;
  FoProperty *border_right_style;
  FoProperty *border_right_width;
  FoProperty *border_start_color;
  FoProperty *border_start_style;
  FoProperty *border_start_width;
  FoProperty *border_top_color;
  FoProperty *border_top_style;
  FoProperty *border_top_width;
  FoProperty *height;
  FoProperty *id;
  FoProperty *inline_progression_dimension;
  FoProperty *keep_together;
  FoProperty *keep_together_within_column;
  FoProperty *keep_together_within_line;
  FoProperty *keep_together_within_page;
  FoProperty *padding_after;
  FoProperty *padding_before;
  FoProperty *padding_bottom;
  FoProperty *padding_end;
  FoProperty *padding_left;
  FoProperty *padding_right;
  FoProperty *padding_start;
  FoProperty *padding_top;
  FoProperty *role;
  FoProperty *source_document;
  FoProperty *width;
};

struct _FoTableCaptionClass
{
  FoMarkerParentClass parent_class;
};

G_END_DECLS

#endif /* !__FO_TABLE_CAPTION_PRIVATE_H__ */
