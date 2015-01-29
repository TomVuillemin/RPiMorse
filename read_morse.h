//
//  read_morse.h
//  Morse
//
//  Created by Jules on 29/01/2015.
//  Copyright (c) 2015 Jules. All rights reserved.
//

#ifndef __Morse__read_morse__
#define __Morse__read_morse__

#define TA_LENGTH 3
#define TI_LENGTH 1
#define SYMBOL_INTERVAL 1
#define LETTER_INTERVAL 3
#define SPACE 6
#define LED_PIN 7

#include <stdio.h>
#include "morse_alphabet.h"
#include "LED_control.h"
#include <unistd.h>


MORSE_CODE * read_letter (char letter, MORSE_LIST * alphabet);
void blink_letter (char letter, MORSE_LIST *alphabet);

#endif /* defined(__Morse__read_morse__) */
