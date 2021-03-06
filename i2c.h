/*
 * Hi-Tech C I2C library for 12F1822
 * Master mode routines for I2C MSSP port to read and write to slave device 
 * Copyright (C)2011 HobbyTronics.co.uk 2011
 * Freely distributable.
*/
#ifndef i2c_H
#define	i2c_H

#define I2C_WRITE 0
#define I2C_READ 1

// Initialise MSSP port. (12F1822 - other devices may differ)
void i2c_Init(void);

// i2c_Wait - wait for I2C transfer to finish
void i2c_Wait(void);
// i2c_Start - Start I2C communication
void i2c_Start(void);

// i2c_Restart - Re-Start I2C communication
void i2c_Restart(void);

// i2c_Stop - Stop I2C communication
void i2c_Stop(void);

// i2c_Write - Sends one byte of data
void i2c_Write(unsigned char data);

// i2c_Address - Sends Slave Address and Read/Write mode
// mode is either I2C_WRITE or I2C_READ
void i2c_Address(unsigned char address, unsigned char mode);


// i2c_Read - Reads a byte from Slave device
unsigned char i2c_Read(unsigned char ack);

#endif