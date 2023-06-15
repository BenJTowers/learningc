/* echo_characters.c

   Task: Read characters from the user (using the getchar() function)
         until they enter the '#' character (which signals the end
         of their input). As each character is read, print it out
         (using the '%c' formatting specifier with printf).

   B. Bird - 09/30/2020
*/

#include <stdio.h>

int main(){

    int ch;
    ch = getchar();
    
    while(ch != '#'){
        printf("%c", ch);

        ch = getchar();
    }
      

    return 0;
}
