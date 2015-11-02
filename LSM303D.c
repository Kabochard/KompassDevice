#include <xc.h>
#include "i2c.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LSM303D.h"

#define _XTAL_FREQ 16000000

void LSM303D_init(void)
{
    LSM303D_Write(ADDR_CTRL_REG1,REG1_RATE_50HZ_A|REG1_X_ENABLE_A|REG1_Y_ENABLE_A|REG1_Z_ENABLE_A);
    //CTRL2,3,4 default
    LSM303D_Write(ADDR_CTRL_REG5,REG5_RATE_50HZ_M|REG5_RES_HIGH_M);
    //CTRL6 default 4 gauss
    LSM303D_Write(ADDR_CTRL_REG7,0x01);
}

void LSM303D_Write(unsigned char reg, unsigned char data) //Cf datasheet pour comprendre le protocole
{
    i2c_Start();
    i2c_Write(LSM303D_WR);
    i2c_Write(reg);
    i2c_Write(data);
    i2c_Stop();

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

void Calib(void)
{
    int minX=0,maxX=0,minY=0,maxY=0; // pour la calib
    float dX,dY; // pareil
    
    printf("Calib: ");
    for(int i=100;i>0;i--) // calib sur 1000 points (il faut physiquement faire tourner le magneto sur 360deg ou plus sans changer l'assiete (a vZ doit pas trop changer)))
    {
        LSM303D_Write(ADDR_CTRL_REG7,0x01);
        __delay_ms(20);
        LSM303D_Read_M();
        if(mX<minX)
            minX=mX;
        if(mX>maxX)
            maxX=mX;
        if(mY<minY)
            minY=mY;
        if(mY>maxY)
            maxY=mY;
       
    }
    
    dX = maxX-minX;
    dY = maxY-minY;
    Xsf=dY/dX;
    if(Xsf<1)
        Xsf=1;
    Ysf=dX/dY;
    if(Ysf<1)
        Ysf=1;
    
    Xoff= ((dX)/2 - maxX) * Xsf;
    Yoff = ((dY)/2 - maxY) * Ysf;
}