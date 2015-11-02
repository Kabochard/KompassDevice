#include "eusart.h"

static char console[10][16]; //Pour voir ce qu'il se passe en mode debug

static unsigned int lines=0;
static unsigned int charac=0;

void EUSART_Initialize(void) {
    // disable interrupts before changing states
    PIE1bits.RCIE = 0;
    PIE1bits.TXIE = 0;

    // Set the EUSART module to the options selected in the user interface.

    // ABDEN disabled; WUE enabled; RCIDL idle; ABDOVF no_overflow; SCKP async_noninverted_sync_fallingedge; BRG16 16bit_generator; 
    BAUDCON = 0x4A;

    // ADDEN disabled; RX9 8-bit; RX9D 0x0; FERR no_error; CREN enabled; SPEN enabled; SREN disabled; OERR no_error; 
    RCSTA = 0x90;

    // CSRC slave_mode; TRMT TSR_empty; TXEN enabled; BRGH hi_speed; SYNC asynchronous; SENDB sync_break_complete; TX9D 0x0; TX9 8-bit; 
    TXSTA = 0x26;

    // Baud Rate = 115200; SPBRGL 34; 
    SPBRGL = 0x22;

    // Baud Rate = 115200; SPBRGH 0; 
    SPBRGH = 0x00;

    // enable receive interrupt
    PIE1bits.RCIE = 1;
}

/*void EUSART_Read(char *Output) 
{

    PIE1bits.RCIE = 0;

    while(eusartRxCount>0)
    {
    Output[eusartRxCount-1] = eusartRxBuffer[eusartRxCount-1];
    eusartRxCount--;
    }
    PIE1bits.RCIE = 1;

}*/

void EUSART_Receive_ISR(void) // appelle automatiquement lorsqu'il y a un charactere qui arrive
{
    char incoming;
    
    if (1 == RCSTAbits.OERR) 
    {
        // EUSART error - restart
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
    }
    
    incoming = RCREG;
    console[lines][charac]=incoming;
    
    if ((incoming == '\n')||(incoming == '\r')) //truc foireux pour remplir la console
    {  
        if(charac > 0)
        {
            lines++;
            charac =0;
        }
    }  
    else
    {
        charac++;
    }    
}


void putch(unsigned char byte)
{
    while(!TXSTAbits.TRMT); //Waiting for Previous Data to Transmit completly
    TXREG = byte; //Writing data to Transmit Register, Starts transmission

}