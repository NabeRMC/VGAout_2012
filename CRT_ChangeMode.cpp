/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : CRT_ChangeMode.cpp
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2011/10/24
*****************************************************************************/
/*==========================================================================*/
/*  Includes                                                                */
/*==========================================================================*/
#include "SYSdef.h"
#include "CRTdef.h"
#include "INTdef.h"

/*==========================================================================*/
/*  Program                                                                 */
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : 
* Descr    : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void CCRT::ChangeMode( UB mode )
{
	static UB tmp = 0;
	unsigned short i;
    
    switch( mode ){

        case CRT_TEST1:
            UB_ModeCRT = CRT_TEST1;
            UH_AddrDataTop = (UH)(&TEST1_data);
            break;
        
  	  	case CRT_UP:
    		UB_ModeCRT = CRT_TEST2;
    		tmp = (tmp+1) & 0x3F;
    		UH_AddrDataTop = ((UH)(&TEST1_data) +tmp);
    		break;
 
//  	  	case CRT_DOWN:
//    		UB_ModeCRT = CRT_TEST2;
//    		tmp = (tmp-1) & 0x3F;
//    		UH_AddrDataTop = ((UH)(&TEST1_data) +tmp);
//    		break;
    	
         case CRT_NUCO1:
            UB_ModeCRT = CRT_NUCO1;
            UH_AddrDataTop = (UH)(&AyaNuco1);
            break;
    	
         case CRT_NUCO2:
            UB_ModeCRT = CRT_NUCO1;
            UH_AddrDataTop = (UH)(&AyaNuco2);
            break;
    	
    	 case CRT_TEXT:
            UB_ModeCRT = CRT_TEXT;
    		UH_AddrDataTop = (UH)(&vram_line);
    		for( i = 0; i < VRAM_SIZE; i++ ){
    			vram_data[i] = 0x20;
    		}
            break;
    	
    	 case CRT_DRAW:
    		UB_ModeCRT = CRT_DRAW;
			UB_Color_DRAW0  = COL_BLK;
			UB_Color_DRAW1  = COL_BLK;
			UB_Color_DRAW2	= COL_BLK;
    		for( i = 0; i < VRAM_SIZE; i++ ){
    			vram_data[i] = 0xFF;
    		}
    		break;
    	
        default:
            UB_ModeCRT = CRT_TEST1;
            UH_AddrDataTop = (UH)(&TEST1_data);
    }

}

