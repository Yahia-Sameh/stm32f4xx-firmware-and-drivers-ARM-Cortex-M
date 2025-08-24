
#ifndef HTFT_CONFIG_H
#define HTFT_CONFIG_H

#define TFT_PORT      PORTA
#define RST_PIN       PIN0
#define CONTROL_PIN   PIN1

#define SLEEP_OUT      0x11
#define COLOR_MODE     0x3A
#define DISPLAY_ON     0x29
#define X_Direction    0x2A
#define Y_Direction    0x2B
#define SCREEN_WRITE   0x2C

#define RGB565    	0x05

//Start & end x
#define START_X_B0    0
#define START_X_B1    0
#define END_X_B0      0
#define END_X_B1      127
//Start & end Y
#define START_Y_B0    0
#define START_Y_B1    0
#define END_Y_B0      0
#define END_Y_B1      159

//Image size
#define IMAGE_SIZE   20480

#endif