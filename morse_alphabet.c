/* morse_alphabet.c */

#include "morse_alphabet.h"


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
        printf("after fgetc\n");
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

MORSE_LIST create_alphabet (MORSE_LIST * mon_alphabet)
{
    MORSE_LETTER * lettre_morse ;
    lettre_morse=malloc(sizeof(MORSE_LETTER));
    char caractereActuel = 'a';
    mon_alphabet=malloc(sizeof(MORSE_LIST));
    MORSE_CODE *code ;
    code=malloc(sizeof(MORSE_CODE));

    FILE* fichier=NULL;
    fichier=fopen("morse.txt","r");
    printf("fopen done\n");


    if (fichier != NULL)
    {
        	printf("file not NULL\n");

        while (caractereActuel != EOF)
        {
            	printf("caractere not Null\n");

            lettre_morse->letter=(char)(fgetc(fichier));
                        	printf("after fgetc\n");

                while ((caractereActuel) != '\n')
                {
                    caractereActuel=(char)fgetc(fichier);
                    printf("after second fgetc\n");
                    printf("char actuel : %c\n",caractereActuel);
                    add_symbol(code,to_morse_symbol(caractereActuel));
                	printf("after add sylbol\n");

                }
                	printf("caractere fin ligne\n");

             lettre_morse->code=code;
            add_letter(mon_alphabet,lettre_morse);
        }
        	printf("caractere EOF\n");

    }
    else {
        printf("file morse.txt not present\n");
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
