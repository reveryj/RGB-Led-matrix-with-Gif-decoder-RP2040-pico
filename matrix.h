/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 */

#include <stdint.h>

#define G_OE   0
#define G_LAT  1
#define G_CLK  2

#define G_A    4
#define G_B    5
#define G_C    6
#define G_D    7

#define G_R2   8
#define G_G2   9
#define G_B2   10
#define G_R1   11
#define G_G1   12
#define G_B1   13

#define BOOT_BUTTON 22   // Reset for BOOTSEL

#define LED_PIN   25     // PICO_DEFAULT_LED_PIN

#define BUTTON1  16      // Button CTL 1
#define BUTTON2  17      // Button CTL 2

// - - - - Physical Description of Screen
// Total Length of MATRICES in series (on a single line)
static uint8_t nMatrix_X = 1;

//Number of panels on true width (mapping of panels in ZStripe = zigzag) of x wide
static uint8_t zStripes_X = 1;

// Name of LEDS per Matrix
static uint8_t nLedsMatrix_Y = 32;
static uint8_t nLedsMatrix_X = 32;

// - - - - Description LOGIQUE de L'écran - - - - - - 
// BITMAP Logical Buffer Dimensions in X & Y PIXELS
// the RAM limit is close to 164 kb out of 264 kb available.
// * for example 320 * 128 pixels -> 4 x 40960 oc.
// * may be higher than physical display
// * buffer used for gif files
#define nb_pixel_X        32     
#define nb_pixel_Y        32

static uint8_t xRED[nb_pixel_X][nb_pixel_Y] = {0};
static uint8_t xGREEN[nb_pixel_X][nb_pixel_Y] = {0};
static uint8_t xBLUE[nb_pixel_X][nb_pixel_Y] = {0};

//Cursor next PrintChar
static uint16_t CurX=0;
static uint16_t CurY=0; 
 
//============== Declarations ===========
void Init_GPIO();
void setRow(uint8_t row);
void PrintChar(uint8_t );
void PrintHex(uint8_t );
void PrintHex2(uint16_t nn);
void Pset(uint16_t x,uint16_t y,uint8_t RR,uint8_t GG,uint8_t BB);
void PsetnoG(uint16_t x,uint16_t y,uint8_t RR,uint8_t GG,uint8_t BB);
void core2();
void Home(void);
void Fade_out(void);
void SetXY(uint16_t x, uint16_t y);
