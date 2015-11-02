/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB® Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC16LF1939
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set COIL_1 aliases
#define COIL_1_TRIS               TRISA0
#define COIL_1_LAT                LATA0
#define COIL_1_PORT               RA0
#define COIL_1_ANS                ANSA0
#define COIL_1_SetHigh()    do { LATA0 = 1; } while(0)
#define COIL_1_SetLow()   do { LATA0 = 0; } while(0)
#define COIL_1_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define COIL_1_GetValue()         RA0
#define COIL_1_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define COIL_1_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define COIL_1_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define COIL_1_SetDigitalMode()   do { ANSA0 = 0; } while(0)
// get/set COIL_0 aliases
#define COIL_0_TRIS               TRISA1
#define COIL_0_LAT                LATA1
#define COIL_0_PORT               RA1
#define COIL_0_ANS                ANSA1
#define COIL_0_SetHigh()    do { LATA1 = 1; } while(0)
#define COIL_0_SetLow()   do { LATA1 = 0; } while(0)
#define COIL_0_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define COIL_0_GetValue()         RA1
#define COIL_0_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define COIL_0_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define COIL_0_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define COIL_0_SetDigitalMode()   do { ANSA1 = 0; } while(0)
// get/set COIL_3 aliases
#define COIL_3_TRIS               TRISA2
#define COIL_3_LAT                LATA2
#define COIL_3_PORT               RA2
#define COIL_3_ANS                ANSA2
#define COIL_3_SetHigh()    do { LATA2 = 1; } while(0)
#define COIL_3_SetLow()   do { LATA2 = 0; } while(0)
#define COIL_3_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define COIL_3_GetValue()         RA2
#define COIL_3_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define COIL_3_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define COIL_3_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define COIL_3_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set COIL_2 aliases
#define COIL_2_TRIS               TRISA3
#define COIL_2_LAT                LATA3
#define COIL_2_PORT               RA3
#define COIL_2_ANS                ANSA3
#define COIL_2_SetHigh()    do { LATA3 = 1; } while(0)
#define COIL_2_SetLow()   do { LATA3 = 0; } while(0)
#define COIL_2_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define COIL_2_GetValue()         RA3
#define COIL_2_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define COIL_2_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define COIL_2_SetAnalogMode()   do { ANSA3 = 1; } while(0)
#define COIL_2_SetDigitalMode()   do { ANSA3 = 0; } while(0)
// get/set COIL_5 aliases
#define COIL_5_TRIS               TRISA4
#define COIL_5_LAT                LATA4
#define COIL_5_PORT               RA4
#define COIL_5_ANS                ANSA4
#define COIL_5_SetHigh()    do { LATA4 = 1; } while(0)
#define COIL_5_SetLow()   do { LATA4 = 0; } while(0)
#define COIL_5_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define COIL_5_GetValue()         RA4
#define COIL_5_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define COIL_5_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

#define COIL_5_SetAnalogMode()   do { ANSA4 = 1; } while(0)
#define COIL_5_SetDigitalMode()   do { ANSA4 = 0; } while(0)
// get/set COIL_4 aliases
#define COIL_4_TRIS               TRISA5
#define COIL_4_LAT                LATA5
#define COIL_4_PORT               RA5
#define COIL_4_ANS                ANSA5
#define COIL_4_SetHigh()    do { LATA5 = 1; } while(0)
#define COIL_4_SetLow()   do { LATA5 = 0; } while(0)
#define COIL_4_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define COIL_4_GetValue()         RA5
#define COIL_4_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define COIL_4_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define COIL_4_SetAnalogMode()   do { ANSA5 = 1; } while(0)
#define COIL_4_SetDigitalMode()   do { ANSA5 = 0; } while(0)
// get/set COIL_10 aliases
#define COIL_10_TRIS               TRISA6
#define COIL_10_LAT                LATA6
#define COIL_10_PORT               RA6
#define COIL_10_SetHigh()    do { LATA6 = 1; } while(0)
#define COIL_10_SetLow()   do { LATA6 = 0; } while(0)
#define COIL_10_Toggle()   do { LATA6 = ~LATA6; } while(0)
#define COIL_10_GetValue()         RA6
#define COIL_10_SetDigitalInput()    do { TRISA6 = 1; } while(0)
#define COIL_10_SetDigitalOutput()   do { TRISA6 = 0; } while(0)

// get/set COIL_9 aliases
#define COIL_9_TRIS               TRISA7
#define COIL_9_LAT                LATA7
#define COIL_9_PORT               RA7
#define COIL_9_SetHigh()    do { LATA7 = 1; } while(0)
#define COIL_9_SetLow()   do { LATA7 = 0; } while(0)
#define COIL_9_Toggle()   do { LATA7 = ~LATA7; } while(0)
#define COIL_9_GetValue()         RA7
#define COIL_9_SetDigitalInput()    do { TRISA7 = 1; } while(0)
#define COIL_9_SetDigitalOutput()   do { TRISA7 = 0; } while(0)

// get/set COIL_11 aliases
#define COIL_11_TRIS               TRISC0
#define COIL_11_LAT                LATC0
#define COIL_11_PORT               RC0
#define COIL_11_SetHigh()    do { LATC0 = 1; } while(0)
#define COIL_11_SetLow()   do { LATC0 = 0; } while(0)
#define COIL_11_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define COIL_11_GetValue()         RC0
#define COIL_11_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define COIL_11_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

// get/set COIL_12 aliases
#define COIL_12_TRIS               TRISC1
#define COIL_12_LAT                LATC1
#define COIL_12_PORT               RC1
#define COIL_12_SetHigh()    do { LATC1 = 1; } while(0)
#define COIL_12_SetLow()   do { LATC1 = 0; } while(0)
#define COIL_12_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define COIL_12_GetValue()         RC1
#define COIL_12_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define COIL_12_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

// get/set COIL_13 aliases
#define COIL_13_TRIS               TRISC2
#define COIL_13_LAT                LATC2
#define COIL_13_PORT               RC2
#define COIL_13_SetHigh()    do { LATC2 = 1; } while(0)
#define COIL_13_SetLow()   do { LATC2 = 0; } while(0)
#define COIL_13_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define COIL_13_GetValue()         RC2
#define COIL_13_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define COIL_13_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

// get/set RESET_BT aliases
#define RESET_BT_TRIS               TRISC5
#define RESET_BT_LAT                LATC5
#define RESET_BT_PORT               RC5
#define RESET_BT_SetHigh()    do { LATC5 = 1; } while(0)
#define RESET_BT_SetLow()   do { LATC5 = 0; } while(0)
#define RESET_BT_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define RESET_BT_GetValue()         RC5
#define RESET_BT_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define RESET_BT_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

// get/set COIL_14 aliases
#define COIL_14_TRIS               TRISD0
#define COIL_14_LAT                LATD0
#define COIL_14_PORT               RD0
#define COIL_14_ANS                ANSD0
#define COIL_14_SetHigh()    do { LATD0 = 1; } while(0)
#define COIL_14_SetLow()   do { LATD0 = 0; } while(0)
#define COIL_14_Toggle()   do { LATD0 = ~LATD0; } while(0)
#define COIL_14_GetValue()         RD0
#define COIL_14_SetDigitalInput()    do { TRISD0 = 1; } while(0)
#define COIL_14_SetDigitalOutput()   do { TRISD0 = 0; } while(0)

#define COIL_14_SetAnalogMode()   do { ANSD0 = 1; } while(0)
#define COIL_14_SetDigitalMode()   do { ANSD0 = 0; } while(0)
// get/set COIL_15 aliases
#define COIL_15_TRIS               TRISD1
#define COIL_15_LAT                LATD1
#define COIL_15_PORT               RD1
#define COIL_15_ANS                ANSD1
#define COIL_15_SetHigh()    do { LATD1 = 1; } while(0)
#define COIL_15_SetLow()   do { LATD1 = 0; } while(0)
#define COIL_15_Toggle()   do { LATD1 = ~LATD1; } while(0)
#define COIL_15_GetValue()         RD1
#define COIL_15_SetDigitalInput()    do { TRISD1 = 1; } while(0)
#define COIL_15_SetDigitalOutput()   do { TRISD1 = 0; } while(0)

#define COIL_15_SetAnalogMode()   do { ANSD1 = 1; } while(0)
#define COIL_15_SetDigitalMode()   do { ANSD1 = 0; } while(0)
// get/set COIL_16 aliases
#define COIL_16_TRIS               TRISD2
#define COIL_16_LAT                LATD2
#define COIL_16_PORT               RD2
#define COIL_16_ANS                ANSD2
#define COIL_16_SetHigh()    do { LATD2 = 1; } while(0)
#define COIL_16_SetLow()   do { LATD2 = 0; } while(0)
#define COIL_16_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define COIL_16_GetValue()         RD2
#define COIL_16_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define COIL_16_SetDigitalOutput()   do { TRISD2 = 0; } while(0)

#define COIL_16_SetAnalogMode()   do { ANSD2 = 1; } while(0)
#define COIL_16_SetDigitalMode()   do { ANSD2 = 0; } while(0)
// get/set COIL_17 aliases
#define COIL_17_TRIS               TRISD3
#define COIL_17_LAT                LATD3
#define COIL_17_PORT               RD3
#define COIL_17_ANS                ANSD3
#define COIL_17_SetHigh()    do { LATD3 = 1; } while(0)
#define COIL_17_SetLow()   do { LATD3 = 0; } while(0)
#define COIL_17_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define COIL_17_GetValue()         RD3
#define COIL_17_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define COIL_17_SetDigitalOutput()   do { TRISD3 = 0; } while(0)

#define COIL_17_SetAnalogMode()   do { ANSD3 = 1; } while(0)
#define COIL_17_SetDigitalMode()   do { ANSD3 = 0; } while(0)
// get/set COIL_7 aliases
#define COIL_7_TRIS               TRISE0
#define COIL_7_LAT                LATE0
#define COIL_7_PORT               RE0
#define COIL_7_ANS                ANSE0
#define COIL_7_SetHigh()    do { LATE0 = 1; } while(0)
#define COIL_7_SetLow()   do { LATE0 = 0; } while(0)
#define COIL_7_Toggle()   do { LATE0 = ~LATE0; } while(0)
#define COIL_7_GetValue()         RE0
#define COIL_7_SetDigitalInput()    do { TRISE0 = 1; } while(0)
#define COIL_7_SetDigitalOutput()   do { TRISE0 = 0; } while(0)

#define COIL_7_SetAnalogMode()   do { ANSE0 = 1; } while(0)
#define COIL_7_SetDigitalMode()   do { ANSE0 = 0; } while(0)
// get/set COIL_6 aliases
#define COIL_6_TRIS               TRISE1
#define COIL_6_LAT                LATE1
#define COIL_6_PORT               RE1
#define COIL_6_ANS                ANSE1
#define COIL_6_SetHigh()    do { LATE1 = 1; } while(0)
#define COIL_6_SetLow()   do { LATE1 = 0; } while(0)
#define COIL_6_Toggle()   do { LATE1 = ~LATE1; } while(0)
#define COIL_6_GetValue()         RE1
#define COIL_6_SetDigitalInput()    do { TRISE1 = 1; } while(0)
#define COIL_6_SetDigitalOutput()   do { TRISE1 = 0; } while(0)

#define COIL_6_SetAnalogMode()   do { ANSE1 = 1; } while(0)
#define COIL_6_SetDigitalMode()   do { ANSE1 = 0; } while(0)
// get/set COIL_8 aliases
#define COIL_8_TRIS               TRISE2
#define COIL_8_LAT                LATE2
#define COIL_8_PORT               RE2
#define COIL_8_ANS                ANSE2
#define COIL_8_SetHigh()    do { LATE2 = 1; } while(0)
#define COIL_8_SetLow()   do { LATE2 = 0; } while(0)
#define COIL_8_Toggle()   do { LATE2 = ~LATE2; } while(0)
#define COIL_8_GetValue()         RE2
#define COIL_8_SetDigitalInput()    do { TRISE2 = 1; } while(0)
#define COIL_8_SetDigitalOutput()   do { TRISE2 = 0; } while(0)

#define COIL_8_SetAnalogMode()   do { ANSE2 = 1; } while(0)
#define COIL_8_SetDigitalMode()   do { ANSE2 = 0; } while(0)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */