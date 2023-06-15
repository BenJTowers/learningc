/* reading_text.c 
   
   B. Bird - 11/01/2020
*/

#include <stdio.h>

int main() {
    FILE* input_file = fopen("fruit.txt","r");
    
    if (input_file == NULL){
        printf("Unable to open input file\n");
        return 1;
    }

    /* Method 1: Use fgetc and check for EOF */
    int ch = fgetc(input_file);
    while(ch != EOF){
        printf("Character: [%c]\n", ch );
        
        ch = fgetc(input_file);
    }

    fclose(input_file);
    return 0;
}
