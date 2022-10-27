;/*****************************************************************************
;   System Name : Arduino 2010
;   File Name   : INT_OutTxt.cpp
;   Content     : 
;   Version     : 0.0
;   CPU board   : Arduino Duemilanove
;   Compiler    : 
;   History     :2010/03/17
;*****************************************************************************/
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
;/*==========================================================================*/
;/* Includes                                                                */
;/*==========================================================================*/
#include "SYSdef.h"
#include "INTdef.h"

;/*==========================================================================*/
;/* Program                                                                 */
;/*==========================================================================*/
;/*----------------------------------------------------------------------------
;* Function : 
;* Descr       : 
;* Inputs   : 
;* Outputs  : 
;* Return   : 
;*---------------------------------------------------------------------------*/

void CINT::OutTxt_JC( UH AddrGRP, UB MaskData, UB Color )
{
    __asm__ __volatile("\n\t"
    
//        "ldi    r21,0x0F\n\t"   //outdata = 0FH
        "mov r21,%2\n\t"
    	
        "ld     r0,x+\n\t"      //1		-1
        "and    r0,%1\n\t"
        "breq   1f\n\t"
        "mov    r0,r21\n\t"
        "1:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //2
        "and    r0,%1\n\t"
        "breq   2f\n\t"
        "mov    r0,r21\n\t"
        "2:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //3
        "and    r0,%1\n\t"
        "breq   3f\n\t"
        "mov    r0,r21\n\t"
        "3:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //4
        "and    r0,%1\n\t"
        "breq   4f\n\t"
        "mov    r0,r21\n\t"
        "4:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //5
        "and    r0,%1\n\t"
        "breq   5f\n\t"
        "mov    r0,r21\n\t"
        "5:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //6
        "and    r0,%1\n\t"
        "breq   6f\n\t"
        "mov    r0,r21\n\t"
        "6:\n\t"
        "out    0x08,r0\n\t"

        "ld     r0,x+\n\t"      //7		-2
        "and    r0,%1\n\t"
        "breq   7f\n\t"
        "mov    r0,r21\n\t"
        "7:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //8
        "and    r0,%1\n\t"
        "breq   8f\n\t"
        "mov    r0,r21\n\t"
        "8:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //9
        "and    r0,%1\n\t"
        "breq   9f\n\t"
        "mov    r0,r21\n\t"
        "9:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //10
        "and    r0,%1\n\t"
        "breq   10f\n\t"
        "mov    r0,r21\n\t"
        "10:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //11
        "and    r0,%1\n\t"
        "breq   11f\n\t"
        "mov    r0,r21\n\t"
        "11:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //12
        "and    r0,%1\n\t"
        "breq   12f\n\t"
        "mov    r0,r21\n\t"
        "12:\n\t"
        "out    0x08,r0\n\t"
    	
         "ld     r0,x+\n\t"      //13	-3
        "and    r0,%1\n\t"
        "breq   13f\n\t"
        "mov    r0,r21\n\t"
        "13:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //14
        "and    r0,%1\n\t"
        "breq   14f\n\t"
        "mov    r0,r21\n\t"
        "14:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //15
        "and    r0,%1\n\t"
        "breq   15f\n\t"
        "mov    r0,r21\n\t"
        "15:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //16
        "and    r0,%1\n\t"
        "breq   16f\n\t"
        "mov    r0,r21\n\t"
        "16:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //17
        "and    r0,%1\n\t"
        "breq   17f\n\t"
        "mov    r0,r21\n\t"
        "17:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //18
        "and    r0,%1\n\t"
        "breq   18f\n\t"
        "mov    r0,r21\n\t"
        "18:\n\t"
        "out    0x08,r0\n\t"   	
    	
        "ld     r0,x+\n\t"      //19	-4
        "and    r0,%1\n\t"
        "breq   19f\n\t"
        "mov    r0,r21\n\t"
        "19:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //20
        "and    r0,%1\n\t"
        "breq   20f\n\t"
        "mov    r0,r21\n\t"
        "20:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //21
        "and    r0,%1\n\t"
        "breq   21f\n\t"
        "mov    r0,r21\n\t"
        "21:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //22
        "and    r0,%1\n\t"
        "breq   22f\n\t"
        "mov    r0,r21\n\t"
        "22:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //23
        "and    r0,%1\n\t"
        "breq   23f\n\t"
        "mov    r0,r21\n\t"
        "23:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //24
        "and    r0,%1\n\t"
        "breq   24f\n\t"
        "mov    r0,r21\n\t"
        "24:\n\t"
        "out    0x08,r0\n\t"    	
    	
        "ld     r0,x+\n\t"      //25	-5
        "and    r0,%1\n\t"
        "breq   25f\n\t"
        "mov    r0,r21\n\t"
        "25:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //26
        "and    r0,%1\n\t"
        "breq   26f\n\t"
        "mov    r0,r21\n\t"
        "26:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //27
        "and    r0,%1\n\t"
        "breq   27f\n\t"
        "mov    r0,r21\n\t"
        "27:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //28
        "and    r0,%1\n\t"
        "breq   28f\n\t"
        "mov    r0,r21\n\t"
        "28:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //29
        "and    r0,%1\n\t"
        "breq   29f\n\t"
        "mov    r0,r21\n\t"
        "29:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //30
        "and    r0,%1\n\t"
        "breq   30f\n\t"
        "mov    r0,r21\n\t"
        "30:\n\t"
        "out    0x08,r0\n\t"    	
    	
        "ld     r0,x+\n\t"      //31	-6
        "and    r0,%1\n\t"
        "breq   31f\n\t"
        "mov    r0,r21\n\t"
        "31:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //32
        "and    r0,%1\n\t"
        "breq   32f\n\t"
        "mov    r0,r21\n\t"
        "32:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //33
        "and    r0,%1\n\t"
        "breq   33f\n\t"
        "mov    r0,r21\n\t"
        "33:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //34
        "and    r0,%1\n\t"
        "breq   34f\n\t"
        "mov    r0,r21\n\t"
        "34:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //35
        "and    r0,%1\n\t"
        "breq   35f\n\t"
        "mov    r0,r21\n\t"
        "35:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //36
        "and    r0,%1\n\t"
        "breq   36f\n\t"
        "mov    r0,r21\n\t"
        "36:\n\t"
        "out    0x08,r0\n\t"
    	

        "ld     r0,x+\n\t"      //37	-7
        "and    r0,%1\n\t"
        "breq   37f\n\t"
        "mov    r0,r21\n\t"
        "37:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //38
        "and    r0,%1\n\t"
        "breq   38f\n\t"
        "mov    r0,r21\n\t"
        "38:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //39
        "and    r0,%1\n\t"
        "breq   39f\n\t"
        "mov    r0,r21\n\t"
        "39:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //40
        "and    r0,%1\n\t"
        "breq   40f\n\t"
        "mov    r0,r21\n\t"
        "40:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //41
        "and    r0,%1\n\t"
        "breq   41f\n\t"
        "mov    r0,r21\n\t"
        "41:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //42
        "and    r0,%1\n\t"
        "breq   42f\n\t"
        "mov    r0,r21\n\t"
        "42:\n\t"
        "out    0x08,r0\n\t"

        "ld     r0,x+\n\t"      //43	-8
        "and    r0,%1\n\t"
        "breq   43f\n\t"
        "mov    r0,r21\n\t"
        "43:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //44
        "and    r0,%1\n\t"
        "breq   44f\n\t"
        "mov    r0,r21\n\t"
        "44:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //45
        "and    r0,%1\n\t"
        "breq   45f\n\t"
        "mov    r0,r21\n\t"
        "45:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //46
        "and    r0,%1\n\t"
        "breq   46f\n\t"
        "mov    r0,r21\n\t"
        "46:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //47
        "and    r0,%1\n\t"
        "breq   47f\n\t"
        "mov    r0,r21\n\t"
        "47:\n\t"
        "out    0x08,r0\n\t"
        "ld     r0,x+\n\t"      //48
        "and    r0,%1\n\t"
        "breq   48f\n\t"
        "mov    r0,r21\n\t"
        "48:\n\t"
        "out    0x08,r0\n\t"    	
    	
    	

        :
        : "x"(AddrGRP) ,"r"(MaskData) ,"r"(Color)
        :
 
    );
}



