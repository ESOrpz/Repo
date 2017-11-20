/*
 * ESO - AERIS 2 Project
 * 
 * Board 02 : On board experimental data acquisition
 * 
 * File:   SUP_func.h
 * Author: Clément ROUSSEAU
 *
 * Created on 18 novembre 2017, 21:42
 * 
 * Function : Contains main function with the sequencer
 */


#ifndef SUP_FUNC_H_
#define SUP_FUNC_H_

/************************************************************************/
/* INCLUDES                                                             */
/************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "SYS_io.h"

/************************************************************************/
/* DEFINES                                                              */
/************************************************************************/
#define CONT_1S 10000

/************************************************************************/
/* GLOBAL FUNCTION PROTOTYPES                                           */
/************************************************************************/
void SUP_initialisation();
void SUP_operational();

#endif /* SUP_FUNC_H_ */