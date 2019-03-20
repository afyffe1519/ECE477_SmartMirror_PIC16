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
#define SDI1_TRIS                 TRISBbits.TRISB4
#define SDI1_LAT                  LATBbits.LATB4
#define SDI1_PORT                 PORTBbits.RB4
#define SDI1_WPU                  WPUBbits.WPUB4
#define SDI1_OD                   ODCONBbits.ODCB4
#define SDI1_ANS                  ANSELBbits.ANSB4
#define SDI1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDI1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDI1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDI1_GetValue()           PORTBbits.RB4
#define SDI1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISBbits.TRISB6
#define SCK1_LAT                  LATBbits.LATB6
#define SCK1_PORT                 PORTBbits.RB6
#define SCK1_WPU                  WPUBbits.WPUB6
#define SCK1_OD                   ODCONBbits.ODCB6
#define SCK1_ANS                  ANSELBbits.ANSB6
#define SCK1_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCK1_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCK1_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCK1_GetValue()           PORTBbits.RB6
#define SCK1_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISCbits.TRISC2
#define SDO1_LAT                  LATCbits.LATC2
#define SDO1_PORT                 PORTCbits.RC2
#define SDO1_WPU                  WPUCbits.WPUC2
#define SDO1_OD                   ODCONCbits.ODCC2
#define SDO1_ANS                  ANSELCbits.ANSC2
#define SDO1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SDO1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SDO1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SDO1_GetValue()           PORTCbits.RC2
#define SDO1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

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