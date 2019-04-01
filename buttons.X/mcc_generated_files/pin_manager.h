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

// get/set D5 aliases
#define D5_TRIS                 TRISAbits.TRISA1
#define D5_LAT                  LATAbits.LATA1
#define D5_PORT                 PORTAbits.RA1
#define D5_WPU                  WPUAbits.WPUA1
#define D5_OD                   ODCONAbits.ODCA1
#define D5_ANS                  ANSELAbits.ANSA1
#define D5_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define D5_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define D5_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define D5_GetValue()           PORTAbits.RA1
#define D5_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define D5_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define D5_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define D5_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define D5_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define D5_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define D5_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISAbits.TRISA2
#define D6_LAT                  LATAbits.LATA2
#define D6_PORT                 PORTAbits.RA2
#define D6_WPU                  WPUAbits.WPUA2
#define D6_OD                   ODCONAbits.ODCA2
#define D6_ANS                  ANSELAbits.ANSA2
#define D6_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define D6_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define D6_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define D6_GetValue()           PORTAbits.RA2
#define D6_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define D6_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define D6_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define D6_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define D6_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define D6_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define D6_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISAbits.TRISA5
#define D4_LAT                  LATAbits.LATA5
#define D4_PORT                 PORTAbits.RA5
#define D4_WPU                  WPUAbits.WPUA5
#define D4_OD                   ODCONAbits.ODCA5
#define D4_ANS                  ANSELAbits.ANSA5
#define D4_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define D4_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define D4_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define D4_GetValue()           PORTAbits.RA5
#define D4_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define D4_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define D4_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define D4_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define D4_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define D4_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set SDI2 aliases
#define SDI2_TRIS                 TRISBbits.TRISB4
#define SDI2_LAT                  LATBbits.LATB4
#define SDI2_PORT                 PORTBbits.RB4
#define SDI2_WPU                  WPUBbits.WPUB4
#define SDI2_OD                   ODCONBbits.ODCB4
#define SDI2_ANS                  ANSELBbits.ANSB4
#define SDI2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDI2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDI2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDI2_GetValue()           PORTBbits.RB4
#define SDI2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDI2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDI2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDI2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDI2_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SDI2_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SDI2_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDI2_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SCK2 aliases
#define SCK2_TRIS                 TRISBbits.TRISB6
#define SCK2_LAT                  LATBbits.LATB6
#define SCK2_PORT                 PORTBbits.RB6
#define SCK2_WPU                  WPUBbits.WPUB6
#define SCK2_OD                   ODCONBbits.ODCB6
#define SCK2_ANS                  ANSELBbits.ANSB6
#define SCK2_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCK2_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCK2_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCK2_GetValue()           PORTBbits.RB6
#define SCK2_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCK2_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCK2_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCK2_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCK2_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define SCK2_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define SCK2_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCK2_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set SPISS aliases
#define SPISS_TRIS                 TRISCbits.TRISC0
#define SPISS_LAT                  LATCbits.LATC0
#define SPISS_PORT                 PORTCbits.RC0
#define SPISS_WPU                  WPUCbits.WPUC0
#define SPISS_OD                   ODCONCbits.ODCC0
#define SPISS_ANS                  ANSELCbits.ANSC0
#define SPISS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SPISS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SPISS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SPISS_GetValue()           PORTCbits.RC0
#define SPISS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SPISS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SPISS_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SPISS_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SPISS_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SPISS_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SPISS_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SPISS_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SDO2 aliases
#define SDO2_TRIS                 TRISCbits.TRISC2
#define SDO2_LAT                  LATCbits.LATC2
#define SDO2_PORT                 PORTCbits.RC2
#define SDO2_WPU                  WPUCbits.WPUC2
#define SDO2_OD                   ODCONCbits.ODCC2
#define SDO2_ANS                  ANSELCbits.ANSC2
#define SDO2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SDO2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SDO2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SDO2_GetValue()           PORTCbits.RC2
#define SDO2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SDO2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SDO2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SDO2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SDO2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SDO2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SDO2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SDO2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set BTN aliases
#define BTN_TRIS                 TRISCbits.TRISC4
#define BTN_LAT                  LATCbits.LATC4
#define BTN_PORT                 PORTCbits.RC4
#define BTN_WPU                  WPUCbits.WPUC4
#define BTN_OD                   ODCONCbits.ODCC4
#define BTN_ANS                  ANSELCbits.ANSC4
#define BTN_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define BTN_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define BTN_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define BTN_GetValue()           PORTCbits.RC4
#define BTN_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define BTN_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define BTN_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define BTN_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define BTN_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define BTN_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define BTN_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define BTN_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISCbits.TRISC5
#define D7_LAT                  LATCbits.LATC5
#define D7_PORT                 PORTCbits.RC5
#define D7_WPU                  WPUCbits.WPUC5
#define D7_OD                   ODCONCbits.ODCC5
#define D7_ANS                  ANSELCbits.ANSC5
#define D7_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define D7_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define D7_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define D7_GetValue()           PORTCbits.RC5
#define D7_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define D7_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define D7_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define D7_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define D7_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define D7_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define D7_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

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