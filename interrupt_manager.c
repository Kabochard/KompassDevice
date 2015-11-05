#include "interrupt_manager.h"
#include <xc.h>
#include "eusart.h"

void interrupt INTERRUPT_InterruptManager(void) {
    // interrupt handler
    if (PIE1bits.RCIE == 1 && PIR1bits.RCIF == 1) 
    {
        EUSART_Receive_ISR();
        
    } 
    else 
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
 */