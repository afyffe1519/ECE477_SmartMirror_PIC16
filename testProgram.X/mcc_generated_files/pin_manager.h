/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18345
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_ind aliases
#define LED_ind_TRIS                 TRISAbits.TRISA2
#define LED_ind_LAT                  LATAbits.LATA2
#define LED_ind_PORT                 PORTAbits.RA2
#define LED_ind_WPU                  WPUAbits.WPUA2
#define LED_ind_OD                   ODCONAbits.ODCA2
#define LED_ind_ANS                  ANSELAbits.ANSA2
#define LED_ind_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_ind_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_ind_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_ind_GetValue()           PORTAbits.RA2
#define LED_ind_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_ind_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_ind_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ind_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_ind_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_ind_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_ind_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_ind_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set PIR_sensor aliases
#define PIR_sensor_TRIS                 TRISCbits.TRISC3
#define PIR_sensor_LAT                  LATCbits.LATC3
#define PIR_sensor_PORT                 PORTCbits.RC3
#define PIR_sensor_WPU                  WPUCbits.WPUC3
#define PIR_sensor_OD                   ODCONCbits.ODCC3
#define PIR_sensor_ANS                  ANSELCbits.ANSC3
#define PIR_sensor_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define PIR_sensor_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define PIR_sensor_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define PIR_sensor_GetValue()           PORTCbits.RC3
#define PIR_sensor_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define PIR_sensor_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define PIR_sensor_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define PIR_sensor_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define PIR_sensor_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define PIR_sensor_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define PIR_sensor_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define PIR_sensor_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/