#ifndef _EUSART_H
#define _EUSART_H


#include <xc.h>
#include <stdbool.h>
#include <stdint.h>




void EUSART_Initialize(void);
   
void EUSART_Receive_ISR(void);
    
void putch(unsigned char byte); // est appele lorsque tu fais un printf

#endif
/**
 End of File
 */
