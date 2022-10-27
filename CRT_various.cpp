/*****************************************************************************
    System Name : Simple Analog RGB 2013
    File Name   : CRT_various.cpp
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2013/02/21
*****************************************************************************/
/*==========================================================================*/
/*  Includes                                                                */
/*==========================================================================*/
#include "SYSdef.h"
#include "CRTdef.h"
#include "INTdef.h"

/*==========================================================================*/
/*  Program                                                                 */
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : 
* Descr    : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void CCRT::set_line( UB x, UB y )
{
	if( x > 200 ){
		x = 200;
	}
	if( y > VRAM_SIZE ){
		y = VRAM_SIZE;
	}
	
	vram_data[ y ] = x;
	
}

void CCRT::set_color( UB start, UB end1, UB end2 )

{
	UB_Color_DRAW0 = start;
	UB_Color_DRAW1 = end1;
	UB_Color_DRAW2 = end2;
}


void CCRT::clear_screen( )
{
	UH i;
	for( i = 0; i <= VRAM_SIZE; i++ ){
		vram_data[i] = 0xFF;
	}
	UB_Color_DRAW0 = COL_BLK;
	UB_Color_DRAW1 = COL_BLK;
	UB_Color_DRAW2 = COL_BLK;
}
