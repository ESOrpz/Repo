/*
 * ESO - AERIS 2 Project
 * 
 * Board 02 : On-board experimental data acquisition
 * 
 * File:   ADC_func.c
 * Author: Killian MELLE
 *
 * Created on 18 novembre 2017
 * 
 * Function : Convert Analogic data to Digital data
 */

 // Principe : l'ADC reçoit un signal analogique (une tension) qu'il convertit (après passage dans le pre-scaler et conversion logique) en une valeur digital de 10-bit, via des approximations.
 // La valeur minimum représente le GND et la valeur max représente la valeur de la tension.

#include "ADC_func.h"
#include "SUP_func.h"

volatile int res_c = 0;


void ADC_init(){

	// Conversion init

	ADCSRA |= (1u << 7); // ADEN
	
	// Prescale initialization with a 128 division factor

	ADCSRA |= 0b111; // ADC0, ADC1, ADC2 initialized to 1

	ADMUX &= ~(0b11 << 6); 	//AREF & Vref

	ADCSRA |= (1u << 3); // Interruption enabled


}

void ADC_convert(uint8_t cha_s){

	ADMUX |= cha_s; // ADC0 or ADC1 port selection
	ADCSRA |= (1u << 6); // ADSC : ADC Control and Status register A
	ADCSRA |= (1u << 4); // ADIF Initialization Interrupt Flag
}

ISR(ADC_vect) // Fonction d'interruption
{
	res_c = ADCL;
	res_c |= (ADCH << 8);
	ADCSRA |= (1u << 4); // ADIF Initialization Interrupt Flag

}

