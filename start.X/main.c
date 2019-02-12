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
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/pwm1.h"
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

void checkButtonS1(void);
void next(void);
void HelloWorld(void);
void Blink(void);
void Rotate(void);
void ADC(void);
void VSR(void);
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

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        // Add your application code
        checkButtonS1();
        switch(event) {
            case 1: HelloWorld();   break;
            case 2: Blink();        break;
            case 3: Rotate();       break;
            case 4: ADC();          break;
            case 5: VSR();          break;
            case 6: PWM();          break;
        }
        
        if(switch1) {
            next();
        }
        
    }
}

void checkButtonS1(void){
    if(button == NOT_PRESSED){
        if(SWITCH_S1_PORT == LOW){  
            __delay_ms(100);
            button = PRESSED;
        }
    }else if(SWITCH_S1_PORT == HIGH){
            button = NOT_PRESSED;   
            switch1 = 1;                                                   
    }
}

void next(void) {
    switch1 = 0;
    if (!pause){
        event++;                                                        

        if (event > 6) {
            event = 1;
        }
    }
}

void HelloWorld(void) {
    if(state == NOT_RUNNING) {
        setLow();
        state = RUNNING;
    }
    if(state == RUNNING) {
        LED_D4_SetHigh();
    }
    if(switch1) {
        state = NOT_RUNNING;
    }
}

void Blink(void) {
    if(state == NOT_RUNNING) {
        setLow();
        TMR1_StartTimer();
        
        state = RUNNING;
    }
    
    if(state == RUNNING) {
        while(!TMR1_HasOverflowOccured());
        TMR1IF = 0;
        TMR1_Reload();
        secondCount++;
        
        if(secondCount == SECONDS_MAX) {
            LED_D4_Toggle();
            secondCount = 0;
        }
    }
    
    if(switch1) {
        TMR1_StopTimer();
        state = NOT_RUNNING;
    }
}

void Rotate(void) {
    if(state == NOT_RUNNING) {
        setLow();
        LED_D4_SetHigh();
        
        rotateVal = 1;
        
        state = RUNNING;
    }
    
    if(state == RUNNING) {
        __delay_ms(500);
        
        rotateVal <<= 1;
        
        if(rotateVal == LAST) {
            rotateVal = 1;
        }
        
        LED_D4_LAT = rotateVal & 1;
        LED_D5_LAT = (rotateVal & 2) >> 1;
        LED_D6_LAT = (rotateVal & 4) >> 2;
        LED_D7_LAT = (rotateVal & 8) >> 3;
    }
    
    if(switch1) {
        state = NOT_RUNNING;
    }
}

void ADC(void) {
    if(state == NOT_RUNNING) {
        setLow();
        
        state = RUNNING;
    }
    
    if(state == RUNNING) {
        adcResult = ADC_GetConversion(POT_CHANNEL) >> 12;
        
        LED_D4_LAT = adcResult & 1;
        LED_D5_LAT = (adcResult & 2) >> 1;
        LED_D6_LAT = (adcResult & 4) >> 2;
        LED_D7_LAT = (adcResult & 8) >> 3;
    }
    
    if(switch1) {
        state = NOT_RUNNING;
    }
}

void VSR(void) {
    if(state == NOT_RUNNING) {
        setLow();
        rotateVal = 1;
        state = RUNNING;
    }
    if(state == RUNNING) {
        delayVal = ADC_GetConversion(POT_CHANNEL) >> 8;
        __delay_ms(5);
        
        while(delayVal -- != 0) {
            __delay_ms(2);
        }
        
        LED_D4_LAT = rotateVal & 1;
        LED_D5_LAT = (rotateVal & 2) >> 1;
        LED_D6_LAT = (rotateVal & 4) >> 2;
        LED_D7_LAT = (rotateVal & 8) >> 3;
        
        rotateVal = rotateVal << 1;
        
        if(rotateVal == LAST) {
            rotateVal = 1;
        }
    }
    
    if(switch1) {
        state = NOT_RUNNING;
    }
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
    RC5PPS = 0x0C;
}

void PWM_Output_D7_Disable(void) {
    RC5PPS = 0x00;
}
/**
 End of File
*/