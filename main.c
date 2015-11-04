#include <xc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "system_init.h"
#include "interrupt_manager.h"
#include "LSM303D.h"
#include "needle.h"
#include "OLED.h"


#define _XTAL_FREQ 16000000

/*static int offsetX[32]=
{835,992,1547,1846,2679,3190,3692,3897,3868,3650,3285,3119,2706,2292,2030,1695,1520,1234,763,188,-483,-1063,-1238,-1329,-1202,-874,-666,-511,-144,197,395,689};
static int offsetY[32]=
{1181,1432,2197,2511,3034,3079,2692,2283,1352,671,-60,-366,-1021,-1687,-2096,-2722,-2998,-3363,-3901,-4362,-4490,-4230,-3844,-3136,-2549,-1727,-1353,-1060,-457,105,401,973};
*/


//int console[2][100];

/*
                         Main application
 */
void main(void) {
    
    // initialize the device
    SYSTEM_Initialize();
    
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    //wait for interupt
    int MagAng;
   
    int pos = 0;
    
   // moveNeedle(CurrentSlot);
    
    while (1)
    {
        
        
//    MagAng = Update_Magnetic_Angle();
//  
//    
//    char disp[4];
//    
//    char str[10];
//
//    sprintf(disp, "%d", MagAng);
//    OLEDText ( 0, 0, disp, SIZE_ONE, WHITE );
//    OLEDUpdateDisplay ( DDGRAM_CLEAR );
//    
//    //MoveOneStepToSlot(AngleToSlot(MagAng)); 
     //   moveNeedle(pos);
     //   pos = (pos +1) % 32;
        
    //__delay_ms(300);
  
        
    }
     
}