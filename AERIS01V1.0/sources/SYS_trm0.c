/*
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SYS_tmr0.c
 * Author: Clément ROUSSEAU
 *
 * Created on 20 novembre 2017, 22:31
 * 
 * Function : Timer0 management
 */

#include "SYS_tmr0.h"
#include "SUP_func.h"

void init_tmr0 ()
{
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS2 = 0;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 0;
    
    INTCONbits.T0IE = 1;
    INTCONbits.T0IF = 0;
}
