/*****************************************************************************
    System Name : Arduino 2010
    File Name   : CSL_various.cpp
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
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
/*==========================================================================*/
/*  Includes                                                                */
/*==========================================================================*/
#include "SYSdef.h"
#include "CSLdef.h"
#include "INTdef.h"

/*==========================================================================*/
/*                                                                          */
/*==========================================================================*/

/*==========================================================================*/
/*  Program                                                                 */
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : CRT
* Descr    : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
CCSL::CCSL()
{
    Ini();
}

void CCSL::Ini()
{
    clear_screen();
}
    
void CCSL::clear_screen()
{
    int i;
    for( i = 0; i < COL_MAX*ROW_MAX; i++ ){
        vram_data[i] = 0x20;
    }
}


UB CCSL::set_cursor( UB x, UB y)
{
    if( (x>=8)||(y>=14) ){
        return( EOF );
    }
	else{
		cursor_x = x;
		cursor_y = y;
	}
}

UB CCSL::put_char( UB c )
{
	UB i;
	
	if( c==0x0D ){				/* 0x0D : CR	*/
		cursor_x = 0;
	}
	else if( c==0x0A ){			/* 0x0A : NL	*/
		if( cursor_y < 13 ){	/* not line end	*/
			cursor_x = 0;
			cursor_y++;
		}
		else{					/* end line		*/
			for( i=0 ; i< COL_MAX*(ROW_MAX-1) ; i++ ){
				vram_data[i] = vram_data[i+COL_MAX];
			}
		}
	}
	else{
		if( (cursor_x == (COL_MAX-1)) && (cursor_y==(ROW_MAX-1)) ){
			for( i=0; i< (COL_MAX*ROW_MAX-1); i++ ){
				vram_data[i] = vram_data[i+1];
			}
			vram_data[COL_MAX*ROW_MAX-1] = c;
		}
		else{
			vram_data[COL_MAX*cursor_y + cursor_x] = c;
			cursor_x++;
			if(cursor_x >= COL_MAX ){
				cursor_x = 0;
				cursor_y++;
				if(cursor_y >=ROW_MAX){
					cursor_y = ROW_MAX-1;
				}
			}
		}
	}

	return(c);
}

UB CCSL::put_char( UB x, UB y, UB c )
{
    if( (c > 0x97)||(x >7)||(y > 13) ){
        return( EOF );
    }
    else{
        vram_data[8*y+x] = c;
        return( 0 );
    }
}

UB CCSL::set_line_color( UB line, UB color )
{
    if( (line >13)||(color > 63) ){
        return( EOF );
    }
    else{
        LineColor[line] = color;
        return( 0 );
    }
}


void CCSL::print(const char *str)
{
	while(*str){
		put_char(*str++);
	}
}


