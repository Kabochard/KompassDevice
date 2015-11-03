/* 
 * File:   needle.h
 * Author: RSoulie
 *
 * Created on November 3, 2015, 2:36 AM
 */

#ifndef NEEDLE_H
#define	NEEDLE_H

char CurrentSlot = 0;

void initNeedle(void);
void swithcAllInductanceOff(void);
void SwitchOnInductandce(int i);
void moveNeedle(int n);
char AngleToSlot(int Angle);
//void MoveOneStepToSlot(char target);



#endif	/* NEEDLE_H */

