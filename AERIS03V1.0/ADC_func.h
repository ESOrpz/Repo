/*
 * ADC_func.h
 *
 * Created: 18/11/2017 19:05:34
 *  Author: Killian
 */ 


#ifndef ADC_FUNC_H_
#define ADC_FUNC_H_

#define ADC_0 0b0000
#define ADC_1 0b0001

#include <avr/io.h>

void ADC_init();

void ADC_convert(uint8_t cha_s);

void ADC_result();

#endif //ADC_FUNC_H_