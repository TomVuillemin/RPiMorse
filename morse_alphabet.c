/* morse_alphabet.c */

#include <stdio.h>
#include <stdlib.h>
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


ALPHABET_MORSE create_alphabet ()
{
    ALPHABET_MORSE * mon_alphabet ;
    MORSE_LETTER * lettre_morse ;
    lettre_morse=malloc(sizeof(MORSE_LETTER));
    char caractereActuel = 'a';
    mon_alphabet=malloc(sizeof(ALPHABET_MORSE));
    MORSE_CODE *code ;
    code=malloc(sizeof(MORSE_CODE));
    
    FILE* fichier=NULL;
    fichier=fopen("morse.txt","r");
    
    if (fichier != NULL)
    {
        
        while (caractereActuel != EOF)
        {
            lettre_morse->letter=(char)(fgetc(fichier));
                while ((caractereActuel) != '\n')
                {
                    caractereActuel=(char)fgetc(fichier);
                    add_symbol(code,to_morse_symbol(caractereActuel));
                }
             lettre_morse->code=code;
            add_letter(mon_alphabet,lettre_morse);
        }
    }
    
    return *mon_alphabet;
}

/*MORSE_CODE get_morse_lettre(char letter) {
	int i = 0;
	for (i=0;i<1;i++) {
		if (alphabet_morse[i].letter == letter) {
			return alphabet_morse[i].code;
		}
	}
}*/