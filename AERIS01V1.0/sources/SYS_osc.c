/*
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SYS_osc.c
 * Author: Clément ROUSSEAU
 *
 * Created on 20 novembre 2017, 22:22
 * 
 * Function : Oscillator management
 */

#include "SYS_osc.h"

void init_osc ()
{
    OSCCONbits.IRCF2 = 1;
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 1;
}
