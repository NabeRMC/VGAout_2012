/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : INT_ICF1_RGB_TXT2.cpp
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

/*  ----------------------------------------------------
    -   Text                                            -
    -----------------------------------------------------   */
void CINT::Int_ICF1_RGB_TEXT2( void )
{
	static UB Mode_Line = 0;
    static UB p_vram_line = 0;
    static UB p_vram_txt = 0;
  	static UH dsp_char = 0;
	static UH num_line = 0;
	
	Mode_Line = pgm_read_byte( &VGA_LINE_TBL[UH_hline] );
	UH_hline++;
	
	switch( Mode_Line ){
		
		case V_SYNC_END:
			P_VSYNC_ON;
			break;
		
		case V_LINE_END:
			P_VSYNC_OFF; 							/* start of timing of V-sync. pulse */
			UH_hline = 0;
        	JobAsy();
    		UH_AddrDataNow = UH_AddrDataTop;
			p_vram_txt = 0;
			num_line = 0;
			break;
		
		case CG_LINE_00:				/* 0は行間					      */
			p_vram_line = 0;            /* 1行V-RAMのポインタを先頭へ     */
			UB_Color = LineColor[num_line];
			num_line++;
			break;
		
		case CG_LINE_0:
			#include    	"CRT_ConvertOneChar_J.h"
			break;
		
		case CG_LINE_1:					/* 1は行間、ここで変換する      */
			#include    	"CRT_ConvertOneChar_J.h"
			break;
										/* 2は行間、ここで変換する      */
		case CG_LINE_2:
			#include    	"CRT_ConvertOneChar_J.h"
			break;
		
		case CG_NONE:
			break;
		
		default:						/* 行間でないのでデータの送出       */
	        OutTxt_JC( UH_AddrDataNow, Mode_Line, UB_Color );	
			PORTC = 0x00;
	}


}
	
