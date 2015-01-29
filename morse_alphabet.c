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


MORSE_CODE* add_symbol(MORSE_CODE *code, MORSE_SYMBOL symbol) {
    MORSE_CODE * aux;
    MORSE_CODE * new;
    if (code == NULL) {
        printf("code = NULL\n");
        code=malloc(sizeof(MORSE_CODE));
        code->symbol = symbol;
        code->next = NULL;
        return code ;
    } else {
        printf("code != NULL\n");
        aux = code;
        while (aux->next != NULL){
            aux=aux->next;
        }
        new = malloc(sizeof(MORSE_CODE));
        aux->next=new;
        new->symbol = symbol;
        new->next = NULL;
        return code ; 
    }

}



MORSE_LIST * add_letter(MORSE_LIST * list, MORSE_LETTER * letter) {
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
    return list ;
}

MORSE_LIST* create_alphabet (MORSE_LIST * mon_alphabet)
{
    MORSE_LETTER * lettre_morse ;
    lettre_morse=malloc(sizeof(MORSE_LETTER));
    char caractereActuel = 'a';
    mon_alphabet=NULL;
    int isEOF;
    MORSE_CODE *code ;
    code=NULL;
    
    FILE* fichier=NULL;
    fichier=fopen("morse.txt","r");
    printf("fopen done\n");
    
    
    if (fichier != NULL)
    {
        printf("file not NULL\n");
        
        caractereActuel=(char)fgetc(fichier);
        while (caractereActuel != EOF)
        {
            printf("caractere not Null\n");
            lettre_morse=malloc(sizeof(MORSE_LETTER));
            lettre_morse->letter=caractereActuel;
            printf("after fgetc\n");
            caractereActuel=(char)fgetc(fichier);
            //TODO : Modify to be OK when EOF without \n
            while ((caractereActuel) != '\n')
            {
                //caractereActuel=(char)fgetc(fichier);
                printf("char actuel : %c\n",caractereActuel);
                code=add_symbol(code,to_morse_symbol(caractereActuel));
                caractereActuel=(char)fgetc(fichier);
            }
            printf("caractere fin ligne\n");
            
            lettre_morse->code=code;
            code = NULL ;
            mon_alphabet=add_letter(mon_alphabet,lettre_morse);
            isEOF=fgetc(fichier);
		printf("isEOF  : %d\n",isEOF);
	    if(isEOF==EOF) {
                printf("EOF found\n\n\n\n\n");
		printf("charInt is : %d\n",isEOF); 
		break; 	    }
            caractereActuel=(char)isEOF;
           printf("actual char = %c\n",caractereActuel); 
        }
        printf("caractere EOF\n");
        
    }
    else {
        printf("file morse.txt not present\n");
    }
    
    return mon_alphabet;
}

/*MORSE_CODE get_morse_lettre(char letter) {
	int i = 0;
	for (i=0;i<1;i++) {
 if (alphabet_morse[i].letter == letter) {
 return alphabet_morse[i].code;
 }
	}
 }*/
