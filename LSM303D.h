#include <xc.h>
#include <stdint.h>
#include <stdbool.h>





static int mX,mY,mZ,aX,aY,aZ=0;

void LSM303D_Write(unsigned char reg, unsigned char data);
void LSM303D_init(void);
void LSM303D_Read_M(void);
void LSM303D_Read_A(void);
void LSM303D_Update_M_Data(void);
int Update_Magnetic_Angle(void);


