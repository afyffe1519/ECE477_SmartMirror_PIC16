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
#include "i2c.h"
#include "APDS9960.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include <xc.h>


void SPI_Write(char);
void checkButton1(void);
void Display_Name(char*);
void Send_Names(void);
void next(void);
void Get_ADC(void);
void Display_Clear(void);

#define PRESSED         1
#define NOT_PRESSED     0
#define RUNNING         1
#define NOT_RUNNING     0
#define SECONDS_MAX     4
#define LAST            16
#define setLow()       do { LATA = 0; LATCbits.LATC5 = 0; } while(0)

uint8_t button = NOT_PRESSED;
int name = 0;
uint8_t start = 1;
uint8_t printed = 0;
char * names[4] = {"Justin Chan", "Noelle Crane", "Alexandra Fyffe", "Jeff Geiss"};
static uint8_t adcResult;

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
    
//    IOCCF1_SetInterruptHandler(GestureInterruptHandler);
    
    unsigned int count = 0;
    
    if(initialize()){
    }

    if(enableGestureSensor(false)){ // false = don't enable interrupts
    }
    Display_Name("reset");
    while (1)
    {
        if(start == 1) {
            Display_Name(names[name]);
            start = 0;
        }
        if(isGestureAvailable()){       
//            Display_Clear();
            //__delay_ms(100);
            //Display_Name("gesture available");
            handleGesture();
        }
    }
}

void handleGesture(){

    switch(readGesture()){
         case DIR_UP:
            // Display_Name("up");
            break;
        case DIR_DOWN:
            //Display_Name("down");
            break;
        case DIR_LEFT:
            printed = 0;
            //setLow();
            //D5_SetHigh();
            name++;
            if(name > 3) {
                name = 0;
            }
            Display_Name(names[name]);
/*            name++;
            if(name > 4) {
                name = 1;
            }
            Display_Clear();
            Display_Name("left");
            //Send_Names();
            //__delay_ms(1000); */
            break;
        case DIR_RIGHT:
            printed = 0;
            --name;
            if(name < 0) {
                name = 3;
            }
            Display_Name(names[name]);
            /*name--;
            if(name < 1) {
                name = 4;
            }
            Display_Clear();
            Display_Name("right");
            //Send_Names();
            //__delay_ms(1000); */
            break;
        case DIR_NEAR:
            //Display_Name("near");
            break;
        case DIR_FAR:
            //Display_Name("far");
            break;
        default:
            //Display_Name("none");
            break;
    }
    printed = 0;
}

void SPI_Write(char incoming)
{
    SPISS_SetLow();
    SPI2_Exchange8bit(incoming);
    SPISS_SetHigh();
    __delay_ms(100);
}


void Display_Name(char * string1) {
    int length;
    int i;
//    if(printed == 0) {
        SPI_Write(0xFE);
        __delay_ms(100);
        SPI_Write(0x51);
        length = strlen(string1);
        for(i = 0; i < length; i++){
            SPI_Write(string1[i]);
        }
//    }
    printed = 1;
}

void Send_Names(void) {
    switch(name) {
        case 1: Display_Name("Justin Chan");        break;
        case 2: Display_Name("Noelle Crane");       break;
        case 3: Display_Name("Alexandra Fyffe");    break;
        case 4: Display_Name("Jeff Geiss");         break;
    }
}

void Display_Clear(void) {
    SPI_Write(0xFE);
    __delay_ms(100);
    SPI_Write(0x51);
}
/**
 End of File
*/