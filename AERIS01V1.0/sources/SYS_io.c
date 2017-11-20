/*
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SYS_io.c
 * Author: Clément ROUSSEAU
 *
 * Created on 20 novembre 2017, 22:35
 * 
 * Function : IO management
 */

#include "SYS_io.h"
#include "SUP_func.h"

void init_io ()
{
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC2 = 1;
    TRISCbits.TRISC4 = 1;
    TRISCbits.TRISC5 = 1;
    TRISAbits.TRISA5 = 0;
    PORTAbits.RA5 = 1;
}
