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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
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

#include <xc.h>
#include <string.h>

#define setLow()       do { LATA = 0; LATCbits.LATC5 = 0; } while(0)

#define PRESSED         1
#define NOT_PRESSED     0
#define RUNNING         1
#define NOT_RUNNING     0
#define SECONDS_MAX     4
#define LAST            16
#define _width         128
#define _height        160

int wrap = true;
#define _swap(a, b) { signed int16 t; t = a; a = b; b = t;}
#define _width         128
#define _height        160
#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09
#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13
#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E
#define ST7735_PTLAR   0x30
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36
#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6
#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5
#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD
#define ST7735_PWCTR6  0xFC
#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1
// Color definitions
#define   ST7735_BLACK   0x0000
#define   ST7735_BLUE    0x001F
#define   ST7735_RED     0xF800
#define   ST7735_GREEN   0x07E0
#define   ST7735_CYAN    0x07FF
#define   ST7735_MAGENTA 0xF81F
#define   ST7735_YELLOW  0xFFE0
#define   ST7735_WHITE   0xFFFF
const char Font[] = {
0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x5F, 0x00, 0x00,
0x00, 0x07, 0x00, 0x07, 0x00,
0x14, 0x7F, 0x14, 0x7F, 0x14,
0x24, 0x2A, 0x7F, 0x2A, 0x12,
0x23, 0x13, 0x08, 0x64, 0x62,
0x36, 0x49, 0x56, 0x20, 0x50,
0x00, 0x08, 0x07, 0x03, 0x00,
0x00, 0x1C, 0x22, 0x41, 0x00,
0x00, 0x41, 0x22, 0x1C, 0x00,
0x2A, 0x1C, 0x7F, 0x1C, 0x2A,
0x08, 0x08, 0x3E, 0x08, 0x08,
0x00, 0x80, 0x70, 0x30, 0x00,
0x08, 0x08, 0x08, 0x08, 0x08,
0x00, 0x00, 0x60, 0x60, 0x00,
0x20, 0x10, 0x08, 0x04, 0x02,
0x3E, 0x51, 0x49, 0x45, 0x3E,
0x00, 0x42, 0x7F, 0x40, 0x00,
0x72, 0x49, 0x49, 0x49, 0x46,
0x21, 0x41, 0x49, 0x4D, 0x33,
0x18, 0x14, 0x12, 0x7F, 0x10,
0x27, 0x45, 0x45, 0x45, 0x39,
0x3C, 0x4A, 0x49, 0x49, 0x31,
0x41, 0x21, 0x11, 0x09, 0x07,
0x36, 0x49, 0x49, 0x49, 0x36,
0x46, 0x49, 0x49, 0x29, 0x1E,
0x00, 0x00, 0x14, 0x00, 0x00,
0x00, 0x40, 0x34, 0x00, 0x00,
0x00, 0x08, 0x14, 0x22, 0x41,
0x14, 0x14, 0x14, 0x14, 0x14,
0x00, 0x41, 0x22, 0x14, 0x08,
0x02, 0x01, 0x59, 0x09, 0x06,
0x3E, 0x41, 0x5D, 0x59, 0x4E,
0x7C, 0x12, 0x11, 0x12, 0x7C,
0x7F, 0x49, 0x49, 0x49, 0x36,
0x3E, 0x41, 0x41, 0x41, 0x22,
0x7F, 0x41, 0x41, 0x41, 0x3E,
0x7F, 0x49, 0x49, 0x49, 0x41,
0x7F, 0x09, 0x09, 0x09, 0x01,
0x3E, 0x41, 0x41, 0x51, 0x73,
0x7F, 0x08, 0x08, 0x08, 0x7F,
0x00, 0x41, 0x7F, 0x41, 0x00,
0x20, 0x40, 0x41, 0x3F, 0x01,
0x7F, 0x08, 0x14, 0x22, 0x41,
0x7F, 0x40, 0x40, 0x40, 0x40,
0x7F, 0x02, 0x1C, 0x02, 0x7F,
0x7F, 0x04, 0x08, 0x10, 0x7F,
0x3E, 0x41, 0x41, 0x41, 0x3E,
0x7F, 0x09, 0x09, 0x09, 0x06,
0x3E, 0x41, 0x51, 0x21, 0x5E,
0x7F, 0x09, 0x19, 0x29, 0x46
};
const char Font2[] = {
0x26, 0x49, 0x49, 0x49, 0x32,
0x03, 0x01, 0x7F, 0x01, 0x03,
0x3F, 0x40, 0x40, 0x40, 0x3F,
0x1F, 0x20, 0x40, 0x20, 0x1F,
0x3F, 0x40, 0x38, 0x40, 0x3F,
0x63, 0x14, 0x08, 0x14, 0x63,
0x03, 0x04, 0x78, 0x04, 0x03,
0x61, 0x59, 0x49, 0x4D, 0x43,
0x00, 0x7F, 0x41, 0x41, 0x41,
0x02, 0x04, 0x08, 0x10, 0x20,
0x00, 0x41, 0x41, 0x41, 0x7F,
0x04, 0x02, 0x01, 0x02, 0x04,
0x40, 0x40, 0x40, 0x40, 0x40,
0x00, 0x03, 0x07, 0x08, 0x00,
0x20, 0x54, 0x54, 0x78, 0x40,
0x7F, 0x28, 0x44, 0x44, 0x38,
0x38, 0x44, 0x44, 0x44, 0x28,
0x38, 0x44, 0x44, 0x28, 0x7F,
0x38, 0x54, 0x54, 0x54, 0x18,
0x00, 0x08, 0x7E, 0x09, 0x02,
0x18, 0xA4, 0xA4, 0x9C, 0x78,
0x7F, 0x08, 0x04, 0x04, 0x78,
0x00, 0x44, 0x7D, 0x40, 0x00,
0x20, 0x40, 0x40, 0x3D, 0x00,
0x7F, 0x10, 0x28, 0x44, 0x00,
0x00, 0x41, 0x7F, 0x40, 0x00,
0x7C, 0x04, 0x78, 0x04, 0x78,
0x7C, 0x08, 0x04, 0x04, 0x78,
0x38, 0x44, 0x44, 0x44, 0x38,
0xFC, 0x18, 0x24, 0x24, 0x18,
0x18, 0x24, 0x24, 0x18, 0xFC,
0x7C, 0x08, 0x04, 0x04, 0x08,
0x48, 0x54, 0x54, 0x54, 0x24,
0x04, 0x04, 0x3F, 0x44, 0x24,
0x3C, 0x40, 0x40, 0x20, 0x7C,
0x1C, 0x20, 0x40, 0x20, 0x1C,
0x3C, 0x40, 0x30, 0x40, 0x3C,
0x44, 0x28, 0x10, 0x28, 0x44,
0x4C, 0x90, 0x90, 0x90, 0x7C,
0x44, 0x64, 0x54, 0x4C, 0x44,
0x00, 0x08, 0x36, 0x41, 0x00,
0x00, 0x00, 0x77, 0x00, 0x00,
0x00, 0x41, 0x36, 0x08, 0x00,
0x02, 0x01, 0x02, 0x04, 0x02
};

uint8_t colstart = 0;
uint8_t rowstart = 0;
char *txt = "Hello World";
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
void fillScreen(uint16_t color);
void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color);
void setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
void write_command(uint8_t cmd);
void write_data(uint8_t data);
void spiwrite(uint8_t spidata);
void Rcmd1(void);
void Rcmd2red(void);
void Rcmd3(void);
void drawtext(uint8_t x, uint8_t y, char *_text, uint16_t color, uint16_t bg, uint8_t size);
void drawChar(uint8_t x, uint8_t y, uint8_t c, uint16_t color, uint16_t bg,  uint8_t size);
void drawPixel(uint8_t x, uint8_t y, uint16_t color);
void setTextWrap(int w);
void BlackTab_Init(void);
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

//    while (1)
//    {
        SPI();
//    }
}

void SPI(void) {
    PWM();
  //  SPI1_Initialize();
 //   uint8_t     myWriteBuffer[2] = {0xFE, 0x42};
 //   uint8_t     total;
//    uint8_t     myWriteBuffer1[2] = {0xFE, 0x4B};

    SPI1_Initialize();

//    total = 0;
//    do
//    {
//        total = SPI1_Exchange8bitBuffer(&myWriteBuffer[total], 2 - total, &myWriteBuffer[total]);
//        __delay_ms(1000);
        // Do something else...
//    } while(total < 2);
    BlackTab_Init();
    fillScreen(ST7735_BLACK);
    drawtext(0, 5, txt, ST7735_WHITE, ST7735_BLACK, 1);
    setTextWrap(false);
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
    
        //TMR2_StopTimer();
        //state = NOT_RUNNING; 
    //if(switch1) {
    //} 
}

void PWM_Output_D7_Enable(void) {
    RC5PPS = 0x0C;
}

void PWM_Output_D7_Disable(void) {
    RC5PPS = 0x00;
}

void BlackTab_Init(void){
    CS_SetHigh();
    DC_SetLow();
    SCK1_SetLow();
    SDO1_SetLow();
    
    Rcmd1();
    Rcmd2red();
    Rcmd3();
    write_command(ST7735_MADCTL);
    write_data(0xC0);
}
void fillScreen(uint16_t color) {
    fillRect(0,0, _width, _height, color);
}

void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint16_t color) {
    uint8_t high;
    uint8_t low;
    if((x >= _width) || (y >= _height)) return;
    if((x + w - 1) >= _width) w = _width - x;
    if((y + h - 1) >= _height) h = _height - y;
    
    setAddrWindow(x, y, x+w-1, y+h-1);
    high = color >> 8; low = color;
    DC_SetHigh();
    CS_SetLow();
    for(y=h; y>0; y--) {
        for(x = w; x > 0; x--) {
            spiwrite(high);
            spiwrite(low);
        }
    }
  CS_SetHigh();
}

void setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1) {
    write_command(ST7735_CASET);
    write_data(0);
    write_data(x0 + colstart);
    write_data(0);
    write_data(x1 + colstart);
    write_command(ST7735_RASET);
    write_data(0);
    write_data(y0+rowstart);
    write_data(0);
    write_data(y1+rowstart);
    write_command(ST7735_RAMWR);
}

void write_command(uint8_t cmd) {
    DC_SetLow();
    CS_SetLow();
    
    spiwrite(cmd);
    
    CS_SetHigh();
}

void write_data(uint8_t data) {
    CS_SetLow();
    DC_SetHigh();
    
    spiwrite(data);
    
    CS_SetHigh();
}

void spiwrite(uint8_t spidata){
    int ss;
    for(ss = 0x80; ss; ss >>= 1) {
        if (spidata & ss) {
            SDO1_SetHigh();
        }
        else {
            SDO1_SetLow();
        }
        SCK1_SetHigh();
        SCK1_SetLow();
    }
}

void Rcmd1(){
  write_command(ST7735_SWRESET);
  __delay_ms(150);
  write_command(ST7735_SLPOUT);
  __delay_ms(500);
  write_command(ST7735_FRMCTR1);
  write_data(0x01);
  write_data(0x2C);
  write_data(0x2D);
  write_command(ST7735_FRMCTR2);
  write_data(0x01);
  write_data(0x2C);
  write_data(0x2D);
  write_command(ST7735_FRMCTR3);
  write_data(0x01); write_data(0x2C); write_data(0x2D);
  write_data(0x01); write_data(0x2C); write_data(0x2D);
  write_command(ST7735_INVCTR);
  write_data(0x07);
  write_command(ST7735_PWCTR1);
  write_data(0xA2);
  write_data(0x02);
  write_data(0x84);
  write_command(ST7735_PWCTR2);
  write_data(0xC5);
  write_command(ST7735_PWCTR3);
  write_data(0x0A);
  write_data(0x00);
  write_command(ST7735_PWCTR4);
  write_data(0x8A);
  write_data(0x2A);
  write_command(ST7735_PWCTR5);
  write_data(0x8A);
  write_data(0xEE);
  write_command(ST7735_VMCTR1);
  write_data(0x0E);
  write_command(ST7735_INVOFF);
  write_command(ST7735_MADCTL);
  write_data(0xC8);
  write_command(ST7735_COLMOD);
  write_data(0x05); 
}

void Rcmd2red(){
  write_command(ST7735_CASET);
  write_data(0x00); write_data(0x00);
  write_data(0x00); write_data(0x7F);
  write_command(ST7735_RASET);
  write_data(0x00); write_data(0x00);
  write_data(0x00); write_data(0x9F);
}

void Rcmd3(){
  write_command(ST7735_GMCTRP1);
  write_data(0x02); write_data(0x1C); write_data(0x07); write_data(0x12);
  write_data(0x37); write_data(0x32); write_data(0x29); write_data(0x2D);
  write_data(0x29); write_data(0x25); write_data(0x2B); write_data(0x39);
  write_data(0x00); write_data(0x01); write_data(0x03); write_data(0x10);
  write_command(ST7735_GMCTRN1);
  write_data(0x03); write_data(0x1D); write_data(0x07); write_data(0x06);
  write_data(0x2E); write_data(0x2C); write_data(0x29); write_data(0x2D);
  write_data(0x2E); write_data(0x2E); write_data(0x37); write_data(0x3F);
  write_data(0x00); write_data(0x00); write_data(0x02); write_data(0x10);
  write_command(ST7735_NORON);
  __delay_ms(10);
  write_command(ST7735_DISPON);
  __delay_ms(100);
}

void drawtext(uint8_t x, uint8_t y, char *_text, uint16_t color, uint16_t bg, uint8_t size){
  uint8_t cursor_x, cursor_y;
  uint16_t textsize, i;
  cursor_x = x, cursor_y = y;
  textsize = strlen(_text);
  for(i = 0; i < textsize; i++){
    if(wrap && ((cursor_x + size * 5) > _width)){
      cursor_x = 0;
      cursor_y = cursor_y + size * 7 + 3 ;
      if(cursor_y > _height) cursor_y = _height;
      if(_text[i] == 0x20) goto _skip; }
    drawChar(cursor_x, cursor_y, _text[i], color, bg, size);
    cursor_x = cursor_x + size * 6;
    if(cursor_x > _width) cursor_x = _width;
    _skip:;}
}

void drawChar(uint8_t x, uint8_t y, uint8_t c, uint16_t color, uint16_t bg,  uint8_t size){
  int i, j;
  if((x >= _width) || (y >= _height))
    return;
  if(size < 1) size = 1;
  if((c < ' ') || (c > '~'))
    c = '?';
  for(i=0; i<5; i++ ) {
    uint8_t line;
    if(c < 'S')
      line = Font[(c - 32)*5 + i];
    else
      line = Font2[(c - 'S')*5 + i];
    for(j=0; j<7; j++, line >>= 1) {
      if(line & 0x01) {
        if(size == 1) drawPixel(x+i, y+j, color);
        else          fillRect(x+(i*size), y+(j*size), size, size, color);
      }
      else if(bg != color) {
           if(size == 1) drawPixel(x+i, y+j, bg);
           else          fillRect(x+i*size, y+j*size, size, size, bg);
        }
    }
  }
}

void drawPixel(uint8_t x, uint8_t y, uint16_t color){
  if((x >= _width) || (y >= _height)) 
    return;
   setAddrWindow(x,y,x+1,y+1);
  write_data(color >> 8);
  write_data(color & 0xFF);
}

void setTextWrap(int w){
  wrap = w;
}
/**
 End of File
*/