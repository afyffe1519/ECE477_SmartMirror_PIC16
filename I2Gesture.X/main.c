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

/* LCD functions and definitions */
void SPI_Write(char);
void Display_Name(char*);
void Display_Clear(void);
void Display_Brightness(void);
uint8_t brightLCD = 8;

int name = 0;
int brightness = 3;
int on = 1;
int prox = 0;
int toggle = 1;
int dummy = 1;
uint8_t start = 1;
uint8_t printed = 0;
char * names[4] = {"Justin Chan", "Noelle Crane", "Alexandra Fyffe", "Jeff Geiss"};
static uint8_t adcResult;

/* Speaker functions and definitions */
void Noise();

/* Gesture functions and definitions */
void handleGesture();
bool handleGestureFlag = 0;
void GestureInterruptHandler(){
    handleGestureFlag = 1;
}

/* PIR functions and definitions */
bool PIR_Sensor(void);

/* Button functions and definitions */
void Get_ADC(void);
bool On_Off(void);

void UART_Byte(void);

/*
                         Main application
 */

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
//    INTERRUPT_GlobalInterruptEnable();
    
    // Enable the Peripheral Interrupts
//    INTERRUPT_PeripheralInterruptEnable();
    
//    IOCCF1_SetInterruptHandler(GestureInterruptHandler);
    Display_Clear();
    while(!PIR_Sensor());
    initialize();
    enableGestureSensor(false); // false = don't use interrupts
    
    LITE_SetHigh();
    while (1) {
        On_Off();
        Display_Brightness();
        UART_Byte();
        if(on) {
            if(PIR_Sensor()) {           
                if(start == 1) {
                    Noise();
                    Display_Name(names[name]);
                    start = 0;
                }
                Get_ADC(); // check buttons
                // mask gesture inputs unless user detected
                if(toggle) {
                    if( isGestureAvailable()){       
                        handleGesture();
                    }
                }
            }
            //else {
            //    Display_Clear();
            //    start = 1;
            //    name = 0;
            //}
        }
        //else {
        //    Display_Clear();
        //    start = 1;
        //    name = 0;
        //}
       
    }
}

/* Gesture Sensor */
void handleGesture() {
    switch(readGesture()) {
         case DIR_UP:
            Noise();
            brightness--;
            if(brightness < 0) {
                brightness = 0;
            }
            //__delay_ms(200);
            break;
        case DIR_DOWN:
            Noise();
            ++brightness;
            if(brightness > 7) {
                brightness = 7;
            }
            //__delay_ms(200);
            break;
        case DIR_LEFT: // next name
            Noise();
            printed = 0;
            //setLow();
            //D5_SetHigh();
            name++;
            if(name > 3) {
                name = 0;
            }
            Display_Name(names[name]);
            break;
        case DIR_RIGHT: // prev name
            Noise();
            printed = 0;
            --name;
            if(name < 0) {
                name = 3;
            }
            Display_Name(names[name]);
            break;
        case DIR_NEAR:
            //Display_Name("near");
            __delay_ms(10);
            break;
        case DIR_FAR:
            //Display_Name("far");
            __delay_ms(10);
            break;
        default:
            //Display_Name("none");
            __delay_ms(10);
            break;
    }
    printed = 0;
}

/* LCD */
void SPI_Write(char incoming) {
    SPISS_SetLow();
    SPI2_Exchange8bit(incoming);
    SPISS_SetHigh();
    __delay_ms(10);
}

void Display_Name(char * string1) {
    int length;
    int i;
    SPI_Write(0xFE);
    __delay_ms(10);
    SPI_Write(0x51);
    length = strlen(string1);
    for(i = 0; i < length; i++){
        SPI_Write(string1[i]);
    }
    printed = 1;
}

void Display_Clear(void) {
    SPI_Write(0xFE);
    __delay_ms(10);
    SPI_Write(0x51);
}

void Display_Brightness(void) {
    SPI_Write(0xFE);
    __delay_ms(10);
    SPI_Write(0x53);
    __delay_ms(10);
    SPI_Write(brightLCD);
}
/* Speaker Code */
void Noise(void){
    PWM1_LoadDutyValue(80);
    RC6PPS = 0x0C; // set register to CCP1
    __delay_ms(100);
    RC6PPS = 0x00; //reset register
}

void Get_ADC(void) { //check values if super broken
    adcResult = ADC_GetConversion(BTN) >> 6;
    int val = adcResult;
    /*
    char string1[12];
    sprintf(string1, "%d", val);
    Display_Name(string1);
        
    if(val >= 240 && val <= 254) { //on off button
        //Display_Name("on");
    }
 
    else */ 
    if(val >= 230 && val <= 239) { //toggle
        Noise();
        if(toggle == 0) {
            toggle = 1;
            LITE_SetHigh();
        }
        else {
            toggle = 0;
            LITE_SetLow();
        }
    }
    else if(val >= 200 && val <= 210) { //up
        Noise();
        brightness--;
        if(brightness < 0) {
           brightness = 0;
        }   
//        __delay_ms(200);
         
    }
    else if(val >= 180 && val <= 190) { //right-prev
        Noise();
        printed = 0;
        --name;
        if(name < 0) {
            name = 3;
        }
        Display_Name(names[name]);
    }
    else if(val >= 150 && val <= 160) { //down
        Noise();
        ++brightness;
        if(brightness > 7) {
            brightness = 7;
        }
//        __delay_ms(200);
    }
    else if(val >= 120 && val <= 130) { //left-next
        Noise();
        printed = 0;
        name++;
        if(name > 3) {
           name = 0;
        }
        Display_Name(names[name]);
    }
    adcResult = 0;
    
}

bool On_Off(void) {
    adcResult = ADC_GetConversion(BTN) >> 6;
    int val = adcResult;
    if(val >= 240 && val <= 254) { //on off button
        Noise();
        if(on == 0) {
            on = 1;
            brightLCD = 8;
            return 1;
        }
        else {
            on = 0;
            brightLCD = 1;
            start = 1;
            name = 0;
            return 0;
        }
    }
    return on;
}

/* PIR */
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

void UART_Byte(void) {
    int tempOn = on + 1;
    int tempProx = prox + 1;
    int tempName = name + 1;
    int tempBright = brightness + 1;
    char bits[5] = {'A', tempOn, tempProx, tempName, tempBright};
    for(int i = 0; i < strlen(bits); i++) {
        while (TXSTA1bits.TRMT == 0){};
        TXREG1 = bits[i];
    }
}
 
/**
 End of File
*/