#include "OLED.h"
#include "i2c.h"

#define OLED_RESET_PIN PORTDbits . RD2

#define bit_test(D,i) (D & (0x01 << i))

#define ARRAY_WIDHT 96 //
#define ARRAY_HEIGHT 2 //fonctionne plus ou moins ac 8
#define ARRAY_LENGHT ( 8 * ARRAY_HEIGHT )
#define SSD1306_GDDRAM ( ARRAY_WIDHT * ARRAY_HEIGHT / 8 )




unsigned char TEST [2][96];

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


