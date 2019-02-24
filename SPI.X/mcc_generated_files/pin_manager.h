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