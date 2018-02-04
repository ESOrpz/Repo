/*
 * ADC.c
 *
 * Created: 04/02/2018 16:07:08
 *  Author: Killian
 */ 

 #include "ADC.h"

 volatile uint16_t result;



 ISR(ADC_vect) // Fonction d'interruption
 {
	result = ADCL + (ADCH<<8);
 }

 void initialization(){

	ADCSRA = (1<<ADEN); // Enable ADC
	ADCSRA = (0b111 << ADPS0); // 128 division factor
	PRR = (1<<PRADC);
	
 }

 void conversion(){

	ADCSRA = (1<<ADSC); // Enable conversion

 }

 void channel_selection(uint8_t ADC_set){

	ADMUX = (ADMUX & 0b11110000) + (ADC_set << MUX0);

 }