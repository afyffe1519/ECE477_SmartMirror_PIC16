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
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/i2c2_driver.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "APDS9960.h"
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>

/*
                         Main application
 */

unsigned int id;
int t;

void handleGesture(void);
bool handleGestureFlag = 0;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    i2c2_driver_setI2cISR(handleGesture); // connect interrupt handler
    
    initialize(); // initialize APDS9960
    enablePower(); // turn on APDS9960
    enableGestureSensor(true); //


    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    mssp2_enableIRQ();
    
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {   
        // Add your application code
    }
}


void LEDs_SetLow()
{
    LED_u_SetLow();
    LED_d_SetLow();
    LED_l_SetLow();
    LED_r_SetLow();
}

void handleGesture()
{
    if(isGestureAvailable())
    {
        mssp2_clearIRQ(); // clear interrupt flag
        
        switch(readGesture())
        {
            
            case DIR_UP:
                LEDs_SetLow();
                LED_u_SetHigh();
                __delay_ms(1000);
                break;
            case DIR_DOWN:
                LEDs_SetLow();
                LED_d_SetHigh();
                __delay_ms(1000);
                break;
            case DIR_LEFT:
                LEDs_SetLow();
                LED_l_SetHigh();
                __delay_ms(1000);
                break;
            case DIR_RIGHT:
                LEDs_SetLow();
                LED_r_SetHigh();
                __delay_ms(1000);
                break;
             
            /*
            case DIR_NEAR:
                LEDs_SetLow();
                LED_l_SetHigh();
                break;
            case DIR_FAR:
                LEDs_SetLow();
                LED_r_SetHigh();
                break;
             */
            default:
                LEDs_SetLow();
                LED_u_SetHigh();
                LED_d_SetHigh();
                __delay_ms(1000);
                break;
             
        }

        LEDs_SetLow(); //reset all LEDs
        
    }
}
/**
 End of File
*/