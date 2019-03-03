
/* I2C library*/

#include <xc.h>
#include "i2c.h"
#include "mcc.h"
#include "i2c1_driver.h"



// The flag to indicate whether an I2C error has occured.
unsigned char b_i2c_error_flag = 0;

// Function Purpose: Configure I2C module
void InitI2C(void)
{	
        
  SDA_DIR = 1;		// Make SDA and
	SCK_DIR = 1;		// SCK pins input
    
	SSPADD  = ((_XTAL_FREQ/4000)/I2C_SPEED) - 1;	
	SSPSTAT = 0x80;		// Slew Rate control is disabled
	SSPCON  = 0x28;		// Select and enable I2C in master mode
  
}

unsigned char b_i2c_check_error_flag(void)
{
	return b_i2c_error_flag;	
}

// Function Purpose: I2C_Start sends start bit sequence
void I2C_Start(void)
{
	SSP1CON2bits.SEN = 1;		// Send start bit
	while( SSP1CON2bits.SEN == 1);		// Wait for it to complete	
}

// Function Purpose: I2C_ReStart sends start bit sequence
void I2C_ReStart(void)
{
	SSP1CON2bits.RSEN = 1;			// Send Restart bit
	while(SSP1CON2bits.RSEN == 1);		// Wait for it to complete
}

//Function : I2C_Stop sends stop bit sequence
void I2C_Stop(void)
{
	SSP1CON2bits.PEN=1;      // Enable the Stop bit  
  while (SSP1CON2bits.PEN == 1); // waits till stob bit is enable
}

//Function : I2C_Send_ACK sends ACK bit sequence
void I2C_Send_ACK(void)
{
	SSP1CON2bits.ACKDT = 0;			// 0 means ACK
	SSP1CON2bits.ACKEN = 1;			// Send ACKDT value
	while(SSP1CON2bits.ACKEN == 1);		// Wait for it to complete			
}

//Function : I2C_Send_NACK sends NACK bit sequence
void I2C_Send_NACK(void)
{
	SSP1CON2bits.ACKDT=1;    // Acknowledge the operation (Send NACK)    
   SSP1CON2bits.ACKEN=1;    // Acknowledge sequence on SDA & SCL pins  
   while (SSP1CON2bits.ACKEN == 1);
}

// Function Purpose: I2C_Write_Byte transfers one byte
void I2C_Write_Byte(unsigned char Byte)
{
  // Clear the error flag before we start a new I2C operation.
	b_i2c_error_flag = 0;
	SSPBUF = Byte;		// Send Byte value
	while (SSPSTATbits.R_nW == 1);// Wait for slave to acknowledge.
  
	// If slave does not acknowledge...
	if (SSP1CON2bits.ACKSTAT == 1) {
		// Send stop bit.
		SSP1CON2bits.PEN = 1;
		while (SSP1CON2bits.PEN == 1);
		
		// Set the error flag and exit.
		b_i2c_error_flag = 1;
		return;
	}
	
}

// Function Purpose: I2C_Read_Byte reads one byte
unsigned char I2C_Read_Byte(void )
{
  SSP1CON2bits.RCEN=1;        // Enable to receive data    
        
    // Wait until the data is received.
	unsigned long count = 10000L;
	while (SSP1STATbits.BF == 0) {
		
		// If timeout..
		if (--count == 0) {
			// Send stop bit.
			SSP1CON2bits.PEN = 1;
			while (SSP1CON2bits.PEN == 1);
			
			// Set the error flag and exit.
			b_i2c_error_flag = 1;
			return 0;
		}
	}
 
  return SSPBUF;		// Return received byte
}

