/*****************************************************************************
    System Name : Simple Analog RGB 2011
    File Name   : defPort.h
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
/*  DEFINE                                                                  */
/*==========================================================================*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        with pullup --> input mode and write "1"
                
                I/O pullup
    Port B      ----------------------------------------
        PB_5    out             SCK         SCK
        PB_4    in  w/o         SD_DO       MISO
        
        PB_3    out             SD_DI       MOSI
        PB_2    out             SD_CS       Port
        PB_1    out             H_Sync_Out  OC1A	13pin Orange
        PB_0    out             V_Sync_Out  Port	14pin Yellow

    Port C      ----------------------------------------
        PC_5    out             Blue_1      Port
        PC_4    out             Blue_0      Port
        
        PC_3    out             Green_1     Port
        PC_2    out             Green_0     Port
        PC_1    out             Red_1       Port
        PC_0    out             Red_0       Port

    Port D      ----------------------------------------
        PD_7    out             Sig_A3      Port
        PD_6    out             Sig_A2      Port
        PD_5    out             Sig_A1      Port
        PD_4    out             Sig_A0      Port
        
        PD_3    out             Sound_Out   OC2B
        PD_2    out             Up_Down     Port (Debug Port)
        PD_1    out             TxD         TxD
        PD_0    in  w/o         RxD         RxD

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define P_LED1_ON       asm volatile("cbi 0x05,5"::)    /* PORTB.5          */
#define P_LED1_OFF      asm volatile("sbi 0x05,5"::)
#define P_UD_ON       	asm volatile("sbi 0x0B,2"::)    /* PORTD.2          */
#define P_UD_OFF      	asm volatile("cbi 0x0B,2"::)
#define P_VSYNC_ON      asm volatile("sbi 0x05,0"::)    /* PORTB.0          */
#define P_VSYNC_OFF     asm volatile("cbi 0x05,0"::)

/*  --- pullup ---------------------------------------------------------------
    PUD PullUp Disable  initial Value = 0 -> pull up enable
    the PUD bit in the MCUCR Register can be set to disable all pull-ups 
    in all ports.
----------------------------------------------------------------------------*/
#define OR_MCUCR    0x10        /* PUD = 1 pull up disable      0001_0000B  */
                                /* 0:in,1:out   initial DDRB    0000_0000B  */
                                
#define OR_DDRB     0x2F        /*                              0010_1111B  */
#define AND_DDRB    0xEF        /*                              1110_1111B  */
#define AND_PORTB   0xFD        /*                              1111_1100B  */

#define AND_PORTC       0x00    /*                              0000_0000B  */
#define  OR_DDRC_RED_MN 0x02    /*                              0000_0010B  */
#define AND_DDRC_RED_MN 0x02    /*                              0000_0010B  */
#define  OR_DDRC_GRN_MN 0x08    /*                              0000_1000B  */
#define AND_DDRC_GRN_MN 0x08    /*                              0000_1000B  */
#define  OR_DDRC_BLU_MN 0x20    /*                              0010_0000B  */
#define AND_DDRC_BLU_MN 0x20    /*                              0010_0000B  */
#define  OR_DDRC_COL_6B 0x3F    /*                              0011_1111B  */
#define AND_DDRC_COL_6B 0x3F    /*                              0011_1111B  */
#define  OR_DDRC_GSC_4B 0x00    /*                              0000_0000B  */
#define AND_DDRC_GSC_4B 0x00    /*                              0000_0000B  */

#define AND_PORTD       0x00    /*                              0000_0000B  */
#define AND_DDRD_RED_MN 0x0E    /*                              0000_1110B  */
#define AND_DDRD_GRN_MN 0x0E    /*                              0000_1110B  */
#define AND_DDRD_BLU_MN 0x0E    /*                              0000_1110B  */
#define AND_DDRD_BLU_MN 0x0E    /*                              0000_1110B  */
#define AND_DDRD_COL_6B 0x0E    /*                              0000_1110B  */
#define  OR_DDRD_GSC_4B 0xFE    /*                              1111_1110B  */
#define AND_DDRD_GSC_4B 0xFE    /*                              1111_1110B  */

