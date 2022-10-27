/*****************************************************************************
    System Name : Arduino 2010
    File Name   : CRT_ConvertOneChar.h
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

            
//            for( i = 0; i < CNV_CHAR; i++ ){    /* 2 ×3行間 = 6文字       */
                
                /* ----- 1文字 = 6byte          txtから 1文字取り出し  -----*/
//                dsp_char = 6* (vram_txt[ p_line_top +p_vram_txt ]);
				dsp_char = 6* (vram_data[ p_vram_txt ]);

                /* ----- 1文字分の変換 -------------------------------------*/
                vram_line[p_vram_line] = pgm_read_byte( &cg_code[dsp_char] );   
                p_vram_line++;
                vram_line[p_vram_line] = pgm_read_byte( &cg_code[dsp_char+1] );
                p_vram_line++;
                vram_line[p_vram_line] = pgm_read_byte( &cg_code[dsp_char+2] );
                p_vram_line++;
                vram_line[p_vram_line] = pgm_read_byte( &cg_code[dsp_char+3] );
                p_vram_line++;
                vram_line[p_vram_line] = pgm_read_byte( &cg_code[dsp_char+4] );
                p_vram_line++;                  
                vram_line[p_vram_line] = pgm_read_byte( &cg_code[dsp_char+5] );
                p_vram_line++;
                /*----------------------------------------------------------*/
                
                p_vram_txt++;   /* 次の文字へ                               */
//            }





/*----------------------------------------------------------------------------
h_line == V_BLANK
    scanline    char_row    cg_line p_vram_line p_vram_txt  mask_bit_data   
    0           0           0       ->0->30     ->0->5                      Convert1
    1           0           1       30->60      5->10                       Convert2
    2           0           2       60->90      10->15                      Convert3
    3           0           3       -           -           0x01
    4           0           4       -           -           0x02
    5           0           5       -           -           0x04
    6           0           6       -           -           0x08
    7           0           7       -           -           0x10
    8           0           8       -           -           0x20
    9           0           9       -           -           0x40

    10          1           0       ->0->30     15->20
    11          1           1       30->60      20->25
    12          1           2       60->90      25->30
    13          1           3       -           -           0x01

------------------------------------------------------------------------------*/



