#ifndef _EUSART_H
#define _EUSART_H


#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include	<ctype.h>
#include	<stdlib.h>



void EUSART_Initialize(void);
   
void EUSART_Receive_ISR(void);
    
void putch(unsigned char byte); // est appele lorsque tu fais un printf

//modif tim
int
string2int(register const char * s);

int isdigi(int c);

void processline(char ch[]);

//char * stringcpy(register char * to, register const char * from, register size_t size);
//char * stringcpy(register char * to, register const char * from, register int  size);
#endif
/**
 End of File
 */

