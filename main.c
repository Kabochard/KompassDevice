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

const int CoefX []= {-2498 ,-1182 ,-412 ,680 ,1875 ,3392 ,5449 ,8870 ,11376 ,13113 ,12166 ,9661 ,6895 ,4809 ,3382 ,1299 ,-298 ,-1763 ,-2279 ,-3520 ,-4647 ,-6236 ,-8340 ,-11413 ,-13763 ,-15677 ,-15136 ,-13327 ,-10405 ,-8142 ,-6480 ,-4384 };
const int CoefY []= {-3607 ,-3542 ,-3779 ,-3977 ,-4453 ,-4806 ,-5159 ,-4724 ,-3113 ,-39 ,2544 ,3942 ,4173 ,3895 ,3739 ,3406 ,3410 ,3475 ,3787 ,4086 ,4579 ,4955 ,5237 ,4768 ,3254 ,372 ,-2324 ,-3977 ,-4526 ,-4366 ,-4173 ,-3758};

static int norm = 0;
static int MagAng = 0;
static int TruAng = 0;
static int TruNorm = 0;

static int TruX = 0;
static int TruY = 0;
/*static int offsetX[32]=
{835,992,1547,1846,2679,3190,3692,3897,3868,3650,3285,3119,2706,2292,2030,1695,1520,1234,763,188,-483,-1063,-1238,-1329,-1202,-874,-666,-511,-144,197,395,689};
static int offsetY[32]=
{1181,1432,2197,2511,3034,3079,2692,2283,1352,671,-60,-366,-1021,-1687,-2096,-2722,-2998,-3363,-3901,-4362,-4490,-4230,-3844,-3136,-2549,-1727,-1353,-1060,-457,105,401,973};
*/


////int console[2][100];
//char* ConcatStrings( char* str1, char* str2, int len)
//    {
//        char * str3  //= (char *) malloc(len);
//      strcpy(str3, str1);
//      strcat(str3, str2);
//      
//      return str3;
//    }

void ComputeAng()
{
    LSM303D_Update_M_Data();
    double x = (double) (GetMx());
    double y = (double) (GetMy());
    
    norm = (int) (sqrt(x * x + y * y));
    MagAng = (int) ((atan2(x,y)+3.14)*57.32);
    
    int cSlot = GetCurrentSlot();
    TruX =GetMx() - CoefX[cSlot] -75;
    TruY = GetMy() - CoefY[cSlot] - 1066;
    
    // TruNorm = (int) (sqrt(TruX * TruX + TruY * TruY));
    //TruAng = (int) ((atan2(TruX,TruY)+3.14)*57.32);
    
    printf("SXY:%2d:%6d:%6d T",cSlot,TruX,TruY);
}


 void UpdateDisplay()
    {
    
     
     
        //retrieve distance and bearing from uart (ios)        
       char dist[6];
       int distance;
       distance = GET_DIST();
       sprintf(dist, "%5d", TruNorm);
       
       char bear[4];
       int cap;
       cap = GET_CAP();
        sprintf(bear, "%3d", TruAng);
      
        char slot[3];
        int slt;
        slt = GetCurrentSlot();
        sprintf(slot, "%2d", slt);
        
      char separator[] = " Ang:";
//    
      char slotor[]  = " Slot:";
      
      char Magor[]  = " Mag:";
      
      char txt[26];// + strlen(separator)];
      strcpy(txt, dist);
      
      strcat(&txt, &separator);
      strcat(txt, bear);
      strcat(&txt, &slotor);
      strcat(&txt, &slot);
      
      OLEDText ( 0, 0, &txt, SIZE_ONE, WHITE );
                OLEDUpdateDisplay ( DDGRAM_CLEAR );
               // moveNeedle(AngleToSlot(bearing));
    }

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

    swithcAllInductanceOff();
    moveNeedle(5);
    
    __delay_ms(1000);
    while (1)
    {
        //printf("Yo");
                //printf("HelloT \n");
                __delay_ms(50);
                ComputeAng();
                UpdateDisplay();

        }
        
        
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
//        ComputeAng();
//        
//        printf("XY:%d:%d",GetMx(),GetMy());
//        UpdateDisplay();
//        //printf("Hello");
//      __delay_ms(100);
   
        
   
}

     
    
   
    
    