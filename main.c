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
static int offsetX[32]=
{1125,-423,-1054,-2587,-3877,-6047,-7184,-8927,-9354,-9934,-9398,-8965,-7571,-6645,-5556,-3183,-1800,-2,535,2065,4021,5283,6699,8069,8880,9553,9194,8637,7020,6672,5195,2554};
static int offsetY[32]=
{1880,1887,2052,2022,1937,1873,1789,1203,402,-641,-1663,-2063,-2448,-2454,-2574,-2444,-2454,-2412,-2600,-2746,-2661,-2379,-2314,-1773,-913,210,1035,1663,2064,1954,1946,1748};
static float gainY[32]={1.578 , 1.791 , 1.401 , 1.638 , 1.511 , 1.707 , 1.474 , 1.536 , 1.193 , 1.170 , 1.464 , 1.553 , 1.733 , 1.633 , 1.711 , 1.723 , 1.745 , 1.781 , 1.572 , 1.721 , 1.851 , 1.685 , 1.742 , 1.621 , 1.036 , 1.685 , 1.178 , 1.623 , 1.593 , 1.486 , 1.798 , 1.918};


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
    //double x = (double) (GetMx());
    //double y = (double) (GetMy());
    
   // norm = (int) (sqrt(x * x + y * y));
   // MagAng = (int) ((atan2(x,y)+3.14)*57.32);
    
   int cSlot = GetCurrentSlot();
//    TruX =GetMx() - CoefX[cSlot] -75;
//    TruY = GetMy() - CoefY[cSlot] - 1066;

    
    // TruNorm = (int) (sqrt(TruX * TruX + TruY * TruY));
    //TruAng = (int) ((atan2(TruX,TruY)+3.14)*57.32);
    
    printf("SXY:%2d:%6d:%6d T",cSlot,GetMx(),GetMy());
}


 void UpdateDisplay()
    {
     
     char slot[3];
        int slt;
        slt = GetCurrentSlot();
        sprintf(slot, "%2d", slt);
    
        OLEDText ( 0, 0, &slot, SIZE_ONE, WHITE );
                OLEDUpdateDisplay ( DDGRAM_CLEAR );
     
     
//    Commented for speeding up calib 
//        //retrieve distance and bearing from uart (ios)        
//       char dist[6];
//       int distance;
//       distance = GET_DIST();
//       sprintf(dist, "%5d", TruNorm);
//       
//       char bear[4];
//       int cap;
//       cap = GET_CAP();
//        sprintf(bear, "%3d", TruAng);
//      
//        char slot[3];
//        int slt;
//        slt = GetCurrentSlot();
//        sprintf(slot, "%2d", slt);
//        
//      char separator[] = " Ang:";
////    
//      char slotor[]  = " Slot:";
//      
//      char Magor[]  = " Mag:";
//      
//      char txt[26];// + strlen(separator)];
//      strcpy(txt, dist);
//      
//      strcat(&txt, &separator);
//      strcat(txt, bear);
//      strcat(&txt, &slotor);
//      strcat(&txt, &slot);
//      
//      OLEDText ( 0, 0, &txt, SIZE_ONE, WHITE );
//                OLEDUpdateDisplay ( DDGRAM_CLEAR );
//               // moveNeedle(AngleToSlot(bearing));
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
        moveNeedle_fw();
        __delay_ms(50);
        
        for (int i=0; i<100; i++)
        {
             ComputeAng();
              UpdateDisplay();
        }
    
               
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

     
    
   
    
    