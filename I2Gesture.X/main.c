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

int name = 0;
int brightness = 0;
int on = 0;
int prox = 0;
uint8_t start = 1;
uint8_t printed = 0;
char * names[4] = {"Justin Chan", "Noelle Crane", "Alexandra Fyffe", "Jeff Geiss"};
static uint8_t adcResult;

/* Speaker functions and definitions */
void PWM(void);
void PWM_Output_Disable(void);
void PWM_Output_Enable(void);

static uint8_t adcResult;


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
    INTERRUPT_GlobalInterruptEnable();
    
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
//    IOCCF1_SetInterruptHandler(GestureInterruptHandler);
    Display_Clear();
    unsigned int count = 0;
    if(PIR_Sensor()) {
        if(initialize()){ // initialize i2c driver
        }
    
        if(enableGestureSensor(false)){ // false = don't use interrupts
        }
    }
    //Display_Name("reset");
   
    bool startSystem;
    int temp;
    while (1)
    {
        On_Off();
        if(on) {
            if(PIR_Sensor()) {           
                if(start == 1) {
                    Display_Name(names[name]);
                    start = 0;
                }
                Get_ADC(); // check buttons
                // mask gesture inputs unless user detected
                if( isGestureAvailable()){       
                    handleGesture();
                }
            }
        }
    }
}

/* Gesture Sensor */
void handleGesture() {
    // speaker output
//    PWM_Output_Enable();
//    __delay_ms(200);
//    PWM_Output_Disable();
    
    switch(readGesture()) {
         case DIR_UP:
            brightness++;
            if(brightness > 7) {
                brightness = 7;
            }
            break;
        case DIR_DOWN:
            --brightness;
            if(brightness < 0) {
                brightness = 0;
            }
            break;
        case DIR_LEFT: // next name
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
            printed = 0;
            --name;
            if(name < 0) {
                name = 3;
            }
            Display_Name(names[name]);
            break;
        case DIR_NEAR:
            //Display_Name("near");
            break;
        case DIR_FAR:
            //Display_Name("far");
            break;
        default:
            //                          possibly put a second line message of "gesture not read" ??
            //Display_Name("none");
            break;
    }
    printed = 0;
}

/* LCD */
void SPI_Write(char incoming) {
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

void Display_Clear(void) {
    SPI_Write(0xFE);
    __delay_ms(100);
    SPI_Write(0x51);
}

/* Speaker Code */

void PWM_Output_Enable(void) {
    RC6PPS = 0x0C; // set register to CCP1
}

void PWM_Output_Disable(void) {
    RC6PPS = 0x00; //reset register
}
/*
    PWM_Output_Enable();
    __delay_ms(200);
    PWM_Output_Disable();
*/

void Get_ADC(void) { //check values if super broken
    adcResult = ADC_GetConversion(BTN) >> 6;
    int val = adcResult;
    /*
    char string1[12];
    sprintf(string1, "%d", val);
    Display_Name(string1);
    */
    
    if(val >= 240 && val <= 254) { //on off button
        Display_Name("on");
    }
    else if(val >= 230 && val <= 239) { //toggle
        Display_Name("toggle");
    }
    else if(val >= 200 && val <= 210) { //up
        brightness++;
        if(brightness > 7) {
           brightness = 7;
        }
    }
    else if(val >= 180 && val <= 190) { //right-prev
        printed = 0;
        --name;
        if(name < 0) {
            name = 3;
        }
        Display_Name(names[name]);
    }
    else if(val >= 150 && val <= 160) { //down
        --brightness;
        if(brightness < 0) {
            brightness = 0;
        }
    }
    else if(val >= 20 && val <= 22) { //left-next
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
        if(on == 0) {
            on = 1;
            return 1;
        }
        else {
            on = 0;
            Display_Clear();
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
    char bits[4] = {tempOn, tempProx, tempName, tempBright};
    for(int i = 0; i < strlen(bits); i++) {
        while (TXSTA1bits.TRMT == 0){};
        TXREG1 = bits[i];
    }
}
 
/**
 End of File
*/