/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : NT_OutData_64.cpp
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2011/10/23
*****************************************************************************/
/*----------------------------------------------------------------------------
;  Copyleft Nabe_RMC
;---------------------------------------------------------------------------*/
;/*==========================================================================*/
;/* Includes                                                                */
;/*==========================================================================*/
#include "SYSdef.h"
#include "INTdef.h"

;/*==========================================================================*/
;/* Program                                                                 */
;/*==========================================================================*/
void CINT::OutData_64( UH UH_AddrGRP )
{
    __asm__ __volatile("\n\t"
        "lpm r0,z+\n\t"     //1	Load Program Memory
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //2
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //3
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //4
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //5
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //6
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //7
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //8
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //9
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //10
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //11
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //12
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //13
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //14
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //15
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //16
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //17
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //18
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //19
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //20
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //21
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //22
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //23
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //24
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //25
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //26
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //27
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //28
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //29
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //30
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //31
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //32
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //33
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //34
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //35
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //36
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //37
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //38
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //39
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //40
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //41
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //42
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //43
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //44
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //45
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //46
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //47
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //48
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //49
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //50
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //51
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //52
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //53
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //54
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //55
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //56
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //57
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //58
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //59
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //60
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //61
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //62
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //63
        // "nop\n\t"
        "out 0x08,r0\n\t"
        "lpm r0,z+\n\t"     //64
        // "nop\n\t"
        "out 0x08,r0\n\t"

        :                   // インラインアセンブラから出力する値
        : "z"(UH_AddrGRP)   // インラインアセンブラへ引き渡すCの値
        :                   // クロバーリスト
                            // コンパイラにアセンブラ内で変更が行われた
    );
}

