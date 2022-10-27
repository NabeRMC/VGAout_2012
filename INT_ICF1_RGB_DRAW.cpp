/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : Int_ICF1_RGB_DRAW.cpp
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2011/10/23
*****************************************************************************/
/*----------------------------------------------------------------------------
;  Copyleft Nabe_RMC
;---------------------------------------------------------------------------*/
/*==========================================================================*/
/*  Includes                                                                */
/*==========================================================================*/
#include "SYSdef.h"
#include "INTdef.h"
#include "CRTdef.h"

/*==========================================================================*/
/*  Program                                                                 */
/*==========================================================================*/
/*  -----------------------------------------------------
    -   VGA type TEST	                                -
    -----------------------------------------------------   */
void CINT::Int_ICF1_RGB_DRAW( void )
{
	static UH Position_x = 0;
	static UB delay = 0;	
	
    UH_hline++;
	
   	if( (UH_hline >= V_BLANK_DRAW) && (UH_hline < H_LINE_FRM_DRAW) ){
 		delay = vram_data[Position_x];
   		if( delay != 0xFF ){
   			PORTC = UB_Color_DRAW0;
			OutDraw( delay, UB_Color_DRAW1, UB_Color_DRAW2 );
			PORTC = 0;
   		}
		Position_x++;
   	}
	
	else if( UH_hline >= H_LINE_END_DRAW ){		 /* 垂直同期パルスタイミング開始     */
        UH_hline = 0;						/* start of timing of V-sync. pulse */
		P_VSYNC_OFF;
        JobAsy();
		Position_x = 0;
    }
    else if( UH_hline == V_SYNC_END_DRAW ){ 	/* 垂直同期パルスタイミング終了     */
        P_VSYNC_ON;								/* end of timing of V-sync pulse    */
    }
												/* --画像表示枠内 ---         		*/

}


