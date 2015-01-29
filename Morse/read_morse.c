//
//  read_morse.c
//  Morse
//
//  Created by Jules on 29/01/2015.
//  Copyright (c) 2015 Jules. All rights reserved.
//

#include "read_morse.h"

MORSE_CODE * read_letter (char letter, MORSE_LIST *alphabet ) {
    MORSE_CODE * code ;
    MORSE_LIST * aux ;
    code = malloc(sizeof(MORSE_CODE));
    aux=alphabet;
    while (aux->element->letter != letter)
        aux=aux->next;
    code=aux->element->code;
    return code ;
}



void blink_letter (char letter, MORSE_LIST *alphabet) {
    MORSE_CODE * code;
    MORSE_CODE * aux;
    code = read_letter(letter, alphabet);
    if (code != NULL) {
        aux = code;
        while (aux->next != NULL){
            switch (aux->symbol) {
                case ti:
                   turn_on_LED(LED_PIN,TI_LENGTH);
                    break;
                default:
                    turn_on_LED(LED_PIN,TA_LENGTH);
                    break;
            }
            sleep(SYMBOL_INTERVAL);
            aux=aux->next;
        }
        sleep(LETTER_INTERVAL - SYMBOL_INTERVAL);
    }
}