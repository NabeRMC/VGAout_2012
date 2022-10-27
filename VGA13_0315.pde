/*****************************************************************************
    System Name : Simple Analog RGB 2013
    File Name   : VGA13_0216.pde
    Content     : 
    Version     : 0.0
    CPU board   : Arduino Duemilanove
    Compiler    : 
    History     :2013/02/16
*****************************************************************************/
/*----------------------------------------------------------------------------
;  Copyleft Nabe_RMC
;---------------------------------------------------------------------------*/

/*==========================================================================*/
/*  Includes                                                                */
/*==========================================================================*/
#include "SYSdef.h"
#include "CRTdef.h"
#include "INTdef.h"
#include "CSLdef.h"

/*==========================================================================*/
/*  DEFINE                                                                  */
/*==========================================================================*/
/*--- blink LED ------------------------------------------------------------*/
#define BLK_LED_CYC_NOM     0x80

/*==========================================================================*/
/*  Program                                                                 */
/*==========================================================================*/
CSYS objSYS;
CCRT objCRT;
CCSL objCSL;
CINT objINT;

const float pi = 3.14;
const float delta = (2*pi)/VRAM_SIZE;

void setup()
{
    objSYS.Ini();               /* re-initialize after Arduini IDE init()   */
    randomSeed(analogRead(0));
    sei();                      /* interrupt enable                         */
}

void loop()
{
	unsigned char ColorData[7] ={	COL_RED, COL_GRN, COL_BLU, COL_YEL,
									COL_CYA, COL_MAG, COL_WHI };
	
	unsigned char	ColorStart	= COL_BLK;
	unsigned char	ColorEnd1 	= COL_BLK;
	unsigned char	ColorEnd2 	= COL_BLK;
	unsigned short	LineStart;
	unsigned short	LineEnd;
	unsigned short	Position;
	unsigned char 	Data;
	float angle;
	unsigned short i,j;

	objCRT.ChangeMode( CRT_TEXT );
    objCSL.put_char( 0, 0, 'A' );   objSYS.delay66( 5 );
    objCSL.put_char( 1, 0, 'r' );   objSYS.delay66( 5 );
    objCSL.put_char( 2, 0, 'd' );   objSYS.delay66( 5 );
    objCSL.put_char( 3, 0, 'u' );   objSYS.delay66( 5 );
    objCSL.put_char( 4, 0, 'i' );   objSYS.delay66( 5 );
    objCSL.put_char( 5, 0, 'n' );   objSYS.delay66( 5 );
    objCSL.put_char( 6, 0, 'o' );   objSYS.delay66( 10 );
	
	Data = 0x80;
	while( Data <= 0x8B ){
		for( i = 0; i < 5; i++ ){
			objCSL.put_char( 0, 0, Data );	objCSL.put_char( 1, 0, Data+1 );
			objSYS.delay66( 5 );
			objCSL.put_char( 0, 0, Data+2 );	objCSL.put_char( 1, 0, Data+3 );
			objSYS.delay66( 5 );
			objCSL.set_line_color( 0, ColorData[i] );
		}
		Data +=4;
	}
	
	objCSL.set_cursor( 0, 1 );
	objCSL.print("2013\n");			objSYS.delay66( 10 );
	objCSL.print("Nabe_RMC\n");		objSYS.delay66( 10 );	
	
	objCRT.ChangeMode( CRT_DRAW );
	
	for( Position = 0; Position < VRAM_SIZE; Position++ ){	/* vertical line thin	*/
		for( i = 0; i < Position; i++ ){
			if( Position < 200 ){
				vram_data[i] = (unsigned char)Position;
			}
			else{
				vram_data[i] = (400 - Position);
			}
		}
		objSYS.delay66( 1 );
		ColorEnd1 = ColorData[((Position/8) & 0x07)];
		objCRT.set_color( COL_BLK, ColorEnd1, COL_BLK );
	}

	objCRT.clear_screen();
	for( Position = 0; Position < 200; Position++ ){	/* vertical line thick	*/
		for( i = 0; i < Position; i++ ){
			vram_data[i] = Position;
		}
		objSYS.delay66( 1 );
		ColorEnd1 = ColorData[((Position/8) & 0x07)];
		ColorEnd2 = ColorData[((Position+1)/8) & 0x07];
		objCRT.set_color( COL_BLK, ColorEnd1,ColorEnd2 );
	}
	
	objCRT.clear_screen();	
	for( Position = 1; Position < VRAM_SIZE; Position++ ){	/* horizontal line	*/
		ColorStart = ColorData[((Position/8) & 0x07)];
		objCRT.set_color( ColorStart, COL_BLK,COL_BLK );
		vram_data[Position-1] = 0xFF;
		vram_data[Position] = (unsigned char)Position;
		objSYS.delay66( 1 );
	}
	
	objCRT.clear_screen();
	angle = 0;
	for( i = 0; i < VRAM_SIZE; i++ ){					/* sine wave line	*/
		Data = (unsigned char)( ( sin( angle ) +1) *100 );
		vram_data[i] = Data;
		objSYS.delay66( 1 );
		ColorEnd1 = ColorData[((i/8) & 0x07)];
		objCRT.set_color( COL_BLK, ColorEnd1, COL_BLK );
		angle += delta;
	}
	for( j = 0; j < 200; j++ ){							/* sine wave line move	*/
		Data = vram_data[0];
		for( i = 0; i < (VRAM_SIZE-1); i++ ){
			vram_data[i] = vram_data[i+1];
		}
		ColorEnd1 = ColorData[((j/8) & 0x07)];
		ColorEnd2 = ColorData[(((j+1)/8) & 0x07)];
		objCRT.set_color( COL_BLK, ColorEnd1, ColorEnd2 );
		vram_data[VRAM_SIZE-1] = Data;
		objSYS.delay66( 1 );
	}
	
	objCRT.clear_screen();
	angle = 0;
	for( i = 0; i < VRAM_SIZE; i++ ){					/* sine draw	*/
		Data = (unsigned char)( ( sin( angle ) +1) *100 );
		vram_data[i] = Data;
		objSYS.delay66( 1 );
		ColorEnd1 = ColorData[((i/8) & 0x07)];
		ColorStart = ColorEnd1;
		objCRT.set_color( ColorStart, ColorEnd1, COL_BLK );
		angle += delta;
	}

	objCRT.clear_screen();
	for( i = 0; i < 10000; i++ ){						/* put dot		*/
		if( (i%500) == 0 ){
			ColorEnd1 = ColorData[((i/8) & 0x07)];
		}
		objCRT.set_color( COL_BLK, ColorEnd1, COL_BLK );
		LineStart = (unsigned char)random( 0, 200 );
		Position = (unsigned short)random( 0, VRAM_SIZE-1 );
		vram_data[Position] = LineStart;
	}
	
}


