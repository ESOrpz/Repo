/* 
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SUP_func.h
 * Author: Clément ROUSSEAU
 *
 * Created on 15 novembre 2017, 21:42
 * 
 * Function : Contains main function with the sequencer
 */

#ifndef SUP_FUNC_H
#define	SUP_FUNC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
/**************************************
 Configuration bits                    
**************************************/
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Detect (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
    
/**************************************
 Includes               
**************************************/
#include <xc.h>
#include "SYS_osc.h"
#include "SYS_tmr0.h"
#include "SYS_io.h"
#include "SYS_uart.h"
#include "SYS_adc.h"

/**************************************
 Timing                   
**************************************/
#define CONT_10s 100000
#define CONT_5s 50000
#define CONT_1S 10000
#define CONT_500MS 5000
#define CONT_100MS 1000
#define CONT_10MS 100
#define CONT_5MS 50

/**************************************
 Defines                   
**************************************/
#define TRUE 1
#define FALSE 0

/**************************************
 Typedefs                    
**************************************/
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;
typedef struct
{
    uint16 data;
    uint32 time;
}sBUF;

#define TRUE 1
#define FALSE 0

/**************************************
 Global variables                  
**************************************/

/**************************************
 Global functions               
**************************************/
void SUP_Init();
void SUP_Oper();

#ifdef	__cplusplus
}
#endif

#endif	/* SUP_FUNC_H */
