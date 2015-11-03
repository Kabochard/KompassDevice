
#include "eusart.h"
#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "OLED.h"
#include "needle.h"

static char console[10][16]; //Pour voir ce qu'il se passe en mode debug
static char line[16];
static int idex;
static char distance[5];
static int bearing;

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
    
    //initialise values at 0
    idex = 0;
    bearing = 0;
    distance[0] = '0';
    distance[1] = '0';
    distance[2] = '0';
    distance[3] = '0';
    distance[4] = '\0';
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
    
    
    //check if 
    
    
    if (1 == RCSTAbits.OERR) 
    {
        //clean line and reinit index
        idex = 0;
        memset(&line[0], 0, sizeof(line));
        
        // EUSART error - restart
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;  
    }
    else
    {
       incoming = RCREG;
       
       if ((incoming == '\n')||(incoming == '\r')) 
       {
           //check format: 8 characters, starting with d 
           if ((idex == 9) && (line[0]=='d')&&(line[5]=='b'))
           {

               char distArr[9];
               char bearingArr[4];
               
              //retrieve dist and bearing
               distArr[0] = line[1];
               distArr[1] = line[2];
               distArr[2] = line[3];
               distArr[3] = '.';
               distArr[4] = line[4];
               distArr[5] = ' ';
               distArr[6] = 'k';
               distArr[7] = 'm';
               distArr[8] = '\0';
   
                bearingArr[0] = line[6];
                bearingArr[1] = line[7];
                bearingArr[2] = line[8];
                bearingArr[3] = '\0';

                char *ptr; //useless pointer to store the next character
                //distance = strtol(distArr, &ptr, 10); 
                bearing = strtol(bearingArr, &ptr, 10);
                

                OLEDText ( 0, 0, &distArr, SIZE_TWO, WHITE );
                OLEDUpdateDisplay ( DDGRAM_CLEAR );
                moveNeedle(AngleToSlot(bearing));

           }
            //clean line and reinit index
             idex = 0;
            memset(&line[0], 0, sizeof(line));
        }
       else {
           line[idex] = incoming;
           idex = idex + 1;
       }
                    
    }
       
 }
    



void putch(unsigned char byte)
{
    while(!TXSTAbits.TRMT); //Waiting for Previous Data to Transmit completly
    TXREG = byte; //Writing data to Transmit Register, Starts transmission

}