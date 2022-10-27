/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : INTdef.h
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2011/10/23
*****************************************************************************/
/*----------------------------------------------------------------------------
;  Copyleft Nabe_RMC
;---------------------------------------------------------------------------*/
#ifdef      INT_INCLUDE
#define     INT_EXT 
#else
#define     INT_EXT extern
#endif

/*==========================================================================*/
/*  Includes                                                                */
/*==========================================================================*/
#ifndef     COMMON_H
#include    "nabe_common.h"
#endif

/*==========================================================================*/
/*  DEFINE                                                                  */
/*==========================================================================*/
#define COL_MAX     8               /* 1行あたりの文字数                    */
#define ROW_MAX     14              /* 表示行数                             */
#define	DRAW_BLACK	0x00
#define	DRAW_WHITE	0x3F
#define	DRAW_RED	0x03
#define	DRAW_GREEN	0x0C
#define	DRAW_BLUE	0x30
#define	DRAW_YELLOW	0x0F
#define	VRAM_SIZE	384

/*==========================================================================*/
/*                                                                          */
/*==========================================================================*/
//INT_EXT UB   vram_txt[ COL_MAX * ROW_MAX ];   /* 6column * 8char row        */
INT_EXT	UB	vram_data[VRAM_SIZE];
INT_EXT UB   vram_line[ 6 * COL_MAX ];
INT_EXT	UB   LineColor[ 14 ];

INT_EXT UH UH_AddrDataTop;
INT_EXT UB UB_ModeCRT;
INT_EXT UB f_CRT;
INT_EXT UB f_req_data_trans;
INT_EXT	UB f_TrgChangeColor1;
INT_EXT	UB f_TrgChangeColor2;
INT_EXT	UB f_TrgChangeColor3;
INT_EXT UB f_disp_on;
//INT_EXT UB f_SYS_66ms_req;
//INT_EXT UB f_SYS_132ms_req;
//INT_EXT UB f_SYS_528ms_req;
//INT_EXT	UB f_SYS_1056ms_req;
//INT_EXT UB f_SYS_1sec_req;
INT_EXT	UB UB_Color;

INT_EXT	volatile UB UB_Color_DRAW0;
INT_EXT	volatile UB UB_Color_DRAW1;
INT_EXT	volatile UB UB_Color_DRAW2;


class CINT
{
public:
    CINT();                         /* constructor for initializing         */
    
    void Ini();
    void JobAsy();
    void ExecFunc(UB);
	UB	Check66ms();
	UB	Check1056ms();

    void Int_ICF1_RGB_TEST();
    void Int_ICF1_RGB_NUCO();
	void Int_ICF1_RGB_TEXT1();
	void Int_ICF1_RGB_TEXT2();
	void Int_ICF1_RGB_DRAW();
    void Int_ICF1_Reserve();
    void FitDelay( UB );
	
	void OutData_64( UH );
	void OutData_70( UH );
    void OutTxt_JC( UH, UB, UB );
	void OutTxtRGB_1( UH, UB, UB );	/* 96画素								*/
	void OutTxtRGB_2( UH, UB, UB );	/* 96画素	PortData自動インクリメント	*/
	void OutTxtCRT_1( UH, UB, UB );
	void OutDelay( UH );
	void OutDraw( UB, UB, UB );
	
    UH  UH_AddrDataNow;

	PROGMEM static const UB cg_code[ (0x97 - 0x00 +1)*6 ];  
    PROGMEM static const UB MASK_bit[ 11 ];
	PROGMEM static const UB CHAR_ROW[10*10];
	PROGMEM static const UB CG_LINE[10*10];
	PROGMEM static const UB VGA_LINE_TBL[520];
	
	
private:
    UH  UH_TCNT1;
    UH  UH_hline;
    UB  UB_scanline;            /* 0 - 9    水平走査ライン  文字行数×10    */
    UB  UB_char_row;            /* 0 - 9    文字行          10行            */
    UB  UB_cg_line;             /* 0 - 9    キャラジェネ選択ライン          */
	static UB f_SYS_66ms_req;
	static UB f_SYS_1056ms_req;

};


