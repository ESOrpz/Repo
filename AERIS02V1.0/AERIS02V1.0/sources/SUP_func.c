/*
 * ESO - AERIS 2 Project
 * 
 * Board 02 : On board experimental data acquisition
 * 
 * File:   SUP_func.c
 * Author: Clément ROUSSEAU
 *
 * Created on 18 novembre 2017, 21:42
 * 
 * Function : Contains main function with the sequencer
 */

/************************************************************************/
/* INCLUDES                                                             */
/************************************************************************/
#include "SUP_func.h"

/************************************************************************/
/* GLOBAL VARIABLES                                                     */
/************************************************************************/
volatile unsigned long SUP_compteur = 0;

/************************************************************************/
/* GLOBAL FUNCTIONS                                                     */
/************************************************************************/
ISR(TIMER0_OVF_vect) // Fonction d'interruption
{
	TCNT0 = 0x06;
	PORTD = PORTD ^ (0x02); // Inverse l'état de la pin 2 de PORTD
	SUP_compteur++;
}

int main(void)
{
	SUP_initialisation();
	
    SUP_operational();
}

void SUP_initialisation()
{
	/* ------------------------------------------------------
		Ports GPIO (General Purpose Input Output)
	------------------------------------------------------ */
	
	/*	DDRn -> Définition des pins comme entrée ou sortie
		PORTn -> Initialisation de l'état des pins
		DDRn = 0 & PORTn = 0 -> Simple entrée
		DDRn = 0 & PORTn = 1 -> Entrée avec pull-up
		DDRn = 1 & PORTn = 0 -> Sortie 0V
		DDRn = 1 & PORTn = 1 -> Sortie 5V	*/
	
	DDRD = 0xFF; //Toutes les pins de PORTD initialisées en sortie
	PORTD = 0x00; //Niveau logique bas
	
	/* ------------------------------------------------------
		TIMER0
	------------------------------------------------------ */
	
	/*	TCNT0 -> Contient la valeur de Timer0
	
		TIMSK0 bit 0 -> Authorise les interruptions du programme par Timer0
		Si cette interruption est activée, lorsque Timer0 est incrémenté alors qu'il est à sa valeur maximale (0xFF),
		sa valeur repasse à 0 et l'exécution du code est interrompue pour passer dans la fonction d'interruption
		correspondant à l'interruption de Timer0 -> ISR(TIMER0_OVF_vect)
		A la fin de la fonction d'interruption, l'exécution du code reprends à l'endroit où elle s'était arrêtée
	
		TCCR0B bits 0, 1 et 2 -> Paramétrage du prescaler de Timer0
		000 -> Pas d'incrémentation de Timer0
		001 -> Timer0 actif, prescaler désactivé
		010 -> prescaler à 8
		011 -> 64
		100 -> 256
		101 -> 1024	*/
	
	TCCR0B = 0x02; //Prescaler à 8
	TIMSK0 = 0x01; //Interruption authorisée
	TCNT0 = 0x06; //Initialisation de la valeur de Timer0
	/*	Ici, la fréquence d'horloge du microcontroleur est de 20Mhz et l'interruption est activée lorque TCNT0 dépasse 255 ou FF
		En initialisant la valeur à 6, l'interruption sera générée par période de :
		1/20E+6 * 8 * (256 - 6) = 0.0001s	*/
	
	/* ------------------------------------------------------
		Global Interrupt enable
	------------------------------------------------------ */
	sei(); //Permet l'utilisation des interruptions
}

void SUP_operational()
{
	while (1)
	{
		while(SUP_compteur < CONT_1S); // On attend 10000 interruptions soit 1 seconde
		PORTD = PORTD ^ (0x01); // Inverse l'état de la pin 1 de PORTD
		SUP_compteur = 0; // Réinitialisation du compteur
	}
}
