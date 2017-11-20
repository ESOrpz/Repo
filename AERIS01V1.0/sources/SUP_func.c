/*
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SUP_func.c
 * Author: Clément ROUSSEAU
 *
 * Created on 15 novembre 2017, 21:42
 * 
 * Function : Contains main function with the sequencer
 */

/********************************************************
    TO DO
 * Augmenter le baudrate
 * Fixer la fréquence d'émission
********************************************************/

#include "SUP_func.h"

void main(void) {
    
    SUP_Init();
    
    SUP_Oper();
    
    return;
}

void SUP_Init()
{
    init_osc ();
    
    init_tmr0 ();
    
    init_io ();
    
    init_uart ();
    
    init_adc ();
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    TMR0 = 0xE6; //En faire une fonction dans SYS_tmr0.c
}

void SUP_Oper()
{
    while(1)
    {
    }
}
