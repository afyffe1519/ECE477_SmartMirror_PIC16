/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18345
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "string.h"
#include "stdio.h"
void SPI_Write(char);
/*
                         Main application
 */

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    uint8_t     myWriteBuffer[2] = {0xFE, 0x61};
    uint8_t     total;
    uint8_t     myWriteBuffer1[2] = {0xFE, 0x4B};
    char * string1 = "Hello!";
    int i =0;
   
//    do
//    {
    while(1) {
        SPI_Write(0xFE);
        __delay_ms(100);
        SPI_Write(0x51);
        for(i = 0; i < 6; i++){
            SPI_Write(string1[i]);
        }
    }
}
        /*
        IO_RC0_SetLow(); 
        SPI1_Exchange8bit(0xFE);
        __delay_ms(100);
        IO_RC0_SetHigh();
//    __delay_ms(100);
    
        IO_RC0_SetLow();
        SPI1_Exchange8bit(0x51);
        __delay_ms(100);
        IO_RC0_SetHigh();
//    __delay_ms(100);
        IO_RC0_SetLow();
        SPI1_Exchange8bit('H');
        __delay_ms(100);
        IO_RC0_SetHigh();
//    __delay_ms(100);
    
        IO_RC0_SetLow();
        SPI1_Exchange8bit('I');
        __delay_ms(100);
        IO_RC0_SetHigh();
//    __delay_ms(100);
    
        __delay_ms(2000);

        IO_RC0_SetLow(); 
        SPI1_Exchange8bit(0xFE);
        __delay_ms(100);
        IO_RC0_SetHigh();
//        __delay_ms(100);
    
        IO_RC0_SetLow();
        SPI1_Exchange8bit(0x51);
        __delay_ms(100);
        IO_RC0_SetHigh();
    
        IO_RC0_SetLow();
        SPI1_Exchange8bit('I');
        __delay_ms(100);
        IO_RC0_SetHigh();
    
        IO_RC0_SetLow();
        SPI1_Exchange8bit('T');
        __delay_ms(100);
        IO_RC0_SetHigh();
        
        __delay_ms(2000);
    }
    */
        // Do something else...
//   } while(total < 2);
    
//    SPI_Write(0xFE);
 //   SPI_Write(0x51);
//    __delay_ms(100);
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();



void SPI_Write(char incoming)
{
    IO_RC0_SetLow();
    SPI1_Exchange8bit(incoming);
    IO_RC0_SetHigh();
    __delay_ms(100);
}
/**
 End of File
*/