#include <xc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Init.h"
#include "DigitsDriver.h"
#include "LIS3MDL.h"
//#include "Switec_motor.h"
#include "interrupt_manager.h"
#include "eusart.h"

void main(void) 
{
    double angle;
    int minX=0,maxX=0,minY=0,maxY=0; // pour la calib
    float dX,dY; // pareil
    
    SYSTEM_Initialize();
    LIS3MDL_init();
    
    zeroNeedle(); // fait revenir l'aiguille en butee a gauche
    
    
    INTERRUPT_GlobalInterruptEnable(); 
    INTERRUPT_PeripheralInterruptEnable(); // autorise l'UART a recevoir des messages
    RC2=1; // active le puce bluetooth
    __delay_ms(100);
    printf("str\r"); // met la puce en mode stream, cf doc sur le site truconnect
    
    for(int i=1000;i>0;i--) // calib sur 1000 points (il faut physiquement faire tourner le magneto sur 360deg ou plus sans changer l'assiete (a vZ doit pas trop changer)))
    {
        LIS3MDL_Wait();
        LIS3MDL_Read_Raw_XY();
        if(vX<minX)
            minX=vX;
        if(vX>maxX)
            maxX=vX;
        if(vY<minY)
            minY=vY;
        if(vY>maxY)
            maxY=vY;
        display(i/10);
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
    
    
    while (1) 
    {
        //LIS3MDL_Read_XYZ();
        //norme = sqrt(((long)vX*(long)vX)+((long)vY*(long)vY)+((long)vZ*(long)vZ));
        //printf("X: %d  Y: %d \r\n",vX,vY);
        LIS3MDL_Wait();
        LIS3MDL_Read_XY();
        
        //LIS3MDL_Wait();
        angle = ((argXY()/M_PI)*180)+180;
        //display((int)angle);
        //goToPos((int)angle); // Fait bouger l'aiguille
        //printf("Angle: %f \r\n",angle); //Envoi l'angle par bluetooth
       //printf("%d\r\n",angle);
        //stepClock();
        __delay_ms(200);
        
        

    }
}

/**
 End of File
 */