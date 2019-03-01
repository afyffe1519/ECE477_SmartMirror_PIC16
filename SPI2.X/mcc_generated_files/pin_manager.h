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

// get/set SDI1 aliases
#define SDI1_TRIS                 TRISAbits.TRISA0
#define SDI1_LAT                  LATAbits.LATA0
#define SDI1_PORT                 PORTAbits.RA0
#define SDI1_WPU                  WPUAbits.WPUA0
#define SDI1_OD                   ODCONAbits.ODCA0
#define SDI1_ANS                  ANSELAbits.ANSA0
#define SDI1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SDI1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SDI1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SDI1_GetValue()           PORTAbits.RA0
#define SDI1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISAbits.TRISA1
#define CS_LAT                  LATAbits.LATA1
#define CS_PORT                 PORTAbits.RA1
#define CS_WPU                  WPUAbits.WPUA1
#define CS_OD                   ODCONAbits.ODCA1
#define CS_ANS                  ANSELAbits.ANSA1
#define CS_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define CS_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define CS_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define CS_GetValue()           PORTAbits.RA1
#define CS_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define CS_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define CS_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set DC aliases
#define DC_TRIS                 TRISAbits.TRISA4
#define DC_LAT                  LATAbits.LATA4
#define DC_PORT                 PORTAbits.RA4
#define DC_WPU                  WPUAbits.WPUA4
#define DC_OD                   ODCONAbits.ODCA4
#define DC_ANS                  ANSELAbits.ANSA4
#define DC_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define DC_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define DC_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define DC_GetValue()           PORTAbits.RA4
#define DC_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define DC_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define DC_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define DC_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define DC_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define DC_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define DC_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define DC_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISBbits.TRISB7
#define SDO1_LAT                  LATBbits.LATB7
#define SDO1_PORT                 PORTBbits.RB7
#define SDO1_WPU                  WPUBbits.WPUB7
#define SDO1_OD                   ODCONBbits.ODCB7
#define SDO1_ANS                  ANSELBbits.ANSB7
#define SDO1_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define SDO1_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define SDO1_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define SDO1_GetValue()           PORTBbits.RB7
#define SDO1_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set POT_CHANNEL aliases
#define POT_CHANNEL_TRIS                 TRISCbits.TRISC0
#define POT_CHANNEL_LAT                  LATCbits.LATC0
#define POT_CHANNEL_PORT                 PORTCbits.RC0
#define POT_CHANNEL_WPU                  WPUCbits.WPUC0
#define POT_CHANNEL_OD                   ODCONCbits.ODCC0
#define POT_CHANNEL_ANS                  ANSELCbits.ANSC0
#define POT_CHANNEL_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define POT_CHANNEL_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define POT_CHANNEL_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define POT_CHANNEL_GetValue()           PORTCbits.RC0
#define POT_CHANNEL_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define POT_CHANNEL_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define POT_CHANNEL_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define POT_CHANNEL_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define POT_CHANNEL_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define POT_CHANNEL_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define POT_CHANNEL_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define POT_CHANNEL_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set LED_D7 aliases
#define LED_D7_TRIS                 TRISCbits.TRISC5
#define LED_D7_LAT                  LATCbits.LATC5
#define LED_D7_PORT                 PORTCbits.RC5
#define LED_D7_WPU                  WPUCbits.WPUC5
#define LED_D7_OD                   ODCONCbits.ODCC5
#define LED_D7_ANS                  ANSELCbits.ANSC5
#define LED_D7_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_D7_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_D7_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_D7_GetValue()           PORTCbits.RC5
#define LED_D7_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_D7_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_D7_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED_D7_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED_D7_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED_D7_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED_D7_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED_D7_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISCbits.TRISC7
#define SCK1_LAT                  LATCbits.LATC7
#define SCK1_PORT                 PORTCbits.RC7
#define SCK1_WPU                  WPUCbits.WPUC7
#define SCK1_OD                   ODCONCbits.ODCC7
#define SCK1_ANS                  ANSELCbits.ANSC7
#define SCK1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SCK1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SCK1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SCK1_GetValue()           PORTCbits.RC7
#define SCK1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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