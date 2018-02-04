/*
 * ADC.h
 *
 * Created: 04/02/2018 16:18:32
 *  Author: Killian
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "SUP_func.h"

#define ADC0 0b0000
#define ADC1 0b0001
#define ADC2 0b0010
#define ADC3 0b0011
#define ADC4 0b0100
#define ADC5 0b0101
#define ADC6 0b0110
#define ADC7 0b0111
extern volatile uint16_t result;

void initialization();
void conversion();
void channel_selection(uint8_t ADC_set);

#endif /* ADC_H_ */