/* Copyright (C) 1999 Aladdin Enterprises.  All rights reserved.
  
  This file is part of AFPL Ghostscript.
  
  AFPL Ghostscript is distributed with NO WARRANTY OF ANY KIND.  No author or
  distributor accepts any responsibility for the consequences of using it, or
  for whether it serves any particular purpose or works at all, unless he or
  she says so in writing.  Refer to the Aladdin Free Public License (the
  "License") for full details.
  
  Every copy of AFPL Ghostscript must include a copy of the License, normally
  in a plain ASCII text file named PUBLIC.  The License grants you the right
  to copy, modify and redistribute AFPL Ghostscript, but only under certain
  conditions described in the License.  Among other things, the License
  requires that the copyright notice and this notice be preserved on all
  copies.
*/

/*$Id: gxdhtres.h,v 1.2 2000/09/19 19:00:36 lpd Exp $ */
/* Definitions for precompiled halftone resources */

#ifndef gxdhtres_INCLUDED
#  define gxdhtres_INCLUDED

#include "stdpre.h"

/*
 * Precompiled halftones generated by genht #include this file.
 */
#ifndef gx_device_halftone_resource_DEFINED
#  define gx_device_halftone_resource_DEFINED
typedef struct gx_device_halftone_resource_s gx_device_halftone_resource_t;
#endif

struct gx_device_halftone_resource_s {
    const char *rname;
    int HalftoneType;
    int Width;
    int Height;
    int num_levels;
    const unsigned int *levels;
    const void *bit_data;
    int elt_size;
};

#define DEVICE_HALFTONE_RESOURCE_PROC(proc)\
  const gx_device_halftone_resource_t *const *proc(P0())

#endif /* gxdhtres_INCLUDED */
