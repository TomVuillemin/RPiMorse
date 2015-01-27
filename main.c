#include <stdio.h>
#include "morse_alphabet.h"

int main(int argc, char **argv)
{
    struct _MORSE_LIST * alphabet;
    char c;
    printf("before alphabetd\n");

	create_alphabet(alphabet);
    printf("create alphabet done\n");

	c=alphabet->element->letter;
	printf("alphabet : %c\n",c);
	return 0;
}
