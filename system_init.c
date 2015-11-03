// Configuration bits: selected in the GUI

// CONFIG1
#pragma config IESO = ON    // Internal/External Switchover->Internal/External Switchover mode is enabled
#pragma config BOREN = ON    // Brown-out Reset Enable->Brown-out Reset enabled
#pragma config PWRTE = OFF    // Power-up Timer Enable->PWRT disabled
#pragma config FOSC = INTOSC    // Oscillator Selection->INTOSC oscillator: I/O function on CLKIN pin
#pragma config FCMEN = ON    // Fail-Safe Clock Monitor Enable->Fail-Safe Clock Monitor is enabled
#pragma config MCLRE = ON    // MCLR Pin Function Select->MCLR/VPP pin function is MCLR
#pragma config CP = OFF    // Flash Program Memory Code Protection->Program memory code protection is disabled
#pragma config CPD = OFF    // Data Memory Code Protection->Data memory code protection is disabled
#pragma config WDTE = OFF    // Watchdog Timer Enable->WDT disabled
#pragma config CLKOUTEN = OFF    // Clock Out Enable->CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin

// CONFIG2
#pragma config WRT = OFF    // Flash Memory Self-Write Protection->Write protection off
#pragma config LVP = OFF    // Low-Voltage Programming Enable->High-voltage on MCLR/VPP must be used for programming
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable->Stack Overflow or Underflow will cause a Reset
#pragma config PLLEN = ON    // PLL Enable->4x PLL enabled
#pragma config BORV = LO    // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (Vbor), low trip point selected.

#include <xc.h>
#include "system_init.h"
#include "eusart.h"
#include "i2c.h"
#include "OLED.h"
#include "needle.h"

void SYSTEM_Initialize(void) 
{
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    
    EUSART_Initialize();
    i2c_Init();
    
      // initialize user interface
    initNeedle(); 
    OLEDSetUp ( );
}

void OSCILLATOR_Initialize(void) {
    // SPLLEN disabled; SCS FOSC; IRCF 16MHz_HF; 
    OSCCON = 0x78;
    // OSTS intosc; HFIOFR disabled; HFIOFS not0.5percent_acc; PLLR disabled; T1OSCR disabled; MFIOFR disabled; HFIOFL not2percent_acc; LFIOFR disabled; 
    OSCSTAT = 0x00;
    // TUN 0x0; 
    OSCTUNE = 0x00;
    // Set the secondary oscillator

}

void PIN_MANAGER_Initialize(void) {
    
    LATA = 0x00;
    TRISA = 0x00;
    ANSELA = 0x00;

    LATB = 0x00;
    TRISB = 0xFF;
    ANSELB = 0x3F;
    WPUB = 0x00;

    LATC = 0x00;
    TRISC = 0xD8;

    LATD = 0x00;
    TRISD = 0xF8;
    ANSELD = 0xF0;

    LATE = 0x00;
    TRISE = 0x08;
    ANSELE = 0x00;
    WPUE = 0x00;

    OPTION_REGbits.nWPUEN = 0x01;

    APFCON = 0x00;


}

/**
 End of File
 */
