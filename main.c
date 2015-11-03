#include <xc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "system_init.h"
#include "eusart.h"
#include "interrupt_manager.h"
#include "LSM303D.h"
//#include "OLED.h"
#include "needle.h"


/*static int offsetX[32]=
{835,992,1547,1846,2679,3190,3692,3897,3868,3650,3285,3119,2706,2292,2030,1695,1520,1234,763,188,-483,-1063,-1238,-1329,-1202,-874,-666,-511,-144,197,395,689};
static int offsetY[32]=
{1181,1432,2197,2511,3034,3079,2692,2283,1352,671,-60,-366,-1021,-1687,-2096,-2722,-2998,-3363,-3901,-4362,-4490,-4230,-3844,-3136,-2549,-1727,-1353,-1060,-457,105,401,973};
*/

int MagAngle = 0;

//int console[2][100];

/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    initNeedle();
    
    OLEDSetUp ( );
    //OLEDFill ( CLEAR );
    
 
  
/* char pos=0;
 char pos2=0;
 
 while (1)
 {
     
     for(pos2=0;pos2<190;)
     {  
        for(pos=0;pos<171;pos++)
        {  
           ODOScroll_units(pos);
           OLEDUpdateDisplay ( DDGRAM_NO_CLEAR );                 
          // __delay_ms (20);
        }
        for(;pos<190;pos++)
        {
        ODOScroll_tens(pos2++);    
        ODOScroll_units(pos);
        OLEDUpdateDisplay ( DDGRAM_NO_CLEAR );
        }
        __delay_ms(120);
        moveNeedle(CurrentSlot);
        CurrentSlot=(CurrentSlot+1)%32;
       // __delay_ms (20);
     }
     
 
 }*/

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    RC5 = 1; //RESET BT OFF
    __delay_ms(100);
    printf("str\r"); // met la puce en mode stream, cf doc sur le site truconnect
    
    //LSM303D_init();
    

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    //moveNeedle(0);
    //CurrentSlot=0;
    
    while (1)
    {
        
        
        
        /*for(char j=0;j<100;j++)
        {
         //LSM303D_Write(ADDR_CTRL_REG7,0x01);
         //LSM303D_Read_M();
         UpdateMagneticAngle();
         console[0][j]=mX;
         console[1][j]=mY;
         __delay_ms(100);
        }*/
        
        //MoveOneStepToSlot(AngleToSlot(MagAngle));
        //i++;
        //moveNeedle(i);
        //__delay_ms(1000);
        //UpdateMagneticAngle();
        //printf("angle: %d deg\r\n",(int)MagAngle);
       //printf("angle: %d \r\n",MagAngle);
    }
    /*{
        //for(int i=0;i<32;i++)
        //{
   
 
        //for(int j=0;j<50;j++)
        //{
        LSM303D_Write(ADDR_CTRL_REG7,0x01);
        LSM303D_Read_M();
        mX = mX+offsetX[i]-671;
        mY = mY+offsetY[i]+1073;   
        __delay_ms(100);
        //swithcAllInductanceOff();         
        
       printf("XXX|%d|%d|%d\r\n",i,mX,mY);
       __delay_ms(100);
       
       //printf("angle: %d deg\r\n",(int)angrad);
       
       
        //vectX[i]=mX+380;
        //vectY[i]=mY+290;
       // }//}
    
        
       
    }*/        
}




/*void UpdateMagneticAngle(void)
{
    double angrad=0;
    
    LSM303D_Write(ADDR_CTRL_REG7,0x01);
    LSM303D_Read_M();
    mX = mX+offsetX[CurrentSlot]-671;
    mY = mY+offsetY[CurrentSlot]+1073;
    angrad = atan2(mX,mY);
    MagAngle = (int)((angrad+3.14)*57.32); 

}*/

void UpdateMagneticAngle(void)
{
    double angrad=0;
    int Acc = 0;
    
    for(char i=0;i<5;i++)
    {
    LSM303D_Write(ADDR_CTRL_REG7,0x01);
    LSM303D_Read_M();
    //mX = mX-offsetX[CurrentSlot]+1000;
    //mY = mY-offsetY[CurrentSlot]-476;
    angrad = atan2(mY,mX);
    Acc=((angrad+3.14)*57.32)+Acc;
    MagAngle = (int)(Acc/5);
    __delay_ms(5);
    }

}