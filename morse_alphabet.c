/* morse_alphabet.c */

#include "morse_alphabet.h"

typedef enum _MORSE_SYMBOL {
	ti,
	ta,
	null //ugly hack to be able to set a fixed size to the array code
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
	MORSE_LETTER element;
	struct _MORSE_LIST * next;
} MORSE_LIST;

typedef struct _ALPHABET_MORSE {
	MORSE_LETTER * first;	
}ALPHABET_MORSE;

/*MORSE_CODE get_morse_lettre(char letter) {
	int i = 0;
	for (i=0;i<1;i++) {
		if (alphabet_morse[i].letter == letter) {
			return alphabet_morse[i].code;
		}
	}
}*/