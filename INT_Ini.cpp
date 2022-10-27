/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : INT_Ini.cpp
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
#define INT_INCLUDE
#include "SYSdef.h"
#include "INTdef.h"
#include "CRTdef.h"

/*==========================================================================*/
/*                                                                          */
/*==========================================================================*/
PROGMEM const UB CINT::cg_code[ (0x97 - 0x00 +1)*6 ] = { 
#include "CG_20130212.h"
};

PROGMEM const UB CINT::VGA_LINE_TBL[ 520 ] = { 
#include "VGA_LINE_TBL.h"
};

PROGMEM const UB CINT::MASK_bit[ 11 ] = { 
    0, 0, 0, 0x01, 0x02, 0x04, 0x8, 0x10, 0x20, 0x40, 0x00
};


//	:: 2つのセミコロンは「有効範囲解決演算子」という
/*==========================================================================*/
/*  Program                                                                 */
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : interrupt コントロール処理関連の初期化
* Descr    : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
CINT::CINT()
{
    Ini();
}

UB CINT::f_SYS_1056ms_req = 0;
UB CINT::f_SYS_66ms_req = 0;

void CINT::Ini( void )
{
    UB_ModeCRT = 0;
	UB_Color = 0x3F;
	LineColor[0] = 0x03;
	LineColor[1] = 0x0C;
	LineColor[2] = 0x0F;
	LineColor[3] = 0x30;
	LineColor[4] = 0x3C;
	LineColor[5] = 0x33;
	LineColor[6] = 0x3F;
	LineColor[7] = 0x13;
	LineColor[8] = 0x1C;
	LineColor[9] = 0x31;
	LineColor[10] = 0x23;
	LineColor[11] = 0x2C;
	LineColor[12] = 0x32;
	LineColor[13] = 0x28;
	
	UH_TCNT1 = 0;
    UH_hline = 0;
  	UB_scanline = 0;
   	UB_char_row = 0;
    UB_cg_line = 0;
	f_SYS_66ms_req = 0;
	f_SYS_1056ms_req = 0;
	UH_AddrDataNow = 0;
}


UB	CINT::Check1056ms()	
{
	if( f_SYS_1056ms_req ==0 ){
		return( 0 );
	}
	else{
		f_SYS_1056ms_req =0;
		return( 1 );
	}
}

UB	CINT::Check66ms()	
{
	if( f_SYS_66ms_req ==0 ){
		return( 0 );
	}
	else{
		f_SYS_66ms_req =0;
		return( 1 );
	}
}
