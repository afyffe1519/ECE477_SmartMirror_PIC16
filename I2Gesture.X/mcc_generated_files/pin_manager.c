/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18345
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB             :  MPLAB X 5.10

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "pin_manager.h"





void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0x33;
    TRISB = 0xB0;
<<<<<<< Upstream, based on origin/master
    TRISC = 0xBA;
=======
    TRISC = 0x99;
>>>>>>> b288aef trying to integrate UART

    /**
    ANSELx registers
    */
    ANSELC = 0xE4;
    ANSELB = 0x00;
    ANSELA = 0x11;

    /**
    WPUx registers
    */
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONB = 0xF0;
    SLRCONC = 0xFF;





   
    // Enable IOCI interrupt 
    PIE0bits.IOCIE = 1; 
    
	
    RXPPS = 0x14;   //RC4->EUSART:RX;    
    SSP2DATPPS = 0x0C;   //RB4->MSSP2:SDI2;    
    SSP1CLKPPS = 0x0F;   //RB7->MSSP1:SCL1;    
    RB6PPS = 0x1A;   //RB6->MSSP2:SCK2;    
    RB7PPS = 0x18;   //RB7->MSSP1:SCL1;    
    RB5PPS = 0x00;   //RB5->MSSP1:SDA1;    
    RC2PPS = 0x1B;   //RC2->MSSP2:SDO2;    
    RC5PPS = 0x14;   //RC5->EUSART:TX;    
    SSP1DATPPS = 0x0D;   //RB5->MSSP1:SDA1;    
    SSP2CLKPPS = 0x0E;   //RB6->MSSP2:SCK2;    
}
  
void PIN_MANAGER_IOC(void)
{   
}

/**
 End of File
*/
