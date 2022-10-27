/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : CRTdef.h
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2011/10/21
*****************************************************************************/
/*----------------------------------------------------------------------------
;  Copyleft Nabe_RMC
;---------------------------------------------------------------------------*/
#ifdef      CRT_INCLUDE
#define     CRT_EXT 
#else
#define     CRT_EXT extern
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
#define CRT_TEST1  	0
#define CRT_TEST2  	1
#define CRT_NUCO1  	2
#define CRT_NUCO2  	3
#define	CRT_TEXT   	4
#define	CRT_DRAW   	5
#define	CRT_RSV	   	6
#define CRT_N      	7
#define	CRT_UP		20
#define	CRT_DOWN	21


#define RED_MN  0
#define GRN_MN  1
#define BLU_MN  2
#define RED_2B  3
#define GRN_2B  4
#define BLUE_2B 5
#define COL_6B  6
#define GSC_4B  7

#define	COL_RED		0x03		/*	Red		0000_0011B	*/
#define	COL_GRN		0x0C		/*	Green	0000_1100B	*/
#define	COL_BLU		0x30		/*	Blue	0011_0000B	*/
#define	COL_YEL		0x0F		/*	Yellow	0000_1111B	*/
#define	COL_CYA		0x3C		/*	Cyan	0011_1100B	*/
#define	COL_MAG		0x33		/*	Magenta	0011_0011B	*/
#define	COL_WHI		0x3F		/*	White	0011_1111B	*/
#define COL_BLK		0x00		/*	Black	0000_0000B	*/

#define CHGN_MODE   0


/* -------------------------------------------------------------------------
 [VGA_TEST]
 	64x64
 	
 V_SYNC_START	0
 					2	pulse width
 V_SYNC_END		2
 					68	front porch
 V_BLANK_VGA	70									0x0046
					384 (64*6) display period		0x0180
 V_END_FRM		454									0x01C6
					66	back porch
 V_END_LINE		520
 ---------------------------------------------------------------------------*/
#define	V_SYNC_START			0xA8
#define	V_SYNC_END				0xA9
#define	V_LINE_END				0xAA
#define	CG_NONE					0xAF

#define	CG_LINE_0				0xA0
#define	CG_LINE_1				0xA1
#define	CG_LINE_2				0xA2
#define	CG_LINE_00				0xA3
 
#define H_DOT_N_VGA_A           70
#define	H_NUM_FRM_VGA_A			64
#define	H_NUM_TXT_ROW			16
#define V_SYNC_START_VGA_A      0
#define V_SYNC_END_VGA_A        2
#define V_BLANK_VGA_A           ( V_SYNC_END_VGA_A + 68 )
#define H_LINE_FRM_VGA_A        ( V_BLANK_VGA_A + H_NUM_FRM_VGA_A *6 )
#define H_LINE_FRM_VGA_NUCO     ( V_BLANK_VGA_A + H_NUM_FRM_VGA_A *6 )
#define	H_LINE_TXT_END			( V_BLANK_VGA_A + H_NUM_TXT_ROW *20 )
#define H_LINE_END_VGA_A        520

#define	V_SYNC_START_DRAW		0
#define	V_SYNC_END_DRAW			2
#define	V_BLANK_DRAW			70
#define	H_LINE_FRM_DRAW			454
#define	H_LINE_END_DRAW			520

/* -------------------------------------------------------------------------
for 56.4Hz
 V_SYNC_START	0
 					2	pulse width
 V_SYNC_END		2
 					28	front porch		68-40 = 28
 V_BLANK_VGA	30									0x0046
					384 (64*6) display period		0x0180
 V_END_FRM		314									0x01C6
					26	back porch		66-40 =26
 V_END_LINE		440
 ---------------------------------------------------------------------------*/
/*==========================================================================*/
/*  RAM PUBLIC                                                              */
/*==========================================================================*/
CRT_EXT UB  UB_ModeColor;

/*==========================================================================*/
/*	C++                                                  	               */
/*==========================================================================*/
class CCRT				//CCRTはインスタンス化されていないのでは？
{
public:
    CCRT();    			//コンストラクタの宣言 名前はクラスと同じになる。
						//ここでは引数無し
    void Ini();
    void ChangeMode( UB );
	void Set_Data_sin();
	void Set_Data_1( UH, UB );
	void set_line( UB, UB );
	void set_color( UB, UB, UB );
	void clear_screen();
	
    PROGMEM static const UB TEST1_data[ 64*3 ];
    PROGMEM static const UB AyaNuco1[ 70 * 64 ];
    PROGMEM static const UB AyaNuco2[ 70 * 64 ];
	PROGMEM static const UB VGA_SIN_TBL[256];	
private:

};

