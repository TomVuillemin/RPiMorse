#include <stdio.h>
#include "morse_alphabet.h"
#include "read_morse.h"

int main(int argc, char **argv)
{
    // Test add symbol
  // char c = '.';
  // char d = '-';
    MORSE_CODE * code;
    code=malloc(sizeof(MORSE_CODE));
/*code = add_symbol(code,to_morse_symbol(d));
code = add_symbol(code,to_morse_symbol(c));

    
    
    // Test add letter
MORSE_LETTER * letter;
MORSE_LIST * list_of_letter;
letter=malloc(sizeof(MORSE_LETTER));
letter->letter='a';
letter->code=code;
list_of_letter = add_letter(list_of_letter, letter);
    printf(" ");*/
    
    
    
    struct _MORSE_LIST * alphabet;
    
    printf("before alphabetd\n");
	alphabet=create_alphabet(alphabet);
    printf("create alphabet done\n");
    
    // Test read_letter
    code=read_letter('l',alphabet);
    
	printf("alphabet : %c\n",'c');
	return 0;
}
