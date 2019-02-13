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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F18345
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set MISO aliases
#define MISO_TRIS                 TRISAbits.TRISA0
#define MISO_LAT                  LATAbits.LATA0
#define MISO_PORT                 PORTAbits.RA0
#define MISO_WPU                  WPUAbits.WPUA0
#define MISO_OD                   ODCONAbits.ODCA0
#define MISO_ANS                  ANSELAbits.ANSA0
#define MISO_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define MISO_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define MISO_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define MISO_GetValue()           PORTAbits.RA0
#define MISO_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define MISO_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define MISO_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define MISO_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define MISO_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define MISO_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define MISO_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define MISO_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set MOSI aliases
#define MOSI_TRIS                 TRISBbits.TRISB7
#define MOSI_LAT                  LATBbits.LATB7
#define MOSI_PORT                 PORTBbits.RB7
#define MOSI_WPU                  WPUBbits.WPUB7
#define MOSI_OD                   ODCONBbits.ODCB7
#define MOSI_ANS                  ANSELBbits.ANSB7
#define MOSI_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define MOSI_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define MOSI_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define MOSI_GetValue()           PORTBbits.RB7
#define MOSI_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define MOSI_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define MOSI_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define MOSI_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define MOSI_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define MOSI_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define MOSI_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define MOSI_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

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

// get/set CLK aliases
#define CLK_TRIS                 TRISCbits.TRISC7
#define CLK_LAT                  LATCbits.LATC7
#define CLK_PORT                 PORTCbits.RC7
#define CLK_WPU                  WPUCbits.WPUC7
#define CLK_OD                   ODCONCbits.ODCC7
#define CLK_ANS                  ANSELCbits.ANSC7
#define CLK_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define CLK_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define CLK_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define CLK_GetValue()           PORTCbits.RC7
#define CLK_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define CLK_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define CLK_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define CLK_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define CLK_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define CLK_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define CLK_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define CLK_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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