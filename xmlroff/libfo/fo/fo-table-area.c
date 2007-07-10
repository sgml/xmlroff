/* Fo
 * fo-table-area.c: Generate area for 'table' formatting object
 *
 * Copyright (C) 2001 Sun Microsystems
 * Copyright (C) 2007 Menteith Consulting Ltd
 *
 * See COPYING for the status of this software.
 */

#include "area/fo-area-table.h"
#include "fo-table-private.h"
#include "fo-block-fo.h"
#include "property/fo-property-inline-progression-dimension.h"

void
fo_table_area_new2 (FoFo *fo,
		    FoFoAreaNew2Context *context,
		    GError **error)
{
  FoTable *table;
  FoArea *use_parent_area;
  FoArea *new_area;
  FoDatatype *ipdim_datatype;
  gfloat available_width;
  gfloat use_width;

  g_return_if_fail (fo != NULL);
  g_return_if_fail (FO_IS_TABLE (fo));
  g_return_if_fail (context != NULL);
  g_return_if_fail (error == NULL || *error == NULL);

  table = FO_TABLE (fo);

  new_area = fo_area_table_new ();
  use_parent_area = context->parent_area;

#if defined(LIBFO_DEBUG) && 0
  g_warning ("*** table parent before new area:");
  fo_object_debug_dump (use_parent_area, 0);
  g_warning ("*** end table parent");
#endif

  FO_AREA (new_area)->generated_by = fo;
  FO_FO (fo)->areas = g_list_append (FO_FO (fo)->areas, new_area);
  fo_block_fo_update_area (fo, new_area);
  use_parent_area = fo_area_break_resolve (use_parent_area, new_area);
  fo_area_border_padding_space_resolve (use_parent_area, new_area);
  fo_area_add_child (use_parent_area, new_area);
  new_area = fo_area_size_request (new_area);

  available_width = fo_area_get_available_width (new_area);

  ipdim_datatype =
    fo_property_get_value (table->inline_progression_dimension);

  use_width = available_width;

  if (FO_IS_LENGTH_RANGE (ipdim_datatype))
    {
      FoDatatype *min_datatype = fo_length_range_get_minimum (ipdim_datatype);
      FoDatatype *opt_datatype = fo_length_range_get_optimum (ipdim_datatype);
      FoDatatype *max_datatype = fo_length_range_get_maximum (ipdim_datatype);

      if (FO_IS_LENGTH (min_datatype) &&
	  available_width < fo_length_get_value (min_datatype))
	{
	  gfloat min_width = fo_length_get_value (min_datatype);

#if defined(LIBFO_DEBUG) && 0
	  g_message ("table_area_new2:: available: %g; min: %g",
		     available_width,
		     min_width);
#endif

	  use_width = min_width;
	}
      else if (FO_IS_LENGTH (opt_datatype) &&
	  fo_length_get_value (opt_datatype) < available_width)
	{
	  gfloat opt_width = fo_length_get_value (opt_datatype);

#if defined(LIBFO_DEBUG) && 0
	  g_message ("table_area_new2:: available: %g; opt: %g",
		     available_width,
		     opt_width);
#endif

	  use_width = opt_width;
	}
      else if (FO_IS_LENGTH (max_datatype) &&
	  fo_length_get_value (max_datatype) < available_width)
	{
	  gfloat max_width = fo_length_get_value (max_datatype);

#if defined(LIBFO_DEBUG) && 0
	  g_message ("table_area_new2:: available: %g; max: %g",
		     available_width,
		     max_width);
#endif

	  use_width = max_width;
	}
    }
  else
    {
      g_assert_not_reached ();
    }

  fo_area_area_set_width (new_area, use_width);

#if defined(LIBFO_DEBUG) && 0
  g_warning ("*** table parent after new area:");
  fo_object_debug_dump (parent_area, 0);
  g_warning ("*** end table parent");
#endif

  *(context->new_area) = new_area;
}