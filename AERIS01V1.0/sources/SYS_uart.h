/*
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SYS_uart.h
 * Author: Clément ROUSSEAU
 *
 * Created on 20 novembre 2017, 22:42
 * 
 * Function : UART management
 */

#ifndef SYS_UART_H
#define	SYS_UART_H

#ifdef	__cplusplus
extern "C" {
#endif

/**************************************
 Includes               
**************************************/
#include "SUP_func.h"
    
/**************************************
 Global variables                  
**************************************/
extern boolean tx_running;
extern uint8 tx_data[];
    
/**************************************
 Global functions               
**************************************/
void init_uart ();
void UART_send(sBUF *data, uint8 size);

#ifdef	__cplusplus
}
#endif

#endif	/* SYS_UART_H */

