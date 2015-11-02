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
        Device            :  PIC16LF1947
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

// get/set IO_RA0 aliases
#define IO_RA0_TRIS               TRISA0
#define IO_RA0_LAT                LATA0
#define IO_RA0_PORT               RA0
#define IO_RA0_ANS                ANSA0
#define IO_RA0_SetHigh()    do { LATA0 = 1; } while(0)
#define IO_RA0_SetLow()   do { LATA0 = 0; } while(0)
#define IO_RA0_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define IO_RA0_GetValue()         RA0
#define IO_RA0_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define IO_RA0_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define IO_RA0_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define IO_RA0_SetDigitalMode()   do { ANSA0 = 0; } while(0)
// get/set IO_RA1 aliases
#define IO_RA1_TRIS               TRISA1
#define IO_RA1_LAT                LATA1
#define IO_RA1_PORT               RA1
#define IO_RA1_ANS                ANSA1
#define IO_RA1_SetHigh()    do { LATA1 = 1; } while(0)
#define IO_RA1_SetLow()   do { LATA1 = 0; } while(0)
#define IO_RA1_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define IO_RA1_GetValue()         RA1
#define IO_RA1_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define IO_RA1_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()   do { ANSA1 = 0; } while(0)
// get/set IO_RA2 aliases
#define IO_RA2_TRIS               TRISA2
#define IO_RA2_LAT                LATA2
#define IO_RA2_PORT               RA2
#define IO_RA2_ANS                ANSA2
#define IO_RA2_SetHigh()    do { LATA2 = 1; } while(0)
#define IO_RA2_SetLow()   do { LATA2 = 0; } while(0)
#define IO_RA2_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define IO_RA2_GetValue()         RA2
#define IO_RA2_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define IO_RA2_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set IO_RA3 aliases
#define IO_RA3_TRIS               TRISA3
#define IO_RA3_LAT                LATA3
#define IO_RA3_PORT               RA3
#define IO_RA3_ANS                ANSA3
#define IO_RA3_SetHigh()    do { LATA3 = 1; } while(0)
#define IO_RA3_SetLow()   do { LATA3 = 0; } while(0)
#define IO_RA3_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define IO_RA3_GetValue()         RA3
#define IO_RA3_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define IO_RA3_SetAnalogMode()   do { ANSA3 = 1; } while(0)
#define IO_RA3_SetDigitalMode()   do { ANSA3 = 0; } while(0)
// get/set IO_RA4 aliases
#define IO_RA4_TRIS               TRISA4
#define IO_RA4_LAT                LATA4
#define IO_RA4_PORT               RA4
#define IO_RA4_SetHigh()    do { LATA4 = 1; } while(0)
#define IO_RA4_SetLow()   do { LATA4 = 0; } while(0)
#define IO_RA4_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define IO_RA4_GetValue()         RA4
#define IO_RA4_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

// get/set IO_RA5 aliases
#define IO_RA5_TRIS               TRISA5
#define IO_RA5_LAT                LATA5
#define IO_RA5_PORT               RA5
#define IO_RA5_ANS                ANSA5
#define IO_RA5_SetHigh()    do { LATA5 = 1; } while(0)
#define IO_RA5_SetLow()   do { LATA5 = 0; } while(0)
#define IO_RA5_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define IO_RA5_GetValue()         RA5
#define IO_RA5_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define IO_RA5_SetAnalogMode()   do { ANSA5 = 1; } while(0)
#define IO_RA5_SetDigitalMode()   do { ANSA5 = 0; } while(0)
// get/set IO_RC0 aliases
#define IO_RC0_TRIS               TRISC0
#define IO_RC0_LAT                LATC0
#define IO_RC0_PORT               RC0
#define IO_RC0_SetHigh()    do { LATC0 = 1; } while(0)
#define IO_RC0_SetLow()   do { LATC0 = 0; } while(0)
#define IO_RC0_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define IO_RC0_GetValue()         RC0
#define IO_RC0_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISC1
#define IO_RC1_LAT                LATC1
#define IO_RC1_PORT               RC1
#define IO_RC1_SetHigh()    do { LATC1 = 1; } while(0)
#define IO_RC1_SetLow()   do { LATC1 = 0; } while(0)
#define IO_RC1_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define IO_RC1_GetValue()         RC1
#define IO_RC1_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS               TRISC3
#define SCL1_LAT                LATC3
#define SCL1_PORT               RC3
#define SCL1_SetHigh()    do { LATC3 = 1; } while(0)
#define SCL1_SetLow()   do { LATC3 = 0; } while(0)
#define SCL1_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define SCL1_GetValue()         RC3
#define SCL1_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS               TRISC4
#define SDA1_LAT                LATC4
#define SDA1_PORT               RC4
#define SDA1_SetHigh()    do { LATC4 = 1; } while(0)
#define SDA1_SetLow()   do { LATC4 = 0; } while(0)
#define SDA1_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define SDA1_GetValue()         RC4
#define SDA1_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS               TRISD0
#define IO_RD0_LAT                LATD0
#define IO_RD0_PORT               RD0
#define IO_RD0_SetHigh()    do { LATD0 = 1; } while(0)
#define IO_RD0_SetLow()   do { LATD0 = 0; } while(0)
#define IO_RD0_Toggle()   do { LATD0 = ~LATD0; } while(0)
#define IO_RD0_GetValue()         RD0
#define IO_RD0_SetDigitalInput()    do { TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RD1_TRIS               TRISD1
#define IO_RD1_LAT                LATD1
#define IO_RD1_PORT               RD1
#define IO_RD1_SetHigh()    do { LATD1 = 1; } while(0)
#define IO_RD1_SetLow()   do { LATD1 = 0; } while(0)
#define IO_RD1_Toggle()   do { LATD1 = ~LATD1; } while(0)
#define IO_RD1_GetValue()         RD1
#define IO_RD1_SetDigitalInput()    do { TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISD1 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_RD2_TRIS               TRISD2
#define IO_RD2_LAT                LATD2
#define IO_RD2_PORT               RD2
#define IO_RD2_SetHigh()    do { LATD2 = 1; } while(0)
#define IO_RD2_SetLow()   do { LATD2 = 0; } while(0)
#define IO_RD2_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define IO_RD2_GetValue()         RD2
#define IO_RD2_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISD2 = 0; } while(0)

// get/set IO_RD3 aliases
#define IO_RD3_TRIS               TRISD3
#define IO_RD3_LAT                LATD3
#define IO_RD3_PORT               RD3
#define IO_RD3_SetHigh()    do { LATD3 = 1; } while(0)
#define IO_RD3_SetLow()   do { LATD3 = 0; } while(0)
#define IO_RD3_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define IO_RD3_GetValue()         RD3
#define IO_RD3_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISD3 = 0; } while(0)

// get/set IO_RE0 aliases
#define IO_RE0_TRIS               TRISE0
#define IO_RE0_LAT                LATE0
#define IO_RE0_PORT               RE0
#define IO_RE0_ANS                ANSE0
#define IO_RE0_SetHigh()    do { LATE0 = 1; } while(0)
#define IO_RE0_SetLow()   do { LATE0 = 0; } while(0)
#define IO_RE0_Toggle()   do { LATE0 = ~LATE0; } while(0)
#define IO_RE0_GetValue()         RE0
#define IO_RE0_SetDigitalInput()    do { TRISE0 = 1; } while(0)
#define IO_RE0_SetDigitalOutput()   do { TRISE0 = 0; } while(0)

#define IO_RE0_SetAnalogMode()   do { ANSE0 = 1; } while(0)
#define IO_RE0_SetDigitalMode()   do { ANSE0 = 0; } while(0)
// get/set IO_RE1 aliases
#define IO_RE1_TRIS               TRISE1
#define IO_RE1_LAT                LATE1
#define IO_RE1_PORT               RE1
#define IO_RE1_ANS                ANSE1
#define IO_RE1_SetHigh()    do { LATE1 = 1; } while(0)
#define IO_RE1_SetLow()   do { LATE1 = 0; } while(0)
#define IO_RE1_Toggle()   do { LATE1 = ~LATE1; } while(0)
#define IO_RE1_GetValue()         RE1
#define IO_RE1_SetDigitalInput()    do { TRISE1 = 1; } while(0)
#define IO_RE1_SetDigitalOutput()   do { TRISE1 = 0; } while(0)

#define IO_RE1_SetAnalogMode()   do { ANSE1 = 1; } while(0)
#define IO_RE1_SetDigitalMode()   do { ANSE1 = 0; } while(0)
// get/set IO_RE2 aliases
#define IO_RE2_TRIS               TRISE2
#define IO_RE2_LAT                LATE2
#define IO_RE2_PORT               RE2
#define IO_RE2_ANS                ANSE2
#define IO_RE2_SetHigh()    do { LATE2 = 1; } while(0)
#define IO_RE2_SetLow()   do { LATE2 = 0; } while(0)
#define IO_RE2_Toggle()   do { LATE2 = ~LATE2; } while(0)
#define IO_RE2_GetValue()         RE2
#define IO_RE2_SetDigitalInput()    do { TRISE2 = 1; } while(0)
#define IO_RE2_SetDigitalOutput()   do { TRISE2 = 0; } while(0)

#define IO_RE2_SetAnalogMode()   do { ANSE2 = 1; } while(0)
#define IO_RE2_SetDigitalMode()   do { ANSE2 = 0; } while(0)
// get/set IO_RE3 aliases
#define IO_RE3_TRIS               TRISE3
#define IO_RE3_LAT                LATE3
#define IO_RE3_PORT               RE3
#define IO_RE3_SetHigh()    do { LATE3 = 1; } while(0)
#define IO_RE3_SetLow()   do { LATE3 = 0; } while(0)
#define IO_RE3_Toggle()   do { LATE3 = ~LATE3; } while(0)
#define IO_RE3_GetValue()         RE3
#define IO_RE3_SetDigitalInput()    do { TRISE3 = 1; } while(0)
#define IO_RE3_SetDigitalOutput()   do { TRISE3 = 0; } while(0)

// get/set IO_RE4 aliases
#define IO_RE4_TRIS               TRISE4
#define IO_RE4_LAT                LATE4
#define IO_RE4_PORT               RE4
#define IO_RE4_SetHigh()    do { LATE4 = 1; } while(0)
#define IO_RE4_SetLow()   do { LATE4 = 0; } while(0)
#define IO_RE4_Toggle()   do { LATE4 = ~LATE4; } while(0)
#define IO_RE4_GetValue()         RE4
#define IO_RE4_SetDigitalInput()    do { TRISE4 = 1; } while(0)
#define IO_RE4_SetDigitalOutput()   do { TRISE4 = 0; } while(0)

// get/set IO_RE5 aliases
#define IO_RE5_TRIS               TRISE5
#define IO_RE5_LAT                LATE5
#define IO_RE5_PORT               RE5
#define IO_RE5_SetHigh()    do { LATE5 = 1; } while(0)
#define IO_RE5_SetLow()   do { LATE5 = 0; } while(0)
#define IO_RE5_Toggle()   do { LATE5 = ~LATE5; } while(0)
#define IO_RE5_GetValue()         RE5
#define IO_RE5_SetDigitalInput()    do { TRISE5 = 1; } while(0)
#define IO_RE5_SetDigitalOutput()   do { TRISE5 = 0; } while(0)

// get/set IO_RE6 aliases
#define IO_RE6_TRIS               TRISE6
#define IO_RE6_LAT                LATE6
#define IO_RE6_PORT               RE6
#define IO_RE6_SetHigh()    do { LATE6 = 1; } while(0)
#define IO_RE6_SetLow()   do { LATE6 = 0; } while(0)
#define IO_RE6_Toggle()   do { LATE6 = ~LATE6; } while(0)
#define IO_RE6_GetValue()         RE6
#define IO_RE6_SetDigitalInput()    do { TRISE6 = 1; } while(0)
#define IO_RE6_SetDigitalOutput()   do { TRISE6 = 0; } while(0)

// get/set IO_RE7 aliases
#define IO_RE7_TRIS               TRISE7
#define IO_RE7_LAT                LATE7
#define IO_RE7_PORT               RE7
#define IO_RE7_SetHigh()    do { LATE7 = 1; } while(0)
#define IO_RE7_SetLow()   do { LATE7 = 0; } while(0)
#define IO_RE7_Toggle()   do { LATE7 = ~LATE7; } while(0)
#define IO_RE7_GetValue()         RE7
#define IO_RE7_SetDigitalInput()    do { TRISE7 = 1; } while(0)
#define IO_RE7_SetDigitalOutput()   do { TRISE7 = 0; } while(0)

// get/set IO_RF0 aliases
#define IO_RF0_TRIS               TRISF0
#define IO_RF0_LAT                LATF0
#define IO_RF0_PORT               RF0
#define IO_RF0_ANS                ANSF0
#define IO_RF0_SetHigh()    do { LATF0 = 1; } while(0)
#define IO_RF0_SetLow()   do { LATF0 = 0; } while(0)
#define IO_RF0_Toggle()   do { LATF0 = ~LATF0; } while(0)
#define IO_RF0_GetValue()         RF0
#define IO_RF0_SetDigitalInput()    do { TRISF0 = 1; } while(0)
#define IO_RF0_SetDigitalOutput()   do { TRISF0 = 0; } while(0)

#define IO_RF0_SetAnalogMode()   do { ANSF0 = 1; } while(0)
#define IO_RF0_SetDigitalMode()   do { ANSF0 = 0; } while(0)
// get/set IO_RF1 aliases
#define IO_RF1_TRIS               TRISF1
#define IO_RF1_LAT                LATF1
#define IO_RF1_PORT               RF1
#define IO_RF1_ANS                ANSF1
#define IO_RF1_SetHigh()    do { LATF1 = 1; } while(0)
#define IO_RF1_SetLow()   do { LATF1 = 0; } while(0)
#define IO_RF1_Toggle()   do { LATF1 = ~LATF1; } while(0)
#define IO_RF1_GetValue()         RF1
#define IO_RF1_SetDigitalInput()    do { TRISF1 = 1; } while(0)
#define IO_RF1_SetDigitalOutput()   do { TRISF1 = 0; } while(0)

#define IO_RF1_SetAnalogMode()   do { ANSF1 = 1; } while(0)
#define IO_RF1_SetDigitalMode()   do { ANSF1 = 0; } while(0)
// get/set IO_RF2 aliases
#define IO_RF2_TRIS               TRISF2
#define IO_RF2_LAT                LATF2
#define IO_RF2_PORT               RF2
#define IO_RF2_ANS                ANSF2
#define IO_RF2_SetHigh()    do { LATF2 = 1; } while(0)
#define IO_RF2_SetLow()   do { LATF2 = 0; } while(0)
#define IO_RF2_Toggle()   do { LATF2 = ~LATF2; } while(0)
#define IO_RF2_GetValue()         RF2
#define IO_RF2_SetDigitalInput()    do { TRISF2 = 1; } while(0)
#define IO_RF2_SetDigitalOutput()   do { TRISF2 = 0; } while(0)

#define IO_RF2_SetAnalogMode()   do { ANSF2 = 1; } while(0)
#define IO_RF2_SetDigitalMode()   do { ANSF2 = 0; } while(0)
// get/set IO_RF3 aliases
#define IO_RF3_TRIS               TRISF3
#define IO_RF3_LAT                LATF3
#define IO_RF3_PORT               RF3
#define IO_RF3_ANS                ANSF3
#define IO_RF3_SetHigh()    do { LATF3 = 1; } while(0)
#define IO_RF3_SetLow()   do { LATF3 = 0; } while(0)
#define IO_RF3_Toggle()   do { LATF3 = ~LATF3; } while(0)
#define IO_RF3_GetValue()         RF3
#define IO_RF3_SetDigitalInput()    do { TRISF3 = 1; } while(0)
#define IO_RF3_SetDigitalOutput()   do { TRISF3 = 0; } while(0)

#define IO_RF3_SetAnalogMode()   do { ANSF3 = 1; } while(0)
#define IO_RF3_SetDigitalMode()   do { ANSF3 = 0; } while(0)
// get/set IO_RF4 aliases
#define IO_RF4_TRIS               TRISF4
#define IO_RF4_LAT                LATF4
#define IO_RF4_PORT               RF4
#define IO_RF4_ANS                ANSF4
#define IO_RF4_SetHigh()    do { LATF4 = 1; } while(0)
#define IO_RF4_SetLow()   do { LATF4 = 0; } while(0)
#define IO_RF4_Toggle()   do { LATF4 = ~LATF4; } while(0)
#define IO_RF4_GetValue()         RF4
#define IO_RF4_SetDigitalInput()    do { TRISF4 = 1; } while(0)
#define IO_RF4_SetDigitalOutput()   do { TRISF4 = 0; } while(0)

#define IO_RF4_SetAnalogMode()   do { ANSF4 = 1; } while(0)
#define IO_RF4_SetDigitalMode()   do { ANSF4 = 0; } while(0)
// get/set IO_RF5 aliases
#define IO_RF5_TRIS               TRISF5
#define IO_RF5_LAT                LATF5
#define IO_RF5_PORT               RF5
#define IO_RF5_ANS                ANSF5
#define IO_RF5_SetHigh()    do { LATF5 = 1; } while(0)
#define IO_RF5_SetLow()   do { LATF5 = 0; } while(0)
#define IO_RF5_Toggle()   do { LATF5 = ~LATF5; } while(0)
#define IO_RF5_GetValue()         RF5
#define IO_RF5_SetDigitalInput()    do { TRISF5 = 1; } while(0)
#define IO_RF5_SetDigitalOutput()   do { TRISF5 = 0; } while(0)

#define IO_RF5_SetAnalogMode()   do { ANSF5 = 1; } while(0)
#define IO_RF5_SetDigitalMode()   do { ANSF5 = 0; } while(0)
// get/set IO_RF6 aliases
#define IO_RF6_TRIS               TRISF6
#define IO_RF6_LAT                LATF6
#define IO_RF6_PORT               RF6
#define IO_RF6_ANS                ANSF6
#define IO_RF6_SetHigh()    do { LATF6 = 1; } while(0)
#define IO_RF6_SetLow()   do { LATF6 = 0; } while(0)
#define IO_RF6_Toggle()   do { LATF6 = ~LATF6; } while(0)
#define IO_RF6_GetValue()         RF6
#define IO_RF6_SetDigitalInput()    do { TRISF6 = 1; } while(0)
#define IO_RF6_SetDigitalOutput()   do { TRISF6 = 0; } while(0)

#define IO_RF6_SetAnalogMode()   do { ANSF6 = 1; } while(0)
#define IO_RF6_SetDigitalMode()   do { ANSF6 = 0; } while(0)
// get/set IO_RF7 aliases
#define IO_RF7_TRIS               TRISF7
#define IO_RF7_LAT                LATF7
#define IO_RF7_PORT               RF7
#define IO_RF7_ANS                ANSF7
#define IO_RF7_SetHigh()    do { LATF7 = 1; } while(0)
#define IO_RF7_SetLow()   do { LATF7 = 0; } while(0)
#define IO_RF7_Toggle()   do { LATF7 = ~LATF7; } while(0)
#define IO_RF7_GetValue()         RF7
#define IO_RF7_SetDigitalInput()    do { TRISF7 = 1; } while(0)
#define IO_RF7_SetDigitalOutput()   do { TRISF7 = 0; } while(0)

#define IO_RF7_SetAnalogMode()   do { ANSF7 = 1; } while(0)
#define IO_RF7_SetDigitalMode()   do { ANSF7 = 0; } while(0)
// get/set IO_RG0 aliases
#define IO_RG0_TRIS               TRISG0
#define IO_RG0_LAT                LATG0
#define IO_RG0_PORT               RG0
#define IO_RG0_SetHigh()    do { LATG0 = 1; } while(0)
#define IO_RG0_SetLow()   do { LATG0 = 0; } while(0)
#define IO_RG0_Toggle()   do { LATG0 = ~LATG0; } while(0)
#define IO_RG0_GetValue()         RG0
#define IO_RG0_SetDigitalInput()    do { TRISG0 = 1; } while(0)
#define IO_RG0_SetDigitalOutput()   do { TRISG0 = 0; } while(0)

// get/set IO_RG1 aliases
#define IO_RG1_TRIS               TRISG1
#define IO_RG1_LAT                LATG1
#define IO_RG1_PORT               RG1
#define IO_RG1_ANS                ANSG1
#define IO_RG1_SetHigh()    do { LATG1 = 1; } while(0)
#define IO_RG1_SetLow()   do { LATG1 = 0; } while(0)
#define IO_RG1_Toggle()   do { LATG1 = ~LATG1; } while(0)
#define IO_RG1_GetValue()         RG1
#define IO_RG1_SetDigitalInput()    do { TRISG1 = 1; } while(0)
#define IO_RG1_SetDigitalOutput()   do { TRISG1 = 0; } while(0)

#define IO_RG1_SetAnalogMode()   do { ANSG1 = 1; } while(0)
#define IO_RG1_SetDigitalMode()   do { ANSG1 = 0; } while(0)
// get/set IO_RG2 aliases
#define IO_RG2_TRIS               TRISG2
#define IO_RG2_LAT                LATG2
#define IO_RG2_PORT               RG2
#define IO_RG2_ANS                ANSG2
#define IO_RG2_SetHigh()    do { LATG2 = 1; } while(0)
#define IO_RG2_SetLow()   do { LATG2 = 0; } while(0)
#define IO_RG2_Toggle()   do { LATG2 = ~LATG2; } while(0)
#define IO_RG2_GetValue()         RG2
#define IO_RG2_SetDigitalInput()    do { TRISG2 = 1; } while(0)
#define IO_RG2_SetDigitalOutput()   do { TRISG2 = 0; } while(0)

#define IO_RG2_SetAnalogMode()   do { ANSG2 = 1; } while(0)
#define IO_RG2_SetDigitalMode()   do { ANSG2 = 0; } while(0)
// get/set IO_RG3 aliases
#define IO_RG3_TRIS               TRISG3
#define IO_RG3_LAT                LATG3
#define IO_RG3_PORT               RG3
#define IO_RG3_ANS                ANSG3
#define IO_RG3_SetHigh()    do { LATG3 = 1; } while(0)
#define IO_RG3_SetLow()   do { LATG3 = 0; } while(0)
#define IO_RG3_Toggle()   do { LATG3 = ~LATG3; } while(0)
#define IO_RG3_GetValue()         RG3
#define IO_RG3_SetDigitalInput()    do { TRISG3 = 1; } while(0)
#define IO_RG3_SetDigitalOutput()   do { TRISG3 = 0; } while(0)

#define IO_RG3_SetAnalogMode()   do { ANSG3 = 1; } while(0)
#define IO_RG3_SetDigitalMode()   do { ANSG3 = 0; } while(0)

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