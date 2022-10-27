/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : CRT_ChangeMode.cpp
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2011/10/24
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
void CCRT::Set_Data_sin( void )
{
	UH i;
	UB j;
	
	i=0;
	
	for( i = 0; i < VRAM_SIZE; i++ ){
	 	vram_data[i] = pgm_read_byte( &VGA_SIN_TBL[ j ] );
		j++;
	}
	
}


void CCRT::Set_Data_1( UH indexRAM, UB indexROM )
{
	vram_data[indexRAM] = pgm_read_byte( &VGA_SIN_TBL[indexROM] );
}

