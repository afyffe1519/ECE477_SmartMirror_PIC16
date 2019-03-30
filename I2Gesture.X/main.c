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
#include "i2c.h"
#include "APDS9960.h"
/*
                         Main application
 */

void handleGesture();
bool handleGestureFlag = 0;

void GestureInterruptHandler(){
    handleGestureFlag = 1;
}
//void I2CDriverHandler(){
    
//}
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    IOCCF1_SetInterruptHandler(GestureInterruptHandler);
    //i2c1_driver_setI2cISR(I2CDriverHandler);
    
    //PEIE = 1;
    //GIE = 1;
    //OPTION_REG = 0;
    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    //i2c_setAddress(APDS9960_I2C_ADDR);
    /*
    LED_u_SetHigh();
    if(initialize()){
        LED_d_SetHigh();
    }
    
    
    */
    unsigned int count = 0;
    
    if(initialize()){
       LED_d_SetHigh();
    }
    if(enableGestureSensor(true)){
        //LED_r_SetHigh();
    }
    
    //LED_r_SetLow();
    while (1)
    {
        //initialize();
        //enableGestureSensor(true);
        //__delay_ms(100
        
        if(isGestureAvailable()){       
            LED_u_SetHigh();
            handleGesture();
            //__delay_ms(1);
            /*
            wireReadDataByte(APDS9960_GFIFO_U);
            __delay_ms(1);
            wireReadDataByte(APDS9960_GFIFO_D);
            __delay_ms(1);
            wireReadDataByte(APDS9960_GFIFO_L);
            __delay_ms(1);
            wireReadDataByte(APDS9960_GFIFO_R);
             * */
        }
        
        //if(i2c1_driver_isBufferFull() == 0){
            
           //SSP1CON2bits.PEN = 1;
        //}
        //else{
           //LED_l_SetHigh(); 
        //}
            
        //if(isGestureAvailable()){
          //  LED_u_SetHigh();
            //handleGesture();
        //}
           
        /*
        if(handleGestureFlag){
            LED_l_SetHigh();
            handleGesture();
            handleGestureFlag = 0;
        }
        */
        // Add your application code
    }
}
void LEDs_SetLow(){
    LED_u_SetLow();
    LED_d_SetLow();
    LED_l_SetLow();
    LED_r_SetLow();
}
void handleGesture(){
    //if (isGestureAvailable()){
        switch(readGesture()){
             case DIR_UP:
                LED_u_SetHigh();
                __delay_ms(1000);
                LEDs_SetLow();
                break;
            case DIR_DOWN:
                
                LED_d_SetHigh();
                __delay_ms(1000);
                LEDs_SetLow();
                break;
            case DIR_LEFT:
                LED_l_SetHigh();
                __delay_ms(1000);
                LEDs_SetLow();
                break;
            case DIR_RIGHT:
                LED_r_SetHigh();
                __delay_ms(1000);
                LEDs_SetLow();
                break;
        }
    //}
}

/**
 End of File
*/