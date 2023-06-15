/* count_characters.c

   Task: Read characters from the user (using the getchar() function)
         until they enter the '#' character (which signals the end
         of their input).
         Afterwards, print the total number of characters they entered,
         not including the # character.

   B. Bird - 09/30/2020
*/

#include <stdio.h>

int main(){
    int count = 0;

    int ch;
    ch = getchar();
    
    while(ch != '#'){
        count = count + 1;

        ch = getchar();
    }

    printf("%d\n",count);

    return 0;
}
