/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : SYSdef.h
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     : 2011/10/22
    
    base soft :z_Neo_Ard\RGB10_z1
              : z_Neo_Ard\BAP10_20100809_2\Arduino\BAP_z1
*****************************************************************************/
/*----------------------------------------------------------------------------
;  Copyleft Nabe_RMC
;---------------------------------------------------------------------------*/
#ifdef      SYS_INCLUDE
#define     SYS_EXT 
#else
#define     SYS_EXT extern
#endif

/*==========================================================================*/
/*  Includes                                                                */
/*==========================================================================*/
#ifndef     COMMON_H
#include    "Nabe_common.h"
#endif

#include    "defPort.h"
#include    "defTimer.h"

/*==========================================================================*/
/*  DEFINE                                                                  */
/*==========================================================================*/
/* ----- interrupt ---------------------------------------------------------*/
#define INI_TIMSK1  0x20    /* Timer/Counter1 Interrupt Mask Register       */
                            /* enable ICE1                      0010_0000B  */

/*==========================================================================*/
/*                                                                          */
/*==========================================================================*/
class CSYS
{
public:
	CSYS();					//コンストラクタの宣言 名前はクラスと同じになる。
							//ここでは引数無し
	UB	f_CycleEnd;
	UH	UH_PagePic;
	UB	UB_ReadByte;
	UB	UB_ReadByte_1;
	UB	UB_ReadByte_2;
	UB	UB_EepData0;
	UB	UB_EepData1;
    void Ini();
	void delay66(UB);
private:
    static void IniPort();
    static void IniTimer();
    static void IniINT();
    
};

