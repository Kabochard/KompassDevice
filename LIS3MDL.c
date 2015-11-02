#include <xc.h>
#include "i2c.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "LIS3MDL.h"

#define _XTAL_FREQ 16000000

 int abs(int val)  // valeur absolue
 { 
     return (val<0 ? (-val) : val);
 } 

void LIS3MDL_init(void) //cf datasheet du magneto
{
    LIS3MDL_Write(REG_CTL_1,0xFC); //UHP mode 80Hz
    LIS3MDL_Write(REG_CTL_2,0x00); // +-4 gauss ,  
    LIS3MDL_Write(REG_CTL_3,0x00); // continuous measurements
    LIS3MDL_Write(REG_CTL_5,0x40);
    
     
    LIS3MDL_Wait();
    LIS3MDL_Read_XY();
      
}

void LIS3MDL_Write(unsigned char reg, unsigned char data) //Cf datasheet pour comprendre le protocole
{
    i2c_Start();
    i2c_Write(LIS3MDL_WR);
    i2c_Write(reg);
    i2c_Write(data);
    i2c_Stop();

}

void LIS3MDL_Read_XY(void)
{
    unsigned char X_L, X_H, Y_L, Y_H;
    vX=0;
    vY=0;
    
    i2c_Start();
    i2c_Write(LIS3MDL_WR);
    i2c_Write(REG_ADDR_OUT_X_L);
    i2c_Restart();
    i2c_Write(LIS3MDL_RD);
    X_L=i2c_Read(1);
    X_H=i2c_Read(1);
    Y_L=i2c_Read(1);
    Y_H=i2c_Read(0);
    i2c_Stop();
    
    vX=(X_H<<8)+X_L; //Concatenation de la valeur en X (entier relatif code comme un int (peut etre negatif)))
    vY=(Y_H<<8)+Y_L;
 
    vX=(int)(Xsf*vX)+Xoff; // application de la calibration
    vY=(int)(Ysf*vY)+Yoff;
}

void LIS3MDL_Read_Raw_XY(void) // sans calibration
{
    unsigned char X_L, X_H, Y_L, Y_H;
    vX=0;
    vY=0;
    
    i2c_Start();
    i2c_Write(LIS3MDL_WR);
    i2c_Write(REG_ADDR_OUT_X_L);
    i2c_Restart();
    i2c_Write(LIS3MDL_RD);
    X_L=i2c_Read(1);
    X_H=i2c_Read(1);
    Y_L=i2c_Read(1);
    Y_H=i2c_Read(0);
    i2c_Stop();
    
    vX=(X_H<<8)+X_L;
    vY=(Y_H<<8)+Y_L;
}

void LIS3MDL_Read_XYZ(void) // avec l'axe Z (init attention a initialiser correctement))
{
    unsigned char X_L, X_H, Y_L, Y_H, Z_L, Z_H;
    
    i2c_Start();
    i2c_Write(LIS3MDL_WR);
    i2c_Write(REG_ADDR_OUT_X_L);
    i2c_Restart();
    i2c_Write(LIS3MDL_RD);
    X_L=i2c_Read(1);
    X_H=i2c_Read(1);
    Y_L=i2c_Read(1);
    Y_H=i2c_Read(1);
    Z_L=i2c_Read(1);
    Z_H=i2c_Read(0);
    i2c_Stop();
    
    vX=(X_H<<8)+X_L;
    vY=(Y_H<<8)+Y_L;
    vZ=(Z_H<<8)+Z_L;
        
}

void LIS3MDL_Average10_XY(void) // moyennage de la valeur brute sur 10 samples
{
    long int X=0;
    long int Y=0;
    
    LIS3MDL_Read_XY();
    for(unsigned char i=0;i<10;i++)
    {
        LIS3MDL_Wait();
        LIS3MDL_Read_XY();
        X=X+vX;
        Y=Y=+vY;
    }
    vX=(int)(Xsf*(X/10))+Xoff;
    vY=(int)(Ysf*(Y/10))+Yoff;

    
    

}

void LIS3MDL_Wait(void) // attente d'un nouveau set de donnees sur XYZ
{
    bool ZYXDA=0;
    while(!ZYXDA)
    {
        i2c_Start();
        i2c_Write(LIS3MDL_WR);
        i2c_Write(REG_STATUS);
        i2c_Restart();
        i2c_Write(LIS3MDL_RD);
        ZYXDA =(i2c_Read(0))& 0x08;
        i2c_Stop();
    }
}

unsigned char LIS3MDL_selfTest(void) // self test as per datasheet, sert pas a grand chose, pas precis du tout
{
    
    int OUTX_NOST=0, OUTY_NOST=0, OUTZ_NOST =0;
    int OUTX_ST=0, OUTY_ST=0, OUTZ_ST =0;
    
    LIS3MDL_Write(REG_CTL_1,0x1C);
    LIS3MDL_Write(REG_CTL_2,0x40); 
    __delay_ms(20);
    LIS3MDL_Write(REG_CTL_3,0x00);    
    __delay_ms(20);
    LIS3MDL_Wait();
    LIS3MDL_Read_XYZ();
    
    for(unsigned char i=0;i<5;i++)
    {
        LIS3MDL_Wait();
        LIS3MDL_Read_XYZ();
        OUTX_NOST = OUTX_NOST+vX;
        OUTY_NOST = OUTY_NOST+vY;
        OUTZ_NOST = OUTZ_NOST+vZ;
    }
    OUTX_NOST = OUTX_NOST/5;
    OUTY_NOST = OUTY_NOST/5;
    OUTZ_NOST = OUTZ_NOST/5;
    
    LIS3MDL_Write(REG_CTL_1,0x1D);
    __delay_ms(60);
    
    LIS3MDL_Wait();
    LIS3MDL_Read_XYZ();
    
    for(unsigned char i=0;i<5;i++)
    {
        LIS3MDL_Wait();
        LIS3MDL_Read_XYZ();
        OUTX_ST = OUTX_ST+vX;
        OUTY_ST = OUTY_ST+vY;
        OUTZ_ST = OUTZ_ST+vZ;
    }
    OUTX_ST = OUTX_ST/5;
    OUTY_ST = OUTY_ST/5;
    OUTZ_ST = OUTZ_ST/5;
    
    
    LIS3MDL_Write(REG_CTL_1,0x1C);
    LIS3MDL_Write(REG_CTL_3,0x03); 
    
    if((  abs(OUTX_ST-OUTX_NOST) < 2281)||(  abs(OUTX_ST-OUTX_NOST) > 6843)) //full scale: +-12 Gauss == 2281 bits / gauss limits 1 - 3 gauss sur XY, 0.1 - 1 sur Z
           return 1; 
    else if((abs(OUTY_ST-OUTY_NOST) < 2281)||(abs(OUTY_ST-OUTY_NOST) > 6843))
            return 2;             
    else if((abs(OUTZ_ST-OUTZ_NOST) < 228)||(abs(OUTZ_ST-OUTZ_NOST) > 2281))
            return 3;
    else
        return 0;
    
}

double argXY (void) // calcul de l'argument en radians
{
    return (atan2((double)vX,(double)vY));
}