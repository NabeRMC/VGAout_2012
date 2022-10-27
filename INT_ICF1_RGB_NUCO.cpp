/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : INT_ICF1_RGB_NUCO.cpp
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2011/11/09
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
    -   VGA type Nuco	                                -
    -----------------------------------------------------   */
void CINT::Int_ICF1_RGB_NUCO( void )
{
	static UB h_CountHpixLine = 0;

    UH_hline++;
	if( UH_hline == H_LINE_END_VGA_A ){
        UH_hline = 0;
		h_CountHpixLine = 0;
    }	
	
   	if( (UH_hline >= V_BLANK_VGA_A) && (UH_hline < H_LINE_FRM_VGA_NUCO) ){
   		OutData_70( UH_AddrDataNow );
        PORTC = 0x00; 
   		h_CountHpixLine++;
   		if( h_CountHpixLine == 6 ){
   			h_CountHpixLine = 0;
   			UH_AddrDataNow += H_DOT_N_VGA_A;
   		}
//		if( (UH_hline) % 6 == 0 ){				/* 6の割り算は遅い、4,8ならOK		*/
//		UH_AddrDataNow += H_DOT_N_VGA_A; 
//		}
   	}
	
	 else if( UH_hline == V_SYNC_START_VGA_A ){ /* 垂直同期パルスタイミング開始     */
    	P_VSYNC_OFF; 							/* start of timing of V-sync. pulse */
        JobAsy();
    	UH_AddrDataNow = UH_AddrDataTop;
    }
    else if( UH_hline == V_SYNC_END_VGA_A ){ 	/* 垂直同期パルスタイミング終了     */
        P_VSYNC_ON;								/* end of timing of V-sync pulse    */
    }
												/* --画像表示枠内 ---         		*/

}

