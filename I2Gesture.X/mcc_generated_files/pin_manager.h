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

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISBbits.TRISB5
#define SDA1_LAT                  LATBbits.LATB5
#define SDA1_PORT                 PORTBbits.RB5
#define SDA1_WPU                  WPUBbits.WPUB5
#define SDA1_OD                   ODCONBbits.ODCB5
#define SDA1_ANS                  ANSELBbits.ANSB5
#define SDA1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SDA1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SDA1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SDA1_GetValue()           PORTBbits.RB5
#define SDA1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

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

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISBbits.TRISB7
#define SCL1_LAT                  LATBbits.LATB7
#define SCL1_PORT                 PORTBbits.RB7
#define SCL1_WPU                  WPUBbits.WPUB7
#define SCL1_OD                   ODCONBbits.ODCB7
#define SCL1_ANS                  ANSELBbits.ANSB7
#define SCL1_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define SCL1_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define SCL1_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define SCL1_GetValue()           PORTBbits.RB7
#define SCL1_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

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

// get/set SPISS aliases
#define SPISS_TRIS                 TRISCbits.TRISC1
#define SPISS_LAT                  LATCbits.LATC1
#define SPISS_PORT                 PORTCbits.RC1
#define SPISS_WPU                  WPUCbits.WPUC1
#define SPISS_OD                   ODCONCbits.ODCC1
#define SPISS_ANS                  ANSELCbits.ANSC1
#define SPISS_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SPISS_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SPISS_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SPISS_GetValue()           PORTCbits.RC1
#define SPISS_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SPISS_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SPISS_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SPISS_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SPISS_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SPISS_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SPISS_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SPISS_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

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

// get/set PIR aliases
#define PIR_TRIS                 TRISCbits.TRISC3
#define PIR_LAT                  LATCbits.LATC3
#define PIR_PORT                 PORTCbits.RC3
#define PIR_WPU                  WPUCbits.WPUC3
#define PIR_OD                   ODCONCbits.ODCC3
#define PIR_ANS                  ANSELCbits.ANSC3
#define PIR_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define PIR_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define PIR_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define PIR_GetValue()           PORTCbits.RC3
#define PIR_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define PIR_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define PIR_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define PIR_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define PIR_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define PIR_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define PIR_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define PIR_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set SPKR aliases
#define SPKR_TRIS                 TRISCbits.TRISC7
#define SPKR_LAT                  LATCbits.LATC7
#define SPKR_PORT                 PORTCbits.RC7
#define SPKR_WPU                  WPUCbits.WPUC7
#define SPKR_OD                   ODCONCbits.ODCC7
#define SPKR_ANS                  ANSELCbits.ANSC7
#define SPKR_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SPKR_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SPKR_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SPKR_GetValue()           PORTCbits.RC7
#define SPKR_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SPKR_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SPKR_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SPKR_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SPKR_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SPKR_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SPKR_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define SPKR_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/