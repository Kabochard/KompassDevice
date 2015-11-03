#include <xc.h>
#include "i2c.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LSM303D.h"
#include "needle.h"

#define _XTAL_FREQ 16000000

#define LSM303D_RD 0x3D
#define LSM303D_WR 0x3C

/* register addresses: A: accel, M: mag, T: temp */
#define ADDR_WHO_AM_I			0x0F

#define ADDR_OUT_TEMP_L			0x05
#define ADDR_OUT_TEMP_H			0x06
#define ADDR_STATUS_M			0x07
#define ADDR_OUT_X_L_M          0x08
#define ADDR_OUT_X_H_M          0x09
#define ADDR_OUT_Y_L_M          0x0A
#define ADDR_OUT_Y_H_M			0x0B
#define ADDR_OUT_Z_L_M			0x0C
#define ADDR_OUT_Z_H_M			0x0D

#define ADDR_INT_CTRL_M			0x12
#define ADDR_INT_SRC_M			0x13
#define ADDR_REFERENCE_X		0x1c
#define ADDR_REFERENCE_Y		0x1d
#define ADDR_REFERENCE_Z		0x1e

#define ADDR_STATUS_A			0x27
#define ADDR_OUT_X_L_A			0x28
#define ADDR_OUT_X_H_A			0x29
#define ADDR_OUT_Y_L_A			0x2A
#define ADDR_OUT_Y_H_A			0x2B
#define ADDR_OUT_Z_L_A			0x2C
#define ADDR_OUT_Z_H_A			0x2D

#define ADDR_CTRL_REG0			0x1F
#define ADDR_CTRL_REG1			0x20
#define ADDR_CTRL_REG2			0x21
#define ADDR_CTRL_REG3			0x22
#define ADDR_CTRL_REG4			0x23
#define ADDR_CTRL_REG5			0x24
#define ADDR_CTRL_REG6			0x25
#define ADDR_CTRL_REG7			0x26

#define ADDR_FIFO_CTRL			0x2e
#define ADDR_FIFO_SRC			0x2f

#define ADDR_IG_CFG1			0x30
#define ADDR_IG_SRC1			0x31
#define ADDR_IG_THS1			0x32
#define ADDR_IG_DUR1			0x33
#define ADDR_IG_CFG2			0x34
#define ADDR_IG_SRC2			0x35
#define ADDR_IG_THS2			0x36
#define ADDR_IG_DUR2			0x37
#define ADDR_CLICK_CFG			0x38
#define ADDR_CLICK_SRC			0x39
#define ADDR_CLICK_THS			0x3a
#define ADDR_TIME_LIMIT			0x3b
#define ADDR_TIME_LATENCY		0x3c
#define ADDR_TIME_WINDOW		0x3d
#define ADDR_ACT_THS			0x3e
#define ADDR_ACT_DUR			0x3f

#define REG1_RATE_BITS_A		((1<<7) | (1<<6) | (1<<5) | (1<<4))
#define REG1_POWERDOWN_A		((0<<7) | (0<<6) | (0<<5) | (0<<4))
#define REG1_RATE_3_125HZ_A		((0<<7) | (0<<6) | (0<<5) | (1<<4))
#define REG1_RATE_6_25HZ_A		((0<<7) | (0<<6) | (1<<5) | (0<<4))
#define REG1_RATE_12_5HZ_A		((0<<7) | (0<<6) | (1<<5) | (1<<4))
#define REG1_RATE_25HZ_A		((0<<7) | (1<<6) | (0<<5) | (0<<4))
#define REG1_RATE_50HZ_A		((0<<7) | (1<<6) | (0<<5) | (1<<4))
#define REG1_RATE_100HZ_A		((0<<7) | (1<<6) | (1<<5) | (0<<4))
#define REG1_RATE_200HZ_A		((0<<7) | (1<<6) | (1<<5) | (1<<4))
#define REG1_RATE_400HZ_A		((1<<7) | (0<<6) | (0<<5) | (0<<4))
#define REG1_RATE_800HZ_A		((1<<7) | (0<<6) | (0<<5) | (1<<4))
#define REG1_RATE_1600HZ_A		((1<<7) | (0<<6) | (1<<5) | (0<<4))

#define REG1_BDU_UPDATE			(1<<3)
#define REG1_Z_ENABLE_A			(1<<2)
#define REG1_Y_ENABLE_A			(1<<1)
#define REG1_X_ENABLE_A			(1<<0)

#define REG2_ANTIALIAS_FILTER_BW_BITS_A	((1<<7) | (1<<6))
#define REG2_AA_FILTER_BW_773HZ_A		((0<<7) | (0<<6))
#define REG2_AA_FILTER_BW_194HZ_A		((0<<7) | (1<<6))
#define REG2_AA_FILTER_BW_362HZ_A		((1<<7) | (0<<6))
#define REG2_AA_FILTER_BW_50HZ_A		((1<<7) | (1<<6))

#define REG2_FULL_SCALE_BITS_A	((1<<5) | (1<<4) | (1<<3))
#define REG2_FULL_SCALE_2G_A	((0<<5) | (0<<4) | (0<<3))
#define REG2_FULL_SCALE_4G_A	((0<<5) | (0<<4) | (1<<3))
#define REG2_FULL_SCALE_6G_A	((0<<5) | (1<<4) | (0<<3))
#define REG2_FULL_SCALE_8G_A	((0<<5) | (1<<4) | (1<<3))
#define REG2_FULL_SCALE_16G_A	((1<<5) | (0<<4) | (0<<3))

#define REG5_ENABLE_T			(1<<7)

#define REG5_RES_HIGH_M			((1<<6) | (1<<5))
#define REG5_RES_LOW_M			((0<<6) | (0<<5))

#define REG5_RATE_BITS_M		((1<<4) | (1<<3) | (1<<2))
#define REG5_RATE_3_125HZ_M		((0<<4) | (0<<3) | (0<<2))
#define REG5_RATE_6_25HZ_M		((0<<4) | (0<<3) | (1<<2))
#define REG5_RATE_12_5HZ_M		((0<<4) | (1<<3) | (0<<2))
#define REG5_RATE_25HZ_M		((0<<4) | (1<<3) | (1<<2))
#define REG5_RATE_50HZ_M		((1<<4) | (0<<3) | (0<<2))
#define REG5_RATE_100HZ_M		((1<<4) | (0<<3) | (1<<2))
#define REG5_RATE_DO_NOT_USE_M	((1<<4) | (1<<3) | (0<<2))

#define REG6_FULL_SCALE_BITS_M	((1<<6) | (1<<5))
#define REG6_FULL_SCALE_2GA_M	((0<<6) | (0<<5))
#define REG6_FULL_SCALE_4GA_M	((0<<6) | (1<<5))
#define REG6_FULL_SCALE_8GA_M	((1<<6) | (0<<5))
#define REG6_FULL_SCALE_12GA_M	((1<<6) | (1<<5))

#define REG7_CONT_MODE_M		((0<<1) | (0<<0))
#define REG7_ONE_SHOT_M         ((0<<1) | (1<<0))

#define REG_STATUS_A_NEW_ZYXADA		0x08

#define INT_CTRL_M              0x12
#define INT_SRC_M               0x13

/* default values for this device */
#define LSM303D_ACCEL_DEFAULT_RANGE_G			8
#define LSM303D_ACCEL_DEFAULT_RATE			800
#define LSM303D_ACCEL_DEFAULT_ONCHIP_FILTER_FREQ	50
#define LSM303D_ACCEL_DEFAULT_DRIVER_FILTER_FREQ	30
#define LSM303D_ACCEL_MAX_OUTPUT_RATE			280

#define LSM303D_MAG_DEFAULT_RANGE_GA			2
#define LSM303D_MAG_DEFAULT_RATE			100

#define LSM303D_ONE_G					9.80665f

const int CoefX []= {285,1686,2115,3253,4287,5654,7486,10210,12546,14634,14529,13085,10036,7789,6097,4358,2330,850,209,-1059,-2333,-4085,-6775,-10390,-12667,-13340,-11504,-8725,-6010,-4386,-3051,-905};
const int CoefY []= {-2054,-2072,-2331,-2557,-2989,-3286,-3585,-3337,-2170,233,2941,4657,5413,5278,5116,4800,4674,4656,4952,5224,5783,6189,6446,5481,3132,-243,-2198,-2970,-2904,-2573,-2408,-2037};



void LSM303D_Write(unsigned char reg, unsigned char data) //Cf datasheet pour comprendre le protocole
{
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(reg);
    i2c_Write(data);
    i2c_Stop();

}

void LSM303D_init(void)
{
    LSM303D_Write(ADDR_CTRL_REG1,REG1_RATE_50HZ_A|REG1_X_ENABLE_A|REG1_Y_ENABLE_A|REG1_Z_ENABLE_A);
    //CTRL2,3,4 default
    LSM303D_Write(ADDR_CTRL_REG5,REG5_RATE_50HZ_M|REG5_RES_HIGH_M);
    //CTRL6 default 4 gauss
    LSM303D_Write(ADDR_CTRL_REG7,REG7_ONE_SHOT_M);
}


void LSM303D_Update_M_Data( void)
{
    LSM303D_Write(ADDR_CTRL_REG7,REG7_ONE_SHOT_M);
    LSM303D_Read_M();
    
    printf("SLOTXY=%d:%d:%d\n",CurrentSlot,mX,mY);
    
}

void LSM303D_Read_M(void) // sans calibration
{
    unsigned char X_L, X_H, Y_L, Y_H, Z_L, Z_H;
    mX=0;
    mY=0;
    mZ=0;
    
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_X_L_M);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    X_L=i2c_Read(0);

    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_X_H_M);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    X_H=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_Y_L_M);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    Y_L=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_Y_H_M);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    Y_H=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_Z_L_M);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    Z_L=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_Z_H_M);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    Z_H=i2c_Read(0);
    i2c_Stop();
    
    mX=(X_H<<8)+X_L;
    mY=(Y_H<<8)+Y_L;
    mZ=(Z_H<<8)+Z_L;
    
}

void LSM303D_Read_A(void) // sans calibration
{
    unsigned char X_L, X_H, Y_L, Y_H, Z_L, Z_H;
    aX=0;
    aY=0;
    aZ=0;
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_X_L_A);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    X_L=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_X_H_A);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    X_H=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_Y_L_A);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    Y_L=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_Y_H_A);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    Y_H=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_Z_L_A);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    Z_L=i2c_Read(0);
    i2c_Stop();
    
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(ADDR_OUT_Z_H_A);
    i2c_Restart();
    i2c_Write(LSM303D_RD);
    Z_H=i2c_Read(0);
    i2c_Stop();
    
    aX=(X_H<<8)+X_L;
    aY=(Y_H<<8)+Y_L;
    aZ=(Z_H<<8)+Z_L;
    
}

int Update_Magnetic_Angle(void)
{
    double angrad=0;
    int Acc = 0;
    int X,Y;
    
    LSM303D_Update_M_Data();
    X = mX-100;//-CoefX[CurrentSlot];
    Y = mY;//-CoefY[CurrentSlot];
    angrad = atan2(X,Y);
    angrad = ((angrad+3.14)*57.32);
    return ((int)angrad);
    //return 1;
}