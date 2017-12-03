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

boolean tx_running = FALSE;
uint8 tx_data[18];

void init_uart ()
{
    /* Config for 115200 bauds
     SPBRG = 0x10;
     BAUDCTLbits.BRG16 = 1;
     TXSTAbits.BRGH = 1;*/
    
    /* Config for 9600 bauds
     SPBRG = 0x0C;*/
    
    RCSTAbits.SPEN = 1;
    SPBRG = 0x10;
    BAUDCTLbits.BRG16 = 1;
    TXSTAbits.BRGH = 1;
    
    PIE1bits.T1IE = 1;
    TXSTAbits.TXEN = 1;
}

void UART_send(sBUF *data, uint8 size)
{
    memcpy(tx_data,data,size);
    if(tx_data[17] < 0xFF)
        TXREG = tx_data[17];
    else
        TXREG = 0xFE;
    tx_running = TRUE;
}
