/************ OLED Display.h *********/

#ifndef OLED_H
#define	OLED_H

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define _XTAL_FREQ 16000000
#define OLED_RESET_PIN PORTDbits . RD2

#define bit_test(D,i) (D & (0x01 << i))

#define ARRAY_WIDHT 96 //
#define ARRAY_HEIGHT 2 //fonctionne plus ou moins ac 8
#define ARRAY_LENGHT ( 8 * ARRAY_HEIGHT )
#define SSD1306_GDDRAM ( ARRAY_WIDHT * ARRAY_HEIGHT / 8 )




#define WHITE 0x01
#define BLACK 0x00
#define FILL 0x01
#define NO_FILL 0x00
// 1. Fundamental Commands.
#define OLED_CONTRAST 0x81
#define OLED_DISPLAY_ALL_ON_RESUME 0xA4
#define OLED_DISPLAY_ALL_ON 0xA5
#define OLED_NORMAL_DISPLAY 0xA6
#define OLED_INVERTED_DISPLAY 0xA7
#define OLED_DISPLAY_OFF 0xAE
#define OLED_DISPLAY_ON 0xAF
// 2. Scrolling
#define OLED_RIGHT_HORIZONTAL_SCROLL 0x26
#define OLED_LEFT_HORIZONTAL_SCROLL 0x27
#define OLED_5_FRAMES 0x00
#define OLED_64_FRAMES 0x01
#define OLED_128_FRAMES 0x02
#define OLED_256_FRAMES 0x03
#define OLED_3_FRAMES 0x04
#define OLED_4_FRAMES 0x05
#define OLED_25_FRAMES 0x06
#define OLED_2_FRAMES 0x07
#define OLED_DUMMY_BYTE 0x00
#define OLED_VERTICAL_RIGHT 0x29
#define OLED_VERTICAL_LEFT 0x2A
#define OLED_DEACTIVATE_SCROLL 0x2E
#define OLED_ACTIVATE_SCROLL 0x2F
#define OLED_VERTICAL_SCROLL 0xA3

// 3. Addressing.
#define OLED_LOW_COLUMN_START 0x00
#define OLED_HIGH_COLUMN_START 0x10
#define OLED_MEMORY_MODE 0x20
#define OLED_HORIZONTAL_MODE 0x00
#define OLED_VERTICAL_MODE 0x01
#define OLED_PAGE_MODE 0x02
#define OLED_COLUMN_ADDRESS 0x21
#define OLED_PAGE_ADDRESS 0x22
#define OLED_PAGE_START 0xB0
// 4. Hardware Configuration.
#define OLED_SET_START_LINE 0x40
#define OLED_SEGMENT_REMAP 0xA0
#define OLED_SET_MULTIPLEX_RATIO 0xA8
#define OLED_COM_SCAN_INCREMENT 0xC0
#define OLED_COM_SCAN_DECREMENT 0xC8
#define OLED_DISPLAY_OFFSET 0xD3
#define OLED_SET_COM_PINS 0xDA
// 5. Timing.
#define OLED_DISPLAY_CLOCK_RATIO 0xD5
#define OLED_CLOCK_RESET_RATIO 0x80
#define OLED_SET_PRECHARGE 0xD9
#define OLED_PRECHARGE_RESET 0x22
#define OLED_PRECHARGE_P1_P2 0xF1
#define OLED_SET_VCOM_H 0xDB
#define OLED_VCC_RESET 0x20
// 6?. Other 
#define OLED_CHARGE_PUMP 0x8D
#define OLED_DISABLE_CHARGE 0x10
#define OLED_ENABLE_CHARGE 0x14

#define bitWise(n) ( 1 << n )
#define SIZE_ONE 0x01
#define SIZE_TWO 0x02
#define SIZE_THREE 0x03
#define DDGRAM_CLEAR 0x01
#define DDGRAM_NO_CLEAR 0x00

#define OLED_ADDRESS 0x3C
#define CLEAR 0x00

char OLEDSetUp ( void );
void OLEDCommand ( unsigned char c );
void OLEDPixel ( int x, int y, char color );
void OLEDCommandSend ( char reg, char data );
void OLEDData ( unsigned char c );
void OLEDFill ( unsigned char dat );
void OLEDUpdateDisplay ( unsigned char clear );
void OLEDClearBuffer ( void );
void OLEDInvertedDisplay ( unsigned char complement );
void testArray ( void );
void clearTest ( void );
void printArrayTest ( void );
void OLEDText ( int x, int y, char* textptr, int size, char color );


#endif