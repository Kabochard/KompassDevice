#include <string.h>
#include "eusart.h"
#include "DigitsDriver.h"
#include "Switec_motor.h"

//#include "Switec_motor.h"

static char console[10][16]; //Pour voir ce qu'il se passe en mode debug et pis c tout

static unsigned int lines=0;
static unsigned int charac=0;

void EUSART_Initialize(void) {
    // disable interrupts before changing states
    PIE1bits.RCIE = 0;
    PIE1bits.TXIE = 0;

    // Set the EUSART module to the options selected in the user interfaceeee.

    // ABDEN disabled; WUE enabled; RCIDL idle; ABDOVF no_overflow; SCKP async_noninverted_sync_fallingedge; BRG16 16bit_generator; 
    BAUD1CON = 0x4A;

    // ADDEN disabled; RX9 8-bit; RX9D 0x0; FERR no_error; CREN enabled; SPEN enabled; SREN disabled; OERR no_error; 
    RC1STA = 0x90;

    // CSRC slave_mode; TRMT TSR_empty; TXEN enabled; BRGH hi_speed; SYNC asynchronous; SENDB sync_break_complete; TX9D 0x0; TX9 8-bit; 
    TX1STA = 0x26;

    // Baud Rate = 115200; SPBRGL 34; 
    SP1BRGL = 0x22;

    // Baud Rate = 115200; SPBRGH 0; 
    SP1BRGH = 0x00;

    
    // enable receive interrupt
    PIE1bits.RCIE = 1;
    
    //????
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
    
    if (1 == RC1STAbits.OERR) 
    {
        // EUSART error - restart
        RC1STAbits.CREN = 0;
        RC1STAbits.CREN = 1;
    }
    
    incoming = RC1REG;
    console[lines][charac]=incoming;
    
    if ((incoming == '\n')||(incoming == '\r')) //truc foireux pour remplir la console
    {  
        if(charac > 0)
        {
            //display the distance
           //display(lines) ;
            char str[9];
            strncpy(str, console[lines], 9);
                    
            processline(str);
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
    while(!TX1STAbits.TRMT); //Waiting for Previous Data to Transmit completly
    TX1REG = byte; //Writing data to Transmit Register, Starts transmission

}


//modif TIm

void processline(  char ch[])
{
    if(ch[0]=='d' && ch[5]=='b')
    {
       
   char src1[8];
   char src2[8];
   char dist[5];
   char bear[3];
  
   int distance;
   int bearing;
   //ugly fix cause it was turning me crazy
   //the incoming format is d####b## with d before the distance and b before the bearing
   strcpy(src1, ch);
   strcpy(src2, ch);
   dist[0] = ch[1];
   dist[1] = ch[2];
   dist[2] = ch[3];
   dist[3] = ch[4];
   dist[4] = '\0';
   
   bear[0] = ch[6];
   bear[1] = ch[7];
   bear[2] = ch[8];
   bear[3] = '\0';
   
   
   
   //memset(dist, '\0', sizeof(dist));
//   strcpy(src, ch);
//   strncpy(dist, ch+1, 4);
   
   //memset(bearing, '\0', sizeof(bearing));
//   strncpy(bear, src+6, 2);
//
    char *ptr;
   distance = strtol(dist, &ptr, 10); //string2int(dist);
   bearing = strtol(bear, &ptr, 10);//string2int(bear);
   
        
        //retrieving the bearing part of the string
//       char* bearing;
//       strncpy(bearing, ch+6, 2); 
       display(distance);
        
        //retrieving the distance part of the string
//       memset(ch, '\0', sizeof( ch ));
//       char* substr;
//       strncpy(substr, ch+1, 4); 
       goToPos(bearing);
       
       
       
    }
}

//char * stringcpy(register char * to, register const char * from, register int  size)
//{
//
//	register char *	cp;
//
//	cp = to;
//	while(size) {
//		size--;
//		if(!(*cp++ = *from++))
//			break;
//	}
//	while(size--)
//		*cp++ = 0;
//	return to;
//}



int
string2int(register const char * s)
{
	register int	a;
	register unsigned char	sign;

	while(*s == ' ' || *s == '\t')
		s++;
	a = 0;
	sign = 0;
	if(*s == '-') {
		sign++;
		s++;
	} else if(*s == '+')
		s++;
	while(isdigi(*s))
		a = a*10 + (*s++ - '0');
	if(sign)
		return -a;
	return a;
}

int isdigi(int c)
{
	return c <= '9' && c >= '0';
}