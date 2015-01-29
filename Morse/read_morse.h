//
//  read_morse.h
//  Morse
//
//  Created by Jules on 29/01/2015.
//  Copyright (c) 2015 Jules. All rights reserved.
//

#ifndef __Morse__read_morse__
#define __Morse__read_morse__

#define TA_LENGTH 900
#define TI_LENGTH 300
#define SYMBOL_INTERVAL 300
#define LETTER_INTERVAL 900
#define SPACE 1200
#define LED_PIN 1

#include <stdio.h>
#include "morse_alphabet.h"
#include "LED_control.h"
#include <unistd.h>


MORSE_CODE * read_letter (char letter, MORSE_LIST * alphabet);
void blink_letter (char letter, MORSE_LIST *alphabet);

#endif /* defined(__Morse__read_morse__) */
