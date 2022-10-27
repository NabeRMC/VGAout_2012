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
/*  ----------------------------------------------------
    -   function pointer                                -
    -----------------------------------------------------   */
void ( CINT::*TBL_int_icf1[] )(void) = {
    &CINT::Int_ICF1_RGB_TEST,		/*  0									*/
    &CINT::Int_ICF1_RGB_TEST,		/*  1									*/
    &CINT::Int_ICF1_RGB_NUCO,		/*  2									*/
    &CINT::Int_ICF1_RGB_NUCO,		/*  3									*/
	&CINT::Int_ICF1_RGB_TEXT2,		/*  4									*/
	&CINT::Int_ICF1_RGB_DRAW,		/*  5									*/	
    &CINT::Int_ICF1_Reserve,    	/*  6       							*/
};

void CINT::ExecFunc( UB nIndex )
{
    (this->*TBL_int_icf1[nIndex])();
	
};

/*----------------------------------------------------------------------------
* Function : interrupt ICF1
* Descr    : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
CINT    clsINT;

ISR (TIMER1_CAPT_vect)
{
    clsINT.FitDelay( TCNT1L );      /* 割り込み遅延ばらつきの合わせ込み     */
                    /* Compensation of the variration in delay of interrupt */
    clsINT.ExecFunc( UB_ModeCRT );

}


/*  ----------------------------------------------------
    -   Reserve                                            -
    -----------------------------------------------------   */
void CINT::Int_ICF1_Reserve( void )
{

}


/*  ----------------------------------------------------
    -                                                   -
    -----------------------------------------------------   */
void CINT::JobAsy()
{
   	static UB   UBCT_16_5ms = 0;
    
	UBCT_16_5ms++;
	
   	if( ( UBCT_16_5ms %4 ) == 0 ){      	/* --- job66ms ---             */
        f_SYS_66ms_req = 1;
    }
	
    if( ( UBCT_16_5ms %64 ) == 0 ){       	/* --- job1056ms ---             */
        f_SYS_1056ms_req = 1;
    }

}


