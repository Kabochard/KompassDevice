#include "needle.h"
#include <xc.h>
#include <stdlib.h>

#define _XTAL_FREQ 16000000



void swithcAllInductanceOff(void)
{
    PORTA = PORTA&0x00;
    PORTC = PORTC&0xF8;
    PORTD = PORTD&0xFC;
    PORTE = PORTE&0xF8;
}

void SwitchOnInductandce(int i)
{
    switch (i)
    {
        case 0: RA1 = 1;
        break;
        case 1: RA3 = 1;
        break;
        case 2: RA5 = 1;
        break;
        case 3: RE1 = 1;
        break;
        case 4: RE2 = 1;
        break;
        case 5: RA6 = 1;
        break;
        case 6: RC1 = 1;
        break;
        case 7: RD0 = 1;
        break;
        //////
        case 8: RA0 = 1;
        break;
        case 9: RA2 = 1;
        break;
        case 10: RA4 = 1;
        break;
        case 11: RE0 = 1;
        break;
        case 12: RA7 = 1;
        break;
        case 13: RC0 = 1;
        break;
        case 14: RC2 = 1;
        break;
        case 15: RD1 = 1;
        break;     
    }
}

void moveNeedle(int n)
{
    swithcAllInductanceOff();
    SwitchOnInductandce(n/2);
    
    if (n%2 == 1)
    {
    SwitchOnInductandce(((n+1)/2)%16);
    }
    
    CurrentSlot = n;
}

void initNeedle(void)
{
    CurrentSlot = 0;
    moveNeedle(0);
    
}

void Needle_Move(int n)
{
    int target;
    target = n % 32;
    //int t1= (target + 16 ) % 32;
    

    while (CurrentSlot != target)
    {
        if (target <16) //target + 16 < 32 = 0 %32
            if ((CurrentSlot > (target - 16) % 32) || (CurrentSlot < target))  
            {
                moveNeedle_fw();
            }
            else
            {
                moveNeedle_bk();
            }
        else 
        {
            if ((CurrentSlot > target - 16) && (CurrentSlot < target))
            {
                moveNeedle_fw();
            }
            else
            {
                moveNeedle_bk();
            }
        }
        __delay_ms(10);
    }

    __delay_ms(2500);
}


char AngleToSlot(int Angle)
{
    Angle = Angle%360;
    return (Angle/11.58);

}

void moveNeedle_fw(void)
{
    moveNeedle( (CurrentSlot+1)%32);
}

void moveNeedle_bk(void)
{
    moveNeedle( (CurrentSlot-1)%32);
}

char GetCurrentSlot(void)
{
    return CurrentSlot;
}

void Needle_Cvg(int n)
{
    int target;
    target = n % 32;
    //int t1= (target + 16 ) % 32;
    int dist =  abs(target - CurrentSlot);
    int tmp = abs(target + 32 - CurrentSlot);
    
    if (tmp < dist)
    {
        dist = tmp;
    }

   
        if (target <16) //target + 16 < 32 = 0 %32
            if ((CurrentSlot > (target - 16) % 32) || (CurrentSlot < target))  
            {
                moveNeedle_fw();
                if (dist > 3)
                {
                    moveNeedle_fw();
                }
                if (dist >6)
                {
                    moveNeedle_fw();
                }
            }
            else
            {
                moveNeedle_bk();
                if (dist > 3)
                {
                    moveNeedle_bk();
                }
                if (dist >6)
                {
                    moveNeedle_bk();
                }
            }
        else 
        {
            if ((CurrentSlot > target - 16) && (CurrentSlot < target))
            {
               moveNeedle_fw();
                if (dist > 3)
                {
                    moveNeedle_fw();
                }
                if (dist >6)
                {
                    //moveNeedle_fw();
                }
            }
            else
            {
                moveNeedle_bk();
                if (dist > 3)
                {
                    moveNeedle_bk();
                }
                if (dist > 6)
                {
                   // moveNeedle_bk();
                }
            }
        }
  
    __delay_ms(200);
}

//void MoveOneStepToSlot(char target)
//{
//    //Test pour stabiliser l aiguille
//    if(   ((target>CurrentSlot)&&((target-CurrentSlot)<2))  ||((CurrentSlot>target)&&((CurrentSlot-target)<2)))
//        return;
//    
//    
//    if(((target>CurrentSlot)&&(target-CurrentSlot<17))
//        ||((target<CurrentSlot)&&(CurrentSlot-target>16)))
//    {
//        CurrentSlot++;
//        if(CurrentSlot>31)
//            CurrentSlot=0;
//        moveNeedle(CurrentSlot);
//    }
//    if(((target>CurrentSlot)&&(target-CurrentSlot>16))
//            ||((target<CurrentSlot)&&(CurrentSlot-target<17)))
//    {
//        if(CurrentSlot==0)
//            CurrentSlot=31;
//        else
//            CurrentSlot--;
//        moveNeedle(CurrentSlot);
//    }
//
//}


