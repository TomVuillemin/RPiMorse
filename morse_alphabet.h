
#ifndef IDENTIFICATEUR
#define IDENTIFICATEUR

#include <stdio.h>
#include <stdlib.h>
typedef enum _MORSE_SYMBOL {
	ti,
	ta,
} MORSE_SYMBOL;

typedef struct _MORSE_CODE {
	MORSE_SYMBOL symbol;
	struct _MORSE_CODE* next;
} MORSE_CODE;

typedef struct _MORSE_LETTER {
	char letter;
	MORSE_CODE* code;
} MORSE_LETTER;

typedef struct _MORSE_LIST {
	MORSE_LETTER * element;
	struct _MORSE_LIST * next;
} MORSE_LIST;

MORSE_SYMBOL to_morse_symbol(char c);
MORSE_LIST* create_alphabet (MORSE_LIST * mon_alphabet);
MORSE_LIST* add_letter(MORSE_LIST * list, MORSE_LETTER * letter);
MORSE_CODE* add_symbol(MORSE_CODE * code, MORSE_SYMBOL symbol);




#endif /* guard */
