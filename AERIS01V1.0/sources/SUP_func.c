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
 * Implémenter la nouvelle mise en forme
********************************************************/

#include "SUP_func.h"

static volatile uint32 compteur = 0;
static sBUF anData[3];

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
    uint32 latchSequencer = compteur;
    
    while(1)
    {
        while(latchSequencer >= compteur);
        latchSequencer = compteur;
        
        SUP_ADC_management();
        
        SUP_UART_management();
    }
}

void SUP_ADC_management ()
{
    uint8 sequence = 0;
    
    switch(sequence++)
    {
        case 0:
            anData[0].time = compteur;
            anData[0].data = ADC_get_value();
            ADC_chan_change(AN5);
            break;

        case 1:
            anData[1].time = compteur;
            anData[1].data = ADC_get_value();
            ADC_chan_change(AN6);
            break;

        case 2:
            anData[2].time = compteur;
            anData[2].data = ADC_get_value();
            ADC_chan_change(AN4);
            break;

        case 3:
            //send();
            break;

        default:
            sequence = 0;
    }
}

void SUP_UART_management ()
{
    
}

void interrupt f_int(void)
{
    if(INTCONbits.T0IF)
    {
        TMR0 = 0xE6; //En faire une fonction dans SYS_tmr0.c
        INTCONbits.T0IF = 0;
        compteur++;
    }
    /*if(PIR1bits.ADIF)
    {
        endConv = TRUE;
        PIR1bits.ADIF = 0;
    }
    if(PIR1bits.RCIF)
    {
        msg = RCREG;
        msgReceived = TRUE;
        PIR1bits.RCIF = 0;
    }
    if(PIR1bits.TXIF)
    {
        static uint8 txState = 0;
        
        PIR1bits.TXIF = 0;
        if(txState++ < 17)
        {
            TXREG = txData[17-txState];
        }
        else if(txState == 18)
        {
            TXREG = 0x42;
        }
        else if(txState == 18)
        {
            TXREG = '\r';
        }
        else if(txState == 19)
        {
            TXREG = '\n';
        }
        else
        {
            TXSTAbits.TXEN = 0;
            PIE1bits.T1IE = 0;
            PIE1bits.RCIE = 1;
            RCSTAbits.CREN = 1;
            txRunning = FALSE;
            txState = 0;
        }
    }*/
}
