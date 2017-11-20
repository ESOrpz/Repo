/*
 * ESO - AERIS 2 Project
 * 
 * Board 01 : Acquisition board for pneumatic circuit test bench
 * 
 * File:   SYS_adc.h
 * Author: Clément ROUSSEAU
 *
 * Created on 20 novembre 2017, 22:47
 * 
 * Function : ADC management
 */

#ifndef SYS_ADC_H
#define	SYS_ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

/**************************************
 Analog channels                   
**************************************/
#define AN4 0b100 //Pin 10 (RC0)
#define AN5 0b101 //Pin 9 (RC1)
#define AN6 0b110 //Pin 8 (RC2)
    
/**************************************
 Global functions               
**************************************/
void init_adc ();

#ifdef	__cplusplus
}
#endif

#endif	/* SYS_ADC_H */

