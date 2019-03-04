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

// get/set LED_l aliases
#define LED_l_TRIS                 TRISAbits.TRISA1
#define LED_l_LAT                  LATAbits.LATA1
#define LED_l_PORT                 PORTAbits.RA1
#define LED_l_WPU                  WPUAbits.WPUA1
#define LED_l_OD                   ODCONAbits.ODCA1
#define LED_l_ANS                  ANSELAbits.ANSA1
#define LED_l_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_l_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_l_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_l_GetValue()           PORTAbits.RA1
#define LED_l_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_l_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_l_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_l_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_l_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED_l_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED_l_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED_l_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED_d aliases
#define LED_d_TRIS                 TRISAbits.TRISA2
#define LED_d_LAT                  LATAbits.LATA2
#define LED_d_PORT                 PORTAbits.RA2
#define LED_d_WPU                  WPUAbits.WPUA2
#define LED_d_OD                   ODCONAbits.ODCA2
#define LED_d_ANS                  ANSELAbits.ANSA2
#define LED_d_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_d_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_d_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_d_GetValue()           PORTAbits.RA2
#define LED_d_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_d_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_d_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_d_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_d_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_d_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_d_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_d_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_RA4 aliases
#define IO_RA4_TRIS                 TRISAbits.TRISA4
#define IO_RA4_LAT                  LATAbits.LATA4
#define IO_RA4_PORT                 PORTAbits.RA4
#define IO_RA4_WPU                  WPUAbits.WPUA4
#define IO_RA4_OD                   ODCONAbits.ODCA4
#define IO_RA4_ANS                  ANSELAbits.ANSA4
#define IO_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_RA4_GetValue()           PORTAbits.RA4
#define IO_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_RA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_RA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_RA4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_RA4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LED_r aliases
#define LED_r_TRIS                 TRISAbits.TRISA5
#define LED_r_LAT                  LATAbits.LATA5
#define LED_r_PORT                 PORTAbits.RA5
#define LED_r_WPU                  WPUAbits.WPUA5
#define LED_r_OD                   ODCONAbits.ODCA5
#define LED_r_ANS                  ANSELAbits.ANSA5
#define LED_r_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_r_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_r_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_r_GetValue()           PORTAbits.RA5
#define LED_r_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_r_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_r_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_r_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_r_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_r_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_r_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED_r_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC0
#define SCL1_LAT                  LATCbits.LATC0
#define SCL1_PORT                 PORTCbits.RC0
#define SCL1_WPU                  WPUCbits.WPUC0
#define SCL1_OD                   ODCONCbits.ODCC0
#define SCL1_ANS                  ANSELCbits.ANSC0
#define SCL1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SCL1_GetValue()           PORTCbits.RC0
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC1
#define SDA1_LAT                  LATCbits.LATC1
#define SDA1_PORT                 PORTCbits.RC1
#define SDA1_WPU                  WPUCbits.WPUC1
#define SDA1_OD                   ODCONCbits.ODCC1
#define SDA1_ANS                  ANSELCbits.ANSC1
#define SDA1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SDA1_GetValue()           PORTCbits.RC1
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set LED_u aliases
#define LED_u_TRIS                 TRISCbits.TRISC5
#define LED_u_LAT                  LATCbits.LATC5
#define LED_u_PORT                 PORTCbits.RC5
#define LED_u_WPU                  WPUCbits.WPUC5
#define LED_u_OD                   ODCONCbits.ODCC5
#define LED_u_ANS                  ANSELCbits.ANSC5
#define LED_u_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_u_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_u_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_u_GetValue()           PORTCbits.RC5
#define LED_u_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_u_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_u_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED_u_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED_u_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED_u_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED_u_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED_u_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

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
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

*/
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

*/
void IOCAF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/