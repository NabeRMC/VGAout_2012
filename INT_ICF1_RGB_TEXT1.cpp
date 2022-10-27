/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : INT_ICF1_RGB_TXT1.cpp
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
void CINT::Int_ICF1_RGB_TEXT1( void )
{
    static UB p_vram_line = 0;
    static UB p_vram_txt = 0;
    static UH p_line_top;
    static UH dsp_char = 0;
    static UB isMabiki = 0;
           UB i;
           UB mask_bit_data;

    UH_hline++;
	if( UH_hline == H_LINE_END_VGA_A ){
		UH_hline = 0;
		UB_scanline = 0;                        /* 文字走査カウンタリセット */
        p_vram_txt = 0;                         /* text data read point     */
		UB_Color = 0x03;
		
	}
	
   	if( (UH_hline >= V_BLANK_VGA_A) && (UH_hline < H_LINE_TXT_END) ){	
	
                                        /* --- テキスト表示枠内 ---         */
//    	if( UB_scanline < ( 8*10 ) ){       /* 8文字行 × 10本                 */
        
        	UB_char_row = UB_scanline/20;   /* 20ラインで1文字行                */
			UB_cg_line = (UB_scanline % 20)/2;  /* 0 -19  line                       */
                                        /* 0,1,2は行間、ここで変換する      */
        	if( UB_cg_line == 0 ){          /* ひとつめの行間                   */
            	p_vram_line = 0;            /* 1行V-RAMのポインタを先頭へ       */
            	p_line_top = (UH)UB_char_row * (UH)COL_MAX;
            	p_vram_txt = 0;
        		UB_Color += 0x02A;
        	}

        	else if( UB_cg_line == 1 ){     /* ふたつめの行間                   */
#include    	"CRT_ConvertOneChar_J.h"
        	}
        	else if( UB_cg_line == 2 ){     /* みっつめの行間                   */
#include    	"CRT_ConvertOneChar_J.h"
        	}

        	else{                           /* 行間でないのでデータの送出       */
            	mask_bit_data = pgm_read_byte( &MASK_bit[UB_cg_line] ); /*速度変わらない	*/
//            	mask_bit_data = MASK_bit_TBL[UB_cg_line]; 
//          	dbg_mask_bit_data =0xFF;
            	OutTxt_JC( UH_AddrDataNow, mask_bit_data, UB_Color );
        	}                       
        	PORTC = 0x00;	//PORTC = 0x00;
//    	}
   		UB_scanline++;  
   	}
	 else if( UH_hline == V_SYNC_START_VGA_A ){ /* 垂直同期パルスタイミング開始     */
    	P_VSYNC_OFF; 							/* start of timing of V-sync. pulse */
        JobAsy();
    	UH_AddrDataNow = UH_AddrDataTop;
    }
    else if( UH_hline == V_SYNC_END_VGA_A ){ 	/* 垂直同期パルスタイミング終了     */
        P_VSYNC_ON;								/* end of timing of V-sync pulse    */
    }
	

}

