/* 
 * File:   needle.h
 * Author: RSoulie
 *
 * Created on November 3, 2015, 2:36 AM
 */

#ifndef NEEDLE_H
#define	NEEDLE_H

char CurrentSlot;

void initNeedle(void);
void swithcAllInductanceOff(void);
void SwitchOnInductandce(int i);
void Needle_Move(int n);
char AngleToSlot(int Angle);
//void MoveOneStepToSlot(char target);
void moveNeedle_fw(void);
void moveNeedle_bk(void);
char GetCurrentSlot(void);
void moveNeedle(int n);
void Needle_Cvg(int n);


#endif	/* NEEDLE_H */

