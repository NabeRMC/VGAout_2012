/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : NT_OutDelay.cpp
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2011/11/19
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
;/* Program                                                                  */
;/*==========================================================================*/
//	ZH :R31
//	ZL :R30
void CINT::OutDelay( UH UH_Delay )
{
	__asm__ __volatile("\n"
		"addr_top = . +14\n\t"
		"ldi r24,lo8(addr_top)\n\t"	//	2byte	1cycle
		"ldi r25,hi8(addr_top)\n\t"	//	2byte	1cycle
		"lsr r24\n\t"				//  2byte	1cycle
		"ror r25\n\t"				//	2byte	1cycle
		"add r30,r24\n\t"			//	2byte	1cycle
		"adc r31,r25\n\t"			//	2byte	1cycle
		"ijmp\n\t"					//	2byte	2cycle
		
		"nop\n\t"				//0
		"nop\n\t"				//1
		"nop\n\t"				//2
		"nop\n\t"				//3
		"nop\n\t"				//4
		"nop\n\t"				//5
		"nop\n\t"				//6
		"nop\n\t"				//7
		"nop\n\t"				//8
		"nop\n\t"				//9
		"nop\n\t"				//10
		"nop\n\t"				//11
		"nop\n\t"				//12
		"nop\n\t"				//13
		"nop\n\t"				//14
		"nop\n\t"				//15
		"nop\n\t"				//16
		"nop\n\t"				//17
		"nop\n\t"				//18
		"nop\n\t"				//19
		"nop\n\t"				//20
		"nop\n\t"				//21
		"nop\n\t"				//22
		"nop\n\t"				//23
		"nop\n\t"				//24
		"nop\n\t"				//25
		"nop\n\t"				//26
		"nop\n\t"				//27
		"nop\n\t"				//28
		"nop\n\t"				//29
		"nop\n\t"				//30
		"nop\n\t"				//31
		"nop\n\t"				//32
		"nop\n\t"				//33
		"nop\n\t"				//34
		"nop\n\t"				//35
		"nop\n\t"				//36
		"nop\n\t"				//37
		"nop\n\t"				//38
		"nop\n\t"				//39
		"nop\n\t"				//40
		"nop\n\t"				//41
		"nop\n\t"				//42
		"nop\n\t"				//43
		"nop\n\t"				//44
		"nop\n\t"				//45
		"nop\n\t"				//46
		"nop\n\t"				//47
		"nop\n\t"				//48
		"nop\n\t"				//49
		"nop\n\t"				//50
		"nop\n\t"				//51
		"nop\n\t"				//52
		"nop\n\t"				//53
		"nop\n\t"				//54
		"nop\n\t"				//55
		"nop\n\t"				//56
		"nop\n\t"				//57
		"nop\n\t"				//58
		"nop\n\t"				//59
		"nop\n\t"				//60
		"nop\n\t"				//61
		"nop\n\t"				//62
		"nop\n\t"				//63
		"nop\n\t"				//64
		"nop\n\t"				//65
		"nop\n\t"				//66
		"nop\n\t"				//67
		"nop\n\t"				//68
		"nop\n\t"				//69
		"nop\n\t"				//70
		"nop\n\t"				//71
		"nop\n\t"				//72
		"nop\n\t"				//73
		"nop\n\t"				//74
		"nop\n\t"				//75
		"nop\n\t"				//76
		"nop\n\t"				//77
		"nop\n\t"				//78
		"nop\n\t"				//79
		"nop\n\t"				//80
		"nop\n\t"				//81
		"nop\n\t"				//82
		"nop\n\t"				//83
		"nop\n\t"				//84
		"nop\n\t"				//85
		"nop\n\t"				//86
		"nop\n\t"				//87
		"nop\n\t"				//88
		"nop\n\t"				//89
		"nop\n\t"				//90
		"nop\n\t"				//91
		"nop\n\t"				//92
		"nop\n\t"				//93
		"nop\n\t"				//94
		"nop\n\t"				//95
		"nop\n\t"				//96
		"nop\n\t"				//97
		"nop\n\t"				//98
		"nop\n\t"				//99

		"nop\n\t"				//0	/100
		"nop\n\t"				//1
		"nop\n\t"				//2
		"nop\n\t"				//3
		"nop\n\t"				//4
		"nop\n\t"				//5
		"nop\n\t"				//6
		"nop\n\t"				//7
		"nop\n\t"				//8
		"nop\n\t"				//9
		"nop\n\t"				//10
		"nop\n\t"				//11
		"nop\n\t"				//12
		"nop\n\t"				//13
		"nop\n\t"				//14
		"nop\n\t"				//15
		"nop\n\t"				//16
		"nop\n\t"				//17
		"nop\n\t"				//18
		"nop\n\t"				//19
		"nop\n\t"				//20
		"nop\n\t"				//21
		"nop\n\t"				//22
		"nop\n\t"				//23
		"nop\n\t"				//24
		"nop\n\t"				//25
		"nop\n\t"				//26
		"nop\n\t"				//27
		"nop\n\t"				//28
		"nop\n\t"				//29
		"nop\n\t"				//30
		"nop\n\t"				//31
		"nop\n\t"				//32
		"nop\n\t"				//33
		"nop\n\t"				//34
		"nop\n\t"				//35
		"nop\n\t"				//36
		"nop\n\t"				//37
		"nop\n\t"				//38
		"nop\n\t"				//39
		"nop\n\t"				//40
		"nop\n\t"				//41
		"nop\n\t"				//42
		"nop\n\t"				//43
		"nop\n\t"				//44
		"nop\n\t"				//45
		"nop\n\t"				//46
		"nop\n\t"				//47
		"nop\n\t"				//48
		"nop\n\t"				//49
		"nop\n\t"				//50
		"nop\n\t"				//51
		"nop\n\t"				//52
		"nop\n\t"				//53
		"nop\n\t"				//54
		"nop\n\t"				//55
		"nop\n\t"				//56
		"nop\n\t"				//57
		"nop\n\t"				//58
		"nop\n\t"				//59
		"nop\n\t"				//60
		"nop\n\t"				//61
		"nop\n\t"				//62
		"nop\n\t"				//63
		"nop\n\t"				//64
		"nop\n\t"				//65
		"nop\n\t"				//66
		"nop\n\t"				//67
		"nop\n\t"				//68
		"nop\n\t"				//69
		"nop\n\t"				//70
		"nop\n\t"				//71
		"nop\n\t"				//72
		"nop\n\t"				//73
		"nop\n\t"				//74
		"nop\n\t"				//75
		"nop\n\t"				//76
		"nop\n\t"				//77
		"nop\n\t"				//78
		"nop\n\t"				//79
		"nop\n\t"				//80
		"nop\n\t"				//81
		"nop\n\t"				//82
		"nop\n\t"				//83
		"nop\n\t"				//84
		"nop\n\t"				//85
		"nop\n\t"				//86
		"nop\n\t"				//87
		"nop\n\t"				//88
		"nop\n\t"				//89
		"nop\n\t"				//90
		"nop\n\t"				//91
		"nop\n\t"				//92
		"nop\n\t"				//93
		"nop\n\t"				//94
		"nop\n\t"				//95
		"nop\n\t"				//96
		"nop\n\t"				//97
		"nop\n\t"				//98
		"nop\n\t"				//99

		:
		: "z"(UH_Delay)
		:
	);

}



