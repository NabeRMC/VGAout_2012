/*****************************************************************************
    System Name : Arduino 2010
    File Name   : defCSL.h
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : xxx
    History     :2010/03/17
*****************************************************************************/
/*----------------------------------------------------------------------------
;  Copyright (C) 2010 Masami Watanabe
;
;  This program is free software; you can redistribute it and/or modify it
;  under the terms of the GNU General Public License as published by the Free
;  Software Foundation; either version 3 of the License, or (at your option)
;  any later version.
;
;  This program is distributed in the hope that it will be useful, but
;  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
;  for more details.
;
;  You should have received a copy of the GNU General Public License along
;  with this program. If not, see <http://www.gnu.org/licenses/>.
;---------------------------------------------------------------------------*/
#ifdef      CSL_INCLUDE
#define     CSL_EXT 
#else
#define     CSL_EXT extern
#endif

/*==========================================================================*/
/*  Includes                                                                */
/*==========================================================================*/
#ifndef     COMMON_H
#include    "nabe_common.h"
#endif

/*==========================================================================*/
/*  DEFINE                                                                  */
/*==========================================================================*/


/*==========================================================================*/
/*                                                                          */
/*==========================================================================*/
class CCSL
{
public:
    CCSL();                 /* constructor for intializing                  */
    void Ini();
    void print(const char *);
    void clear_screen();
    UB   put_char( UB, UB, UB );
	UB	 put_char( UB );
    UB   set_line_color( UB, UB );
	UB	 set_cursor( UB, UB );
private:
	UB cursor_x, cursor_y;
    int numRows;
    int numCols;
};

