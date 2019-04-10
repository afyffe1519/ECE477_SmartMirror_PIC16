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
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/pwm1.h"
#include <xc.h>

/* Gesture functions and definitions */
void handleGesture();
bool handleGestureFlag = 0;
void GestureInterruptHandler(){
    handleGestureFlag = 1;
}

/* LCD functions and definitions */
void SPI_Write(char);
void Display_Name(char*);
void Display_Clear(void);
char * names[4] = {"Justin Chan", "Noelle Crane", "Alexandra Fyffe", "Jeff Geiss"};
int name = 0;
uint8_t printed = 0;
uint8_t start = 1;

/* Speaker functions and definitions */
void PWM_Output_Disable(void);
void PWM_Output_Enable(void);

/* Button functions and definitions */
void Get_ADC(void);
bool On_Off(void);
void Toggle(void);
uint8_t on = 1;
int brightness = 0;
uint8_t gestureToggle = 1;
static uint8_t adcResult;

/* PIR functions and definitions */
bool PIR_Sensor(void);
uint8_t prox = 0;

/* UART functions and definitions */
void UART_Byte(void);

/**************************************MAIN************************************/
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

    Display_Clear();
//    unsigned int count = 0;
//    while(On_Off() != 1);
//    if(PIR_Sensor()) {
//        initialize();// initialize i2c driver
//        enableGestureSensor(false); // false = don't use interrupts
//    }
    while (1)
    {
//        On_Off();
//        UART_Byte();
//        PIR_Sensor();
//        if(on) {
//            if(prox) {          
//                if(start == 1) {         // start displaying at Justin's profile
//                    Display_Name(names[name]);
//                    start = 0;
//                }
                Get_ADC(); // check buttons
                // mask gesture inputs unless user detected
//                if(gestureToggle == 1) {
//                    if( isGestureAvailable()){       
//                        handleGesture();
//                    }
//                }
//            }
//        }
    }
}

/*******************************GESTURE SENSOR*********************************/
void handleGesture() {
    switch(readGesture()) {
        case DIR_UP: //increase brightness
            brightness++;
            if(brightness >  7) {
                brightness = 7;
            } 
            break;
        case DIR_DOWN: //decrease brightness
            brightness--;
            if(brightness < 0) {
                brightness = 0;
            }
            break;
        case DIR_LEFT: // next name
            printed = 0;
            name++;
            if(name > 3) {
                name = 0;
            }
            Display_Name(names[name]);
            break;
        case DIR_RIGHT: // prev name
            printed = 0;
            --name;
            if(name < 0) {
                name = 3;
            }
            Display_Name(names[name]);
            break;
        case DIR_NEAR:
            break;
        case DIR_FAR:
            break;
        default:
            break;
    }
    printed = 0;
}

/***********************************LCD****************************************/
void SPI_Write(char incoming) {
    SPISS_SetLow();
    SPI2_Exchange8bit(incoming);
    SPISS_SetHigh();
    __delay_ms(100);
}

void Display_Name(char * string1) {
    int length;
    int i;
//    PWM_Output_Enable();
//    __delay_ms(200);
//    PWM_Output_Disable();
    SPI_Write(0xFE);
    __delay_ms(100);
    SPI_Write(0x51);
    length = strlen(string1);
    for(i = 0; i < length; i++){
        SPI_Write(string1[i]);
    }
    printed = 1;
}

void Display_Clear(void) {
    SPI_Write(0xFE);
    __delay_ms(100);
    SPI_Write(0x51);
}

/*********************************SPEAKER**************************************/
void PWM_Output_Enable(void) {
    RC6PPS = 0x0C; // set register to CCP1
}

void PWM_Output_Disable(void) {
    RC6PPS = 0x00; //reset register
}

/*********************************BUTTONS**************************************/
void Get_ADC(void) { //check values if super broken
    adcResult = ADC_GetConversion(BTN) >> 6;
    char * string1[12];
    int val = adcResult;
    sprintf(string1, "%d", adcResult);
/*    if(val >= 215 && val <= 225) { //toggle gesture sensor
        Toggle();
    }
    else if(val >= 165 && val <= 180) { //up - increase brightness
        brightness++;
        if(brightness >  7) {
            brightness = 7;
        }
    }
    else if(val >= 140 && val <= 155) { //right - previous name
        printed = 0;
        --name;
        if(name < 0) {
            name = 3;
        }
        Display_Name(names[name]);
    }
    else if(val >= 90 && val <= 120) { //down - decrease brightness
        brightness--;
        if(brightness < 0) {
            brightness = 0;
        }
    }
    else if(val >= 200 && val <= 230) { //left - next name
        printed = 0;
        name++;
        if(name > 3) {
           name = 0;
        }
        Display_Name(names[name]);
    }
 
    adcResult = 0;
 */
}

bool On_Off(void) {
    adcResult = ADC_GetConversion(BTN) >> 6;
    int val = adcResult;
    if(val >= 10 && val <= 20) { //on off button
        if(on == 0) {
            on = 1;
        }
        else {
            on = 0;
        }
    }
    return on;
}

void Toggle(void) {
    if(gestureToggle == 0) {
        gestureToggle = 1;
    }
    else {
        gestureToggle = 0;
    }
}

/*************************************PIR**************************************/
bool PIR_Sensor(void){
    if(PIR_GetValue() >= 1){
        prox = 1;
        return 1;
    }
    else{
        prox = 0;
        return 0;
    }
}

/*************************************UART*************************************/
void UART_Byte(void) {
    char bits[7];
    char * onStr;
    char * proxStr;
    char * profileStr;
    char * brightStr;
    sprintf(onStr, "%d", on);
    sprintf(proxStr, "%d", prox);
    sprintf(profileStr, "%d", name);
    sprintf(brightStr, "%d", brightness);
    strcpy(bits, onStr);
    strcat(bits, proxStr);
    strcat(bits, profileStr);
    strcat(bits, brightStr);
    
    while(TXSTA1bits.TRMT == 0){};
    TXREG1 = bits;
}
/**
 End of File
*/
