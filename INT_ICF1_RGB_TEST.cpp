/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : INT_ICF1.cpp
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
void CINT::Int_ICF1_RGB_TEST( void )
{
    UH_hline++;
	if( UH_hline == H_LINE_END_VGA_A ){		 /* 垂直同期パルスタイミング開始     */
        UH_hline = 0;						/* start of timing of V-sync. pulse */
		P_VSYNC_OFF; 							
        JobAsy();
    	UH_AddrDataNow = UH_AddrDataTop;
    }
    else if( UH_hline == V_SYNC_END_VGA_A ){ 	/* 垂直同期パルスタイミング終了     */
        P_VSYNC_ON;								/* end of timing of V-sync pulse    */
    }
												/* --画像表示枠内 ---         		*/
   	if( (UH_hline >= V_BLANK_VGA_A) && (UH_hline < H_LINE_FRM_VGA_A) ){
   		OutData_64( UH_AddrDataNow );
        PORTC = 0x00;   		
		if( (UH_hline) % 4 == 0 ){
		UH_AddrDataNow += 1;
		}
   	}
}


