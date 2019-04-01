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

#define PRESSED         1
#define NOT_PRESSED     0
#define RUNNING         1
#define NOT_RUNNING     0
#define SECONDS_MAX     4
#define LAST            16
#define setLow()       do { LATA = 0; LATCbits.LATC5 = 0; } while(0)

uint8_t button = NOT_PRESSED;
uint8_t switch1 = 0;
int name = 0;
uint8_t start = 1;
uint8_t printed = 0;
uint8_t right = 1;
char * names[4] = {"Justin Chan", "Noelle Crane", "Alexandra Fyffe", "Jeff Geiss"};
static uint8_t adcResult;
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
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        Get_ADC();
    }
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

void checkButton1(void){
    char string1[12];
    if(button == NOT_PRESSED){
        if(BTN_PORT == LOW){  
            __delay_ms(100);
            button = PRESSED;
        }
    }else if(BTN_PORT == HIGH){
            button = NOT_PRESSED;   
            switch1 = 1;
            adcResult = ADC_GetConversion(BTN) >> 12;
            sprintf(string1, "%d", adcResult);
            Display_Name(string1);
    }
}

void Send_Names(void) {
    switch(name) {
        case 1: Display_Name("Justin Chan");        break;
        case 2: Display_Name("Noelle Crane");       break;
        case 3: Display_Name("Alexandra Fyffe");    break;
        case 4: Display_Name("Jeff Geiss");         break;
    }
        
    if(switch1) {
        next();
    }
}
void next(void) {
    switch1 = 0;
    printed = 0;
    if(right) {
        name--;
    }
    else {
        name++;
    }
    if (name > 3) {
        name = 0;
    }
    else if(name < 0) {
        name = 3;
    }
}


void Get_ADC(void) {
    checkButton1();
    if(start == 1) {
        Display_Name(names[name]);
        start = 0;
    }
    adcResult = ADC_GetConversion(BTN) >> 8;
    int val = adcResult;
    if(val >= 175 && val <= 180) { //on off button
        setLow();
        D4_SetHigh();
        Display_Name(names[name]);
    }
    else if(val >= 181 && val <= 185) { //toggle
    }
    else if(val >= 186 && val <= 195) { //up
    }
    else if(val >= 196 && val <= 200) { //right-prev
        printed = 0;
        setLow();
        D6_SetHigh();
        --name;
        if(name < 0) {
            name = 3;
        }
        Display_Name(names[name]);
    }
    else if(val >= 201 && val <= 205) { //down
    }
    else if(val >= 217 && val <= 220) { //left-next
        printed = 0;
        setLow();
        D5_SetHigh();
        name++;
        if(name > 3) {
           name = 0;
        }
        Display_Name(names[name]);
    }
}
/**
 End of File
*/