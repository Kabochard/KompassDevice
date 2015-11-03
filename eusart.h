#ifndef EUSART_H
#define EUSART_H

//initialise eusart connection
void EUSART_Initialize(void);
   
//handle incoming characters
void EUSART_Receive_ISR(void);

//send charcters to the uart module
void putch(unsigned char byte); // est appele lorsque tu fais un printf


#endif
/**
 End of File
 */
