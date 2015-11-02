/* 
 * File:   Switec_motor.h
 * Author: RSoulie
 *
 * Created on September 3, 2015, 3:30 PM
 */

static unsigned char stateMap[] = {0x90, 0x80, 0x20, 0x60, 0x40, 0x10};
volatile unsigned char state=0;
int position = 0;

void zeroNeedle(void);
void stepCounterClock(void);
void stepClock(void);
void goToPos(unsigned int);