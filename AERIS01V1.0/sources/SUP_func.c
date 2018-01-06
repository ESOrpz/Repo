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

volatile uint32 compteur = 0;
sBUF anData[3];
boolean emission_rdy = FALSE;

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
    
    TMR0_reload();
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
    static uint8 sequence = 0;
    
    if(!emission_rdy)
    {
        switch(sequence)
        {
            case 0:
                ADC_start_conv();
                sequence++;
                break;

            case 1:
                if(endConv)
                {
                    endConv = FALSE;
                    anData[0].time = compteur;
                    anData[0].data = ADC_get_value();
                    ADC_chan_change(AN5);
                    sequence++;
                }
                break;

            case 2:
                ADC_start_conv();
                sequence++;
                break;

            case 3:
                if(endConv)
                {
                    endConv = FALSE;
                    anData[1].time = compteur;
                    anData[1].data = ADC_get_value();
                    ADC_chan_change(AN6);
                    sequence++;
                }
                break;

            case 4:
                ADC_start_conv();
                sequence++;
                break;

            case 5:
                if(endConv)
                {
                    endConv = FALSE;
                    anData[2].time = compteur;
                    anData[2].data = ADC_get_value();
                    ADC_chan_change(AN4);
                    sequence++;
                }
                break;

            case 6:
                emission_rdy = TRUE;
                sequence = 0;
                break;

            default:
                sequence = 0;
        }
    }
}

void SUP_UART_management ()
{
    if(emission_rdy && !tx_running)
    {
        emission_rdy = FALSE;
        UART_send(anData, sizeof(anData));
    }
}

void interrupt f_int(void)
{
    if(INTCONbits.T0IF)
    {
        TMR0_reload();
        INTCONbits.T0IF = 0;
        compteur++;
    }
    if(PIR1bits.ADIF)
    {
        endConv = TRUE;
        PIR1bits.ADIF = 0;
    }
    /*if(PIR1bits.RCIF)
    {
        msg = RCREG;
        msgReceived = TRUE;
        PIR1bits.RCIF = 0;
    }*/
    if(PIR1bits.TXIF && tx_running)
    {
        static uint8 txState = 0;
        
        PIR1bits.TXIF = 0;
        if(txState++ < 17)
        {
            if(tx_data[17-txState] < 0xFF)
                TXREG = tx_data[17-txState];
            else
                TXREG = 0xFE;
        }
        else if(txState == 18)
        {
            TXREG = 0xFF;
        }
        /*else if(txState == 18)
        {
            TXREG = '\r';
        }
        else if(txState == 19)
        {
            TXREG = '\n';
        }*/
        else
        {
            tx_running = FALSE;
            txState = 0;
        }
    }
}
