/*
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SYS_uart.c
 * Author: Clément ROUSSEAU
 *
 * Created on 20 novembre 2017, 22:42
 * 
 * Function : UART management
 */

#include "SYS_uart.h"
#include "SUP_func.h"

void init_uart ()
{
    RCSTAbits.SPEN = 1;
    SPBRG = 0x0C;
    
    /* Config for 115200 bauds
     SPBRG = 0x10;
     BAUDCTLbits.BRG16 = 1;
     TXSTAbits.BRGH = 1;*/
}
