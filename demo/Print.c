#include <stdio.h>
#include <stdlib.h>

/// @brief Ref. Bro Code
void Print() {

    // this is single line comment
    /*
      This
      is
      a
      multi line comment
    */

    /* *** ( escape sequence ) ***
      Character combination consisting of a backslah -> `\`, followed by a letter or combination of digits.
      They specify actions within a line or string of text.
      \n : newline
      \t : tab
      \\ : display \
      \' : display '
      \" : display " ... etc more
    */

    system("clear");
    printf("Hello World\n");
    printf("I like pizza\n");
    printf("This \'is\' \"tab\"\t apply\n");
}
