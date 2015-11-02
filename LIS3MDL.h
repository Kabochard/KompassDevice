#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "pin_manager.h"

#define LIS3MDL_RD 0x3D
#define LIS3MDL_WR 0x3C
// External constants
#define AXIS_X 0x80
#define AXIS_Y 0x40
#define AXIS_Z 0x20
// Note that if INTERRUPT_ISACTIVEHIGH is used to generate a wake signal, significant power may be wasted.  See README for details.
#define INTERRUPT_ISACTIVEHIGH 0x04
#define INTERRUPT_DONTLATCH 0x02
#define DATA_RATE_FAST -1
#define CONVERSION_TYPE_CONTINUOUS 0x00
#define CONVERSION_TYPE_SINGLE 0x01

// Internal constants
#define REG_ADDR_OUT_X_L 0x28
#define REG_ADDR_OUT_Y_L 0x2A
#define REG_ADDR_OUT_Z_L 0x2C
#define REG_CTL_1 0x20
#define REG_CTL_2 0x21
#define REG_CTL_3 0x22
#define REG_CTL_4 0x23
#define REG_CTL_5 0x24
#define REG_STATUS 0x27
#define REG_INT_CFG 0x30
#define REG_INT_SRC 0x31
#define REG_INT_THS_L 0x32
#define REG_INT_THS_H 0x33
#define SENSITIVITY_OF_MIN_SCALE 27368.0 // = (4 gauss scale) * (6842 LSB/gauss at 4 gauss scale)

int vX,vY,vZ;
float Xsf, Ysf, Xoff, Yoff;

int abs(int val);
void LIS3MDL_init(void);
void LIS3MDL_Read_XY(void);
void LIS3MDL_Read_XYZ(void);
void LIS3MDL_Average10_XY(void);
void LIS3MDL_Wait(void);
unsigned char LIS3MDL_selfTest(void);
void LIS3MDL_Write(unsigned char reg, unsigned char data);
double argXY();
void LIS3MDL_TEST(void);
void LIS3MDL_Read_Raw_XY(void);


