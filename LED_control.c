//
//  LED_control.c
//  Morse
//
//  Created by Jules on 29/01/2015.
//  Copyright (c) 2015 Jules. All rights reserved.
//

#include "LED_control.h"


void turn_on_LED (int pin,int delay_ms)
{
    pinMode(pin,OUTPUT);
    digitalWrite(pin, 1);
    delay(delay_ms*1000);
    digitalWrite(pin,0);
}

