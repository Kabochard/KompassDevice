#ifndef OLED_H
#define	OLED_H


#include <xc.h>
/************ OLED Display.h *********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "i2c.h"

#define _XTAL_FREQ 16000000
#define OLED_RESET_PIN PORTDbits . RD2

#define bit_test(D,i) (D & (0x01 << i))

#define ARRAY_WIDHT 96 //
#define ARRAY_HEIGHT 2 //fonctionne plus ou moins ac 8
#define ARRAY_LENGHT ( 8 * ARRAY_HEIGHT )
#define SSD1306_GDDRAM ( ARRAY_WIDHT * ARRAY_HEIGHT / 8 )

unsigned char TEST [2][96];


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
void OLEDLine ( unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, char color );
void OLEDRectangular ( unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, char color );
void OLEDCircle ( int x, int y, int radius, char fill, char color );
void OLEDBar ( int x1, int y1, int x2, int y2, int width, char color );
void OLEDAreaFill ( unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, char color );
void OLEDText ( int x, int y, char* textptr, int size, char color );

void ODOpaste(char digit);
void ODOScroll_units(unsigned int position);
void ODOScroll_tens(unsigned int position);

const char TEXT[51][5] = 
{0x00, 0x00, 0x00, 0x00, 0x00, // SPACE
0x00, 0x00, 0x5F, 0x00, 0x00, // !
0x00, 0x03, 0x00, 0x03, 0x00, // "
0x14, 0x3E, 0x14, 0x3E, 0x14, // #
0x24, 0x2A, 0x7F, 0x2A, 0x12, // $
0x43, 0x33, 0x08, 0x66, 0x61, // %
0x36, 0x49, 0x55, 0x22, 0x50, // &
0x00, 0x05, 0x03, 0x00, 0x00, // '
0x00, 0x1C, 0x22, 0x41, 0x00, // (
0x00, 0x41, 0x22, 0x1C, 0x00, // )
0x14, 0x08, 0x3E, 0x08, 0x14, // *
0x08, 0x08, 0x3E, 0x08, 0x08, // +
0x00, 0x50, 0x30, 0x00, 0x00, // ,
0x08, 0x08, 0x08, 0x08, 0x08, // -
0x00, 0x60, 0x60, 0x00, 0x00, // .
0x20, 0x10, 0x08, 0x04, 0x02, // /
0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
0x04, 0x02, 0x7F, 0x00, 0x00, // 1
0x42, 0x61, 0x51, 0x49, 0x46, // 2
0x22, 0x41, 0x49, 0x49, 0x36, // 3
0x18, 0x14, 0x12, 0x7F, 0x10, // 4
0x27, 0x45, 0x45, 0x45, 0x39, // 5
0x3E, 0x49, 0x49, 0x49, 0x32, // 6
0x01, 0x01, 0x71, 0x09, 0x07, // 7
0x36, 0x49, 0x49, 0x49, 0x36, // 8
0x26, 0x49, 0x49, 0x49, 0x3E, // 9
0x00, 0x36, 0x36, 0x00, 0x00, // :
0x00, 0x56, 0x36, 0x00, 0x00, // ;
0x08, 0x14, 0x22, 0x41, 0x00, // <
0x14, 0x14, 0x14, 0x14, 0x14, // =
0x00, 0x41, 0x22, 0x14, 0x08, // >
0x02, 0x01, 0x51, 0x09, 0x06, // ?
0x3E, 0x41, 0x59, 0x55, 0x5E, // @
0x7E, 0x09, 0x09, 0x09, 0x7E, // A
0x7F, 0x49, 0x49, 0x49, 0x36, // B
0x3E, 0x41, 0x41, 0x41, 0x22, // C
0x7F, 0x41, 0x41, 0x41, 0x3E, // D
0x7F, 0x49, 0x49, 0x49, 0x41, // E
0x7F, 0x09, 0x09, 0x09, 0x01, // F
0x3E, 0x41, 0x41, 0x49, 0x3A, // G
0x7F, 0x08, 0x08, 0x08, 0x7F, // H
0x00, 0x41, 0x7F, 0x41, 0x00, // I
0x30, 0x40, 0x40, 0x40, 0x3F, // J
0x7F, 0x08, 0x14, 0x22, 0x41, // K
0x7F, 0x40, 0x40, 0x40, 0x40, // L
0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
0x7F, 0x02, 0x04, 0x08, 0x7F, // N
0x3E, 0x41, 0x41, 0x41, 0x3E, // O
0x7F, 0x09, 0x09, 0x09, 0x06, // P
0x1E, 0x21, 0x21, 0x21, 0x5E, // Q
0x7F, 0x09, 0x09, 0x09, 0x76};// R
const char TEXT2[44][5]={0x26, 0x49, 0x49, 0x49, 0x32, // S
0x01, 0x01, 0x7F, 0x01, 0x01, // T
0x3F, 0x40, 0x40, 0x40, 0x3F, // U
0x1F, 0x20, 0x40, 0x20, 0x1F, // V
0x7F, 0x20, 0x10, 0x20, 0x7F, // W
0x41, 0x22, 0x1C, 0x22, 0x41, // X
0x07, 0x08, 0x70, 0x08, 0x07, // Y
0x61, 0x51, 0x49, 0x45, 0x43, // Z
0x00, 0x7F, 0x41, 0x00, 0x00, // [
0x02, 0x04, 0x08, 0x10, 0x20, // \
0x00, 0x00, 0x41, 0x7F, 0x00, // ]
0x04, 0x02, 0x01, 0x02, 0x04, // ^
0x40, 0x40, 0x40, 0x40, 0x40, // _
0x00, 0x01, 0x02, 0x04, 0x00, // `
0x20, 0x54, 0x54, 0x54, 0x78, // a
0x7F, 0x44, 0x44, 0x44, 0x38, // b
0x38, 0x44, 0x44, 0x44, 0x44, // c
0x38, 0x44, 0x44, 0x44, 0x7F, // d
0x38, 0x54, 0x54, 0x54, 0x18, // e
0x04, 0x04, 0x7E, 0x05, 0x05, // f
0x08, 0x54, 0x54, 0x54, 0x3C, // g
0x7F, 0x08, 0x04, 0x04, 0x78, // h
0x00, 0x44, 0x7D, 0x40, 0x00, // i
0x20, 0x40, 0x44, 0x3D, 0x00, // j
0x7F, 0x10, 0x28, 0x44, 0x00, // k
0x00, 0x41, 0x7F, 0x40, 0x00, // l
0x7C, 0x04, 0x78, 0x04, 0x78, // m
0x7C, 0x08, 0x04, 0x04, 0x78, // n
0x38, 0x44, 0x44, 0x44, 0x38, // o
0x7C, 0x14, 0x14, 0x14, 0x08, // p
0x08, 0x14, 0x14, 0x14, 0x7C, // q
0x00, 0x7C, 0x08, 0x04, 0x04, // r
0x48, 0x54, 0x54, 0x54, 0x20, // s
0x04, 0x04, 0x3F, 0x44, 0x44, // t
0x3C, 0x40, 0x40, 0x20, 0x7C, // u
0x1C, 0x20, 0x40, 0x20, 0x1C, // v
0x3C, 0x40, 0x30, 0x40, 0x3C, // w
0x44, 0x28, 0x10, 0x28, 0x44, // x
0x0C, 0x50, 0x50, 0x50, 0x3C, // y
0x44, 0x64, 0x54, 0x4C, 0x44, // z
0x00, 0x08, 0x36, 0x41, 0x41, // {
0x00, 0x00, 0x7F, 0x00, 0x00, // |
0x41, 0x41, 0x36, 0x08, 0x00, // }
0x02, 0x01, 0x02, 0x04, 0x02};// ~


const char ODOFonts[12][26]={
  	0xE0,0xFC,0xFE,0xFF,0x1F,0x0F,0x0F,0x1F,0xFF,0xFE,0xFC,0xE0,
 	0x03,0x1F,0x3F,0x7F,0x7C,0x78,0x78,0x7C,0x7F,0x3F,0x1F,0x03,
 	0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xF8,0xF8,0xF8,0x00,0x00,0x00,
 	0x01,0x01,0x01,0x00,0x80,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,
 	0x00,0x80,0xC2,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0x83,0x02,
 	0x07,0x07,0x07,0x03,0x81,0xC1,0xE1,0xF3,0x7F,0x3F,0x1F,0x0E,
 	0x18,0x1C,0x1E,0x1F,0x1F,0x1F,0x1D,0x1C,0x1C,0x1C,0x1C,0x1C,
 	0x00,0x38,0x3C,0x3E,0x1E,0x8E,0x8E,0xDE,0xFE,0xFC,0x7C,0x30,
 	0x18,0x38,0x78,0xF8,0xF0,0xE3,0xE3,0xF7,0xFF,0xFF,0x7E,0x1C,
 	0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF0,0xF0,0x00,
 	0xF0,0xF8,0xFC,0xFE,0xEF,0xE7,0xE3,0xE1,0xFF,0xFF,0xFF,0xE0,
 	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x87,0x87,0x87,0x00,
 	0x7F,0x7F,0x7F,0x73,0x73,0x33,0x33,0x73,0xF3,0xF3,0xE3,0x80,
 	0x06,0x0E,0x1E,0x1C,0x3C,0x38,0x38,0x3C,0x1E,0x1F,0x0F,0x03,
 	0xC0,0xF0,0xF8,0xFC,0x3C,0x9C,0x9C,0x9C,0x9C,0x3C,0x38,0x30,
 	0x1F,0x7F,0xFF,0xFF,0xE7,0xC3,0xC3,0xC3,0xE7,0xFF,0xFF,0x7C,
 	0xE0,0xE0,0xE0,0xE0,0xE1,0xE1,0xE1,0xE1,0xE1,0xE0,0xE0,0xE0,
 	0x00,0x00,0x00,0x80,0xE0,0xF8,0xFE,0x7F,0x0F,0x03,0x01,0x00,
 	0x00,0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,
 	0x00,0x3C,0xFE,0xFF,0xEF,0xC7,0xC7,0xEF,0xFF,0xFE,0x3C,0x00,
 	0x0C,0x1F,0x3F,0x7F,0x7B,0x71,0x71,0x7B,0x7F,0x3F,0x1F,0x0C,
 	0xC0,0xE0,0xF0,0xF8,0x78,0x38,0x38,0x78,0xF0,0xF0,0xE0,0x80,
 	0xC3,0xCF,0xDF,0xDF,0x9E,0x9C,0x9C,0xCE,0xFF,0xFF,0xFF,0x1F,
 	0x00,0x01,0x83,0xC3,0xC3,0xC3,0xC3,0xC3,0xC1,0x81,0x00,0x00,
 	0xF8,0xFF,0xFF,0xFF,0x07,0x03,0x03,0x07,0xFF,0xFF,0xFF,0xF8,
 	0x00,0x07,0x0F,0x1F,0x1F,0x1E,0x1E,0x1F,0x1F,0x0F,0x07,0x00,
};

 char OLEDSetUp ( void )
{
	__delay_ms ( 1 );				// As OLDE VDD goes high sooner than VCC,
	OLED_RESET_PIN = 0;			// we must wait to stabilize VCC
	__delay_ms ( 1 );				// OLED Reset pin.
	OLED_RESET_PIN = 1;			

// 1. Fundamental Commands.
	OLEDCommand ( OLED_CONTRAST );				// 0x81
	OLEDCommand ( 0x4F );						// was 0x9F. ******
	OLEDCommand ( OLED_DISPLAY_ALL_ON_RESUME );	// 0xA5
	OLEDCommand ( OLED_NORMAL_DISPLAY );		// 0xA6
	OLEDCommand ( OLED_DISPLAY_ON );			// 0xAF

// 2. Scrolling.

// 3. Addressing.
	OLEDCommand ( OLED_MEMORY_MODE );			// 0x20
	OLEDCommand ( OLED_HORIZONTAL_MODE );
		
// 4. Hardware Configuration.
	OLEDCommand ( OLED_SET_START_LINE | 0x00 );	// line #0
	OLEDCommand ( OLED_SEGMENT_REMAP | 0x01 );	// WTF???
	OLEDCommand ( OLED_SET_MULTIPLEX_RATIO );	// 0xA8
	OLEDCommand ( 0x0F );
	OLEDCommand ( OLED_COM_SCAN_DECREMENT );	// WTF???
	OLEDCommand ( OLED_DISPLAY_OFFSET );		// 0xD3
	OLEDCommand ( 0x0 );						// no offset
	OLEDCommand ( OLED_SET_COM_PINS );			// 0xDA
	OLEDCommand ( 0x2 ); //was 0x12

// 5. Timing.
	OLEDCommand ( OLED_DISPLAY_CLOCK_RATIO );	// 0xD5
	OLEDCommand ( OLED_CLOCK_RESET_RATIO );
	OLEDCommand ( OLED_SET_PRECHARGE );			// 0xd9
	OLEDCommand ( OLED_PRECHARGE_P1_P2 );		// 0xF1
	OLEDCommand ( OLED_SET_VCOM_H );			// 0xDB
	OLEDCommand ( 0x40 );						// WTF???

// 6?. Other 
	OLEDCommand ( OLED_CHARGE_PUMP );			// 0x8D
	OLEDCommand ( OLED_ENABLE_CHARGE );			// 0x14

	
	return 0x00;
	}
	
	
void OLEDCommand ( unsigned char c )
{
	unsigned char command = 0x00;	// Co = 0, D/C=0, followed by 00 0000.
	
	i2c_Start ( );
	i2c_Address ( OLED_ADDRESS, I2C_WRITE );
	i2c_Write ( command );
	i2c_Write ( c );
	i2c_Stop ( );
	}
	

/********** prints out the Data to the GLCD ********/
void OLEDData ( unsigned char c ) 
{
	unsigned char control = 0x40;   // Co = 0, D/C = 1

	i2c_Start ( );
	i2c_Address ( OLED_ADDRESS, I2C_WRITE );
	i2c_Write ( control );
	i2c_Write ( c );
	i2c_Stop ( );
	}


/********** prints out a pixel on the GLCD ********/
void OLEDPixel ( int x, int y, char color )
{
	unsigned char *ptr;
	unsigned char page;
	unsigned int axisX;
	unsigned int axisY;
	signed char bitNumber, bitPlace;
	unsigned int address;


	if ( ( x < ARRAY_WIDHT && y <= ARRAY_LENGHT ) && 
		( x >= 0x00 && y >= 0x00 ) )
	{
		axisY = y / 8;							// Getting the row value.
		axisX = x;								// Getting the column value.
		page = abs ( axisY );					// Getting the Page number.
		bitNumber = ( y % 8 );					// Getting the bit value on the column.
		
/*		printf ( " \nX:%d, seg#:%d", x, axisX );
		printf ( " \nY:%d, PAGE:%d", y, page );
		printf ( " \nbit #:%d", bitNumber );
*/
		int temp;
		temp =  y / 8;
		temp *= ARRAY_WIDHT;
		temp += x;
		ptr = ( char * ) TEST;

	// Set Column Address.
		OLEDCommand ( OLED_COLUMN_ADDRESS );		
		OLEDCommand ( axisX );					// Column start address.
		OLEDCommand ( axisX );					// Column end address.
	// Set Page Address.
		OLEDCommand ( OLED_PAGE_ADDRESS );		
		OLEDCommand ( page );					// Page start Address.
		OLEDCommand ( page );					// Page end Address.
		
		if ( color )	// bitSet ( x, x ) equivalent.
//			OLEDData ( *( ptr + temp ) |=  ( bitWise ( y % 8 ) ) );
			*( ptr + temp ) |=  ( bitWise ( y % 8 ) );

		else			// bitClear ( x, x ) equivalent.	
//			OLEDData ( *( ptr + temp ) &=  ~( bitWise ( y % 8 ) ) );
			*( ptr + temp ) &=  ~( bitWise ( y % 8 ) );

		}	// If the axies are whithin the OLED margin.
	}	// test Pixel.	



/********** prints out the 'color' Data to the GLCD ********/
void OLEDFill ( unsigned char color )
{
//	OLEDClearBuffer ( );

	unsigned char *ptr;
	unsigned char i, j;

	ptr = ( char * ) TEST;

	for ( unsigned int i = 0x00; i < ARRAY_HEIGHT; i++ )
		for ( unsigned int j = 0x00; j < ARRAY_WIDHT; j++ )
			*( ptr + ( j + i * ARRAY_WIDHT ) ) = color;


// Set the Display with the 'color' Data.
	OLEDCommand ( OLED_LOW_COLUMN_START );		//set lower column address.
	OLEDCommand ( OLED_HIGH_COLUMN_START );		//set higher column address.
	OLEDCommand ( OLED_PAGE_START );			//set page address.

	for ( j = 0x00; j < ARRAY_HEIGHT; j++ )
	{
		OLEDCommand ( OLED_LOW_COLUMN_START );	//set lower column address.
		OLEDCommand ( OLED_HIGH_COLUMN_START );	//set higher column address.
		OLEDCommand ( OLED_PAGE_START + j );	//set page address.
		
		for ( i = 0x00; i < ARRAY_WIDHT; i++ )
			OLEDData ( *( ptr + ( j + i * ARRAY_WIDHT ) ) = color );
//			OLEDData ( color );
		}	// Printing out the rows an then the columns.

	}	// OLEDFill ( ).


void OLEDClearBuffer ( void )
{
	unsigned char *ptr;
	unsigned char ColumnAddress, PageAddress;

	ptr = ( char * ) TEST;

	for ( PageAddress = 0x00; PageAddress < ARRAY_HEIGHT; PageAddress++ )
		for ( ColumnAddress = 0x00; ColumnAddress < ARRAY_WIDHT; ColumnAddress++ )
			*( ptr + ( ColumnAddress + PageAddress * ARRAY_WIDHT ) ) = CLEAR;
	
	}	




void OLEDUpdateDisplay ( unsigned char clear )
{
	unsigned char ColumnAddress, PageAddress;
	unsigned char *ptr;
	
	ptr = ( char * ) TEST;

// Set Page Address.
	OLEDCommand ( OLED_PAGE_ADDRESS );		
	OLEDCommand ( 0x00 );					// Page start Address.
	OLEDCommand ( 0x07 );					// Page end Address.

// Set Column Address.
	OLEDCommand ( OLED_COLUMN_ADDRESS );		
	OLEDCommand ( 0x00 );					// Column start address.
	OLEDCommand ( 0x7F );					// Column end address.

	for ( PageAddress = 0x00; PageAddress < ARRAY_HEIGHT; PageAddress++ )	
	{
// Set Page Address.
		OLEDCommand ( OLED_PAGE_ADDRESS );		
		OLEDCommand ( 0x00 + PageAddress );	// Page start Address.
		OLEDCommand ( 0x07 );				// Page end Address.
// Set Column Address.
		OLEDCommand ( OLED_COLUMN_ADDRESS );		
		OLEDCommand ( 0x00 );			// Column start address.
		OLEDCommand ( 0x7F );			// Column end address.

		i2c_Start ( );
		i2c_Address ( OLED_ADDRESS, I2C_WRITE );
		i2c_Write ( OLED_SET_START_LINE );
		for ( ColumnAddress = 0x00; ColumnAddress < ARRAY_WIDHT; ColumnAddress++ )
			i2c_Write ( *( ptr + ( ( PageAddress * ARRAY_WIDHT) + ColumnAddress ) ) );
		i2c_Stop ( );
		}	// Printing out the rows an then the columns.

	if ( clear )				// if erased DDRAM wanted on every Update.
		OLEDClearBuffer ( );
	
	}	// OLEDUpdateDisplay.


	
/********** prints out on the UART PORT the Arrays ********/
/********** For Testing Purposes ********/
void printArrayTest ( void )
{
	for ( unsigned char i = 0; i < ARRAY_HEIGHT; i++ )	
	{
		printf ( "\n" );
		for ( unsigned char j = 0; j < ARRAY_WIDHT; j++ )
			printf ( "[%2X]", TEST [ i ] [ j ] );
		}		
	printf ( "\n" );
	}



void OLEDInvertedDisplay ( unsigned char complement )
{
	if ( complement )
		OLEDCommand ( OLED_INVERTED_DISPLAY );
	else
		OLEDCommand ( OLED_NORMAL_DISPLAY );
	}	
	
	
	
void OLEDLine ( unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, char color )
{
	int  x, y, addx, addy, dx, dy;
	int P;
	int i;

	dx = abs ( ( int ) ( x2 - x1 ) );
	dy = abs ( ( int ) ( y2 - y1 ) );
	x = x1;
	y = y1;

	if ( x1 > x2 )
		addx = -1;
	else
		addx = 1;
	
	if ( y1 > y2 )
		addy = -1;
	else
		addy = 1;

	if ( dx >= dy )
	{
		P = 2 * dy - dx;

		for ( i = 0; i <= dx; ++i )
		{
			OLEDPixel ( x, y, color );

			if ( P < 0 )
			{
				P += 2 * dy;
				x += addx;
				}
			else
			{
				P += 2 * dy - 2 * dx;
				x += addx;
				y += addy;
				}
			}
		}
	else
	{
		P = 2 * dx - dy;

		for ( i = 0; i <= dy; ++i )
		{
			OLEDPixel ( x, y, color );

			if ( P < 0 )
			{
				P += 2 * dx;
				y += addy;
				}
			else
			{
				P += 2 * dx - 2 * dy;
				x += addx;
				y += addy;
				}
			}
		}
	}


void OLEDRectangular ( unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, char color )
{
	if ( fill )
	{
		unsigned char y, ymax;                          // Find the y min and max
		
		if ( y1 < y2 )
		{
			y = y1;
			ymax = y2;
			}
		else
		{
			y = y2;
			ymax = y1;
			}

		for ( ; y <= ymax; ++y )                    // Draw lines to fill the rectangle
			OLEDLine ( x1, y, x2, y, color );
		}
	else
	{
		OLEDLine ( x1, y1, x2, y1, color );      // Draw the 4 sides
		OLEDLine ( x1, y2, x2, y2, color );
		OLEDLine ( x1, y1, x1, y2, color );
		OLEDLine ( x2, y1, x2, y2, color );
		}
	}


void OLEDAreaFill ( unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, char color )
{
	unsigned char y, ymax;                          // Find the y min and max
	
	if ( y1 < y2 )
	{
		y = y1;
		ymax = y2;
		}
	else
	{
		y = y2;
		ymax = y1;
		}

	for ( ; y <= ymax; ++y )                    // Draw lines to fill the rectangle
		OLEDLine ( x1, y, x2, y, color );
	}	


void OLEDCircle ( int x, int y, int radius, char fill, char color )
{
	int a, b, P;
	a = 0x00;
	b = radius;
	P = 0x01 - radius;
	
	do
	{
		if( fill )
		{
			OLEDLine ( x - a, y + b, x + a, y + b, color );
			OLEDLine ( x - a, y - b, x + a, y - b, color );
			OLEDLine ( x - b, y + a, x + b, y + a, color );
			OLEDLine ( x - b, y - a, x + b, y - a, color );
			}
		else
		{
			OLEDPixel ( a + x, b + y, color );
			OLEDPixel ( b + x, a + y, color );
			OLEDPixel ( x - a, b + y, color );
			OLEDPixel ( x - b, a + y, color );
			OLEDPixel ( b + x, y - a, color );
			OLEDPixel ( a + x, y - b, color );
			OLEDPixel ( x - a, y - b, color );
			OLEDPixel ( x - b, y - a, color );
      		}

		if ( P < 0 )
			P += 3 + 2 * a++;
		else
			P += 5 + 2 * ( a++ - b-- );
		
		} while ( a <= b );
	}


void OLEDBar ( int x1, int y1, int x2, int y2, int width, char color )
{
	signed int  x, y, addx, addy, j;
	signed int P, dx, dy, c1, c2;
	char i;

	dx = abs ( ( signed int ) ( x2 - x1 ) );
	dy = abs ( ( signed int ) ( y2 - y1 ) );
	x = x1;
	y = y1;
	c1 = -dx * x1 - dy * y1;
	c2 = -dx * x2 - dy * y2;

	if ( x1 > x2 )
	{
		addx = -1;
		c1 = -dx * x2 - dy * y2;
		c2 = -dx * x1 - dy * y1;
		}
	else
		addx = 1;
	
	if ( y1 > y2 )
	{
		addy = -1;
		c1 = -dx*x2 - dy*y2;
		c2 = -dx*x1 - dy*y1;
		}
	else
		addy = 1;

	if ( dx >= dy )
	{
		P = 2*dy - dx;

		for ( i = 0; i <= dx; ++i )
		{
			for ( j =- ( width / 2 ); j < width / 2 + width % 2; ++j )
			{
				if ( dx * x + dy * ( y + j ) + c1 >= 0 && dx * x + dy * ( y + j ) + c2 <= 0 )
					OLEDPixel ( x, y + j, color );
				}
			
			if ( P < 0 )
			{
				P += 2 * dy;
				x += addx;
				}
         	else
			{
				P += 2 * dy - 2 * dx;
				x += addx;
				y += addy;
				}
			}
		}
	else
	{
		P = 2 * dx - dy;

		for ( i = 0; i <= dy; ++i )
		{
			if ( P < 0 )
			{
				P += 2 * dx;
				y += addy;
				}
			else
			{
				P += 2 * dx - 2 * dy;
				x += addx;
				y += addy;
				}
			
			for ( j =- ( width / 2 ); j < width / 2 + width % 2; ++j )
			{
				if ( dx * x + dy * ( y + j ) + c1 >= 0 && dx * x + dy * ( y + j ) + c2 <= 0 )
				OLEDPixel ( x + j, y, color );
				}
			}
		}
	}




 void OLEDText ( int x, int y, char* textptr, int size, char color )
{
	unsigned char i, j, k, l, m;						// Loop counters
	unsigned char pixelData [ 5 ];						// Stores character data

	for ( i = 0; textptr [ i ] != 0x00; ++i, ++x )		// Loop through the passed string
	{
		if ( textptr [ i ] < 'S') // Checks if the letter is in the first text array
			memcpy ( pixelData, TEXT [ textptr [ i ] - ' '], 5 );
		
		else if(textptr[i] <= '~') // Check if the letter is in the second array
		{
			if ( ( textptr[i] >= 'a' ) && ( textptr[i] <= 'z' ) )
				memcpy ( pixelData, TEXT2 [ textptr [ i ] - 'S' - 1 ], 5 );
			
			else
				memcpy ( pixelData, TEXT2 [ textptr [ i ] - 'S' ], 5 );

			}
		
		else
			memcpy ( pixelData, TEXT [ 0 ], 5 );		// Default to space

		if ( x + 5 * size >= ARRAY_WIDHT )				// Performs character wrapping
		{	
			x = 0;										// Set x at far left position
			y += 7*size + 1;							// Set y at next position down
      		}
      
		for ( j = 0; j < 5; ++j, x += size )			// Loop through character byte data
		{
			for ( k = 0; k <7 *size; ++k )				// Loop through the vertical pixels
			{
				if ( bit_test ( pixelData [ j ], k ) )	// Check if the pixel should be set
				{
					for ( l = 0; l < size; ++l )		// The next two loops change the
					{									// character's size
						for ( m = 0; m < size; ++m )
						{
							OLEDPixel ( x + m, y + k * size + l, color ); // Draws the pixel
							}
						}
					}
				}
			}
		}
	}


void ODOpaste(char digit)
{
    unsigned int ptrTEST = &TEST;
    unsigned int ptrODOFonts = &ODOFonts;
    if ((digit>9)||(digit<0))
        digit =5;
    
    
    memcpy(ptrTEST,ptrODOFonts+(24*digit),12);
    memcpy(ptrTEST+96,ptrODOFonts+(24*digit)+12,12);
    
}

void ODOScroll_units(unsigned int position) //position from 0 to 159
{
    unsigned int byteIndex;
    unsigned int buffer;
    unsigned int buffer2;
    unsigned int ptrTEST = &TEST;
    unsigned int ptrODOFonts = &ODOFonts;
    unsigned int ptrbuffer = &buffer;
    unsigned int ptrbuffer2 = &buffer2;
    
    for(int i=0;i<12;i++)
    {
        buffer = 0x0000;
        buffer2 = 0x0000;
        byteIndex = (((unsigned int)(position/8))*12)+i;
        memcpy(ptrbuffer,ptrODOFonts+byteIndex,1);
        memcpy(ptrbuffer+1,ptrODOFonts+byteIndex+12,1);        
        memcpy(ptrbuffer2,ptrODOFonts+byteIndex+12,1);
        memcpy(ptrbuffer2+1,ptrODOFonts+byteIndex+24,1);
        buffer = buffer>>(position%8);
        buffer2 = buffer2>>(position%8);
        memcpy(ptrTEST+68+i,ptrbuffer,1);
        memcpy(ptrTEST+68+i+96,ptrbuffer2,1);
    }
}

void ODOScroll_tens(unsigned int position)
{
    unsigned int byteIndex;
    unsigned int buffer;
    unsigned int buffer2;
    unsigned int ptrTEST = &TEST;
    unsigned int ptrODOFonts = &ODOFonts;
    unsigned int ptrbuffer = &buffer;
    unsigned int ptrbuffer2 = &buffer2;
    
    for(int i=0;i<12;i++)
    {
        buffer = 0x0000;
        buffer2 = 0x0000;
        byteIndex = (((unsigned int)(position/8))*12)+i;
        memcpy(ptrbuffer,ptrODOFonts+byteIndex,1);
        memcpy(ptrbuffer+1,ptrODOFonts+byteIndex+12,1);        
        memcpy(ptrbuffer2,ptrODOFonts+byteIndex+12,1);
        memcpy(ptrbuffer2+1,ptrODOFonts+byteIndex+24,1);
        buffer = buffer>>(position%8);
        buffer2 = buffer2>>(position%8);
        memcpy(ptrTEST+i+52,ptrbuffer,1);
        memcpy(ptrTEST+i+52+96,ptrbuffer2,1);
    }

}

#endif