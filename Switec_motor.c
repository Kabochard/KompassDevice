#include "Init.h"
#include "DigitsDriver.h"
#include "LIS3MDL.h"
#include "Switec_motor.h"

void stepClock(void)
{
    PORTD = PORTD & 0x0F;
    PORTD = PORTD | stateMap[state];
    if (state==5)
        state = 0;
    else
        state++;
    
    __delay_ms(3); // definit a quelle frequence le moteur recoit les impulsions
                   // a modifier pour ajuster la vitesse, peut etre reduit lorque le moteur est lance (acceleration))
    PORTD = PORTD & 0x0F; // coupe le courant dans les bobines
    
}

void stepCounterClock(void)
{
    PORTD = PORTD & 0x0F;
    PORTD = PORTD | stateMap[state];
    if (state==0)
        state = 5;
    else
        state--;
    
    __delay_ms(3);
    PORTD = PORTD & 0x0F;
}

void zeroNeedle(void)
{
    for(unsigned int i=0; i<1080;i++)
    {
        stepCounterClock();
    }
    position=0;
}

void goToPos(unsigned int pos)
{    
    int target=pos;
    if (pos>position)
    {
        while(pos>position)
        {
            stepClock();
            stepClock();
            stepClock();
           pos--;
        }
    }
    else if (pos<position)
    {
        while(pos<position)
        {
            stepCounterClock();
            stepCounterClock();
            stepCounterClock();
           pos++;
        }
    }

    position = target;
    return;
}
