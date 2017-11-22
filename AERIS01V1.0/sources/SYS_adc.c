/*
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SYS_adc.c
 * Author: Clément ROUSSEAU
 *
 * Created on 20 novembre 2017, 22:47
 * 
 * Function : ADC management
 */

#include "SYS_adc.h"

volatile uint8 endConv = FALSE;

void init_adc ()
{
    ADCON0bits.ADFM = 1;
    ADCON0bits.CHS = AN4;
    ADCON0bits.ADON = 1;
    ADCON1bits.ADCS2 = 1;
    ADCON1bits.ADCS1 = 0;
    ADCON1bits.ADCS0 = 1;
    
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF = 0;
}

void ADC_chan_change(uint8 ANChannel)
{
    ADCON0bits.CHS = ANChannel;
}

uint16 ADC_get_value()
{
    uint16 ANvalue = 0;
    
    if(endConv) //A REVOIR !!
    {
        ANvalue = ADRESL;
        ANvalue += (ADRESH << 8);
        //endConv = FALSE;
    }
    else
    {
        PIR1bits.ADIF = 0;
        ADCON0bits.GO = 1;
    }
    
    return ANvalue;
}
