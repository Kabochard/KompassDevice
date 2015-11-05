#include "interrupt_manager.h"
#include <xc.h>
#include "eusart.h"
#include "needle.h"

#define _XTAL_FREQ 16000000

void interrupt INTERRUPT_InterruptManager(void) {
    // interrupt handler
    if (PIE1bits.RCIE == 1 && PIR1bits.RCIF == 1) 
    {
        EUSART_Receive_ISR();
        
    }
      else if(INTCONbits.IOCIF ==1)
    {
        INTCONbits.IOCIE = 0;
        char status = 0;
        if(IOCBFbits.IOCBF2 ==1)
        {
            IOCBFbits.IOCBF2=0;
            moveNeedle_fw();
            __delay_ms(100);
            
            while(status == 0)
                status = PORTBbits.RB2;
           __delay_ms(100);
        }
        else if(IOCBFbits.IOCBF3 ==1)
        {
            IOCBFbits.IOCBF3=0;
            moveNeedle_bk();
            __delay_ms(100);
           while(status == 0)
                status = PORTBbits.RB3;
            __delay_ms(100);
        }
        else
        {
        
        }
        INTCONbits.IOCIE = 1;
    }
    else 
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
 */