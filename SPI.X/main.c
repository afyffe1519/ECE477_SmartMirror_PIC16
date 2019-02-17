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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
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
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/pwm1.h"
#include "header_files/Adafruit-GFX-Library-master/"
#include <xc.h>

#define setLow()       do { LATA = 0; LATCbits.LATC5 = 0; } while(0)

#define PRESSED         1
#define NOT_PRESSED     0
#define RUNNING         1
#define NOT_RUNNING     0
#define SECONDS_MAX     4
#define LAST            16

static uint8_t adcResult;
static uint16_t adcResult2;
static uint8_t secondCount = 0;
static uint8_t rotateVal;
static uint8_t delayVal;
uint8_t switch1 = 0;
uint8_t button = NOT_PRESSED;
uint8_t event = 1;
uint8_t state = NOT_RUNNING;
uint8_t pause = 0;

void SPI(void);
void PWM(void);
void PWM_Output_D7_Enable(void);
void PWM_Output_D7_Disable(void);
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
    while(1) {
        SPI();
    }

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        SPI();
    }
}

void SPI(void) {
    PWM();
    SPI1_Exchange8bit('A');
    
}

void PWM(void) {
    if(state == NOT_RUNNING) {
        setLow();
        PWM_Output_D7_Enable();
        TMR2_StartTimer();
        pause = 1;
        state = RUNNING;
    }
    
    if(state == RUNNING) {
        adcResult2 = ADC_GetConversion(POT_CHANNEL) >> 6;
        PWM1_LoadDutyValue(adcResult2);
    }
    
    if (button == PRESSED){
        PWM_Output_D7_Enable();
        __delay_ms(100);
        PWM_Output_D7_Disable();
    }
    
    //if(switch1) {
        //TMR2_StopTimer();
        //state = NOT_RUNNING; 
    //} 
}

void PWM_Output_D7_Enable(void) {
    RA1PPS = 0x0C;
}

void PWM_Output_D7_Disable(void) {
    RA1PPS = 0x00;
}
/**
 End of File
*/