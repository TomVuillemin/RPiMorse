/* morse_alphabet.c */

#include <stdio.h>
#include <stdlib.h>
#include "morse_alphabet.h"

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

MORSE_SYMBOL to_morse_symbol(char c){
	switch(c) {
		case '.' :
			return ti;
			break;
		default:
			return ta;
			break;
	}
}

void add_symbol(MORSE_CODE * code, MORSE_SYMBOL symbol) {
	MORSE_CODE * aux;
	MORSE_CODE * new;
	if (code == NULL) {
		code=malloc(sizeof(MORSE_CODE));
		code->symbol = symbol;
		code->next = NULL;
	} else {
		aux = code;
		while (aux->next != NULL) {
			aux=aux->next;
		}
		new = malloc(sizeof(MORSE_CODE));
		aux->next=new;
		new->symbol = symbol;
		new->next = NULL;
	}
}

void add_letter(MORSE_LIST * list, MORSE_LETTER * letter) {
	MORSE_LIST * aux;
	MORSE_LIST * new;
	if (list == NULL) {
		list=malloc(sizeof(MORSE_LIST));
		list->element=letter;
		list->next = NULL;
	} else {
		aux = list;
		while (aux->next != NULL) {
			aux=aux->next;
		}
		new = malloc(sizeof(MORSE_LIST));
		aux->next=new;
		new->element = letter;
		new->next = NULL;
	}
}

MORSE_LIST create_alphabet ()
{
    MORSE_LIST * mon_alphabet ;
    MORSE_LETTER * lettre_morse ;
    lettre_morse=malloc(sizeof(MORSE_LETTER));
    char caractereActuel = 'a';
    mon_alphabet=malloc(sizeof(MORSE_LIST));
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
