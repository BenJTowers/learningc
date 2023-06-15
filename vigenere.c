/* vigenere.c
   CSC 111 - Fall 2021 - Assignment 6
   V00978554\Ben Towers\2021/11/17
   B. Bird - 10/23/2021
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* index_to_character(index)
   Given an index, which MUST be in the range 0 through 25 (inclusive), return
   the corresponding lowercase character of the English alphabet, where
   the index 0 refers to 'a' and the index 25 refers to 'z'.

   If the index is not in the range 0 through 25, the behavior of this function
   is undefined.

   Parameters: index (integer)
   Return value (char): The character of the English alphabet with the
                        provided index.
*/
char index_to_character(int index){
    return 'a' + index;
}


/* character_to_index(ch)
   Given a lowercase English letter, return the index of that character in the
   English alphabet, where 'a' has the index 0 and 'z' has the index 25.

   If the character is not a lowercase letter, the behavior of this function
   is undefined.

   Parameters: ch (character)
   Return value (int): The index of the provided character in the English
                       alphabet.
*/
int character_to_index(char ch){
    return ch - 'a';
}


int main(){

    char key[100];
    char message[100];
    char encrypted[100];
    char decrypted[100];
   
    char sized1[100];
    
    int index1[100];
    int index2[100];
    int index3[100];
    int index4[100];
    
    int x = 0;
    int y = 0;
    int j = 0;
    
    FILE* input_file = fopen("input.txt","r");
    
     if (input_file == NULL){
        printf("Error: Unable to open input file.\n");
        return 1;
    }
    
    fgets(key, 100, input_file);
    fgets(message, 100, input_file);
    
    fclose(input_file);
    
     while( key[j] != '\0'){
        if(key[j] == ' ' && isspace(key[j+1]) == 0){
            printf("Error: Invalid key.\n"); 
            return 1;
        }
        j++;
    }
    
    j = 0;
     while( message[j] != '\0'){
        if(message[j] == ' ' && isspace(message[j+1]) == 0){
            printf("Error: Invalid message.\n"); 
            return 1;
        }
        j++;
    }
    
    while(key[x] != ' ' && key[x] != '\n' && key[x] != '\0'){
        x++;
    }
    key[x] = '\0';
    
    while(message[y] != ' ' && message[y] != '\n' && message[y] != '\0'){
        y++;
    }
    message[y] = '\0';
    
    if(key[0] == '\0'){
        printf("Error: Invalid key.\n");
        return 1;
    }
    int e = 0;
    while(key[e] != '\0'){
        if(isupper(key[e]) > 0 || isalpha(key[e]) == 0){
           printf("Error: Invalid key.\n");
        return 1; 
        }
        e++;
    }
    
     if(message[0] == '\0'){
        printf("Error: Invalid message.\n");
        return 1;
    }
    e = 0;
    while(message[e] != '\0'){
        if(isupper(message[e]) > 0 || isalpha(message[e]) == 0){
           printf("Error: Invalid message.\n");
        return 1; 
        }
        e++;
    }
    
    int a = 0;
    int b = 0;
    while(message[a] != '\0'){
    sized1[a] = key[b];
    b++;
        if(key[b] == '\0'){
           b = 0;
        }
    a++;
    }
    
    int c = 0;
   while(sized1[c] != '\0'){
        index1[c] = character_to_index(sized1[c]);
        c++;
    }
    c = 0;
    while(message[c] != '\0'){
        index2[c] = character_to_index(message[c]);
        c++;
    }
    
    int d = 0;
    while(d <= y-1){
        index3[d] = index1[d] + index2[d];
        if(index3[d] > 25){
            index3[d] = index3[d] - 26;
        }
        d++;
    }
    
    d = 0;
    while(d <= y-1){
        encrypted[d] = index_to_character(index3[d]);
    
        d++;
    }
  
    d = 0;
    while(d <= y-1){
        index4[d] = index2[d] - index1[d];
        if(index4[d] < 0){
            index4[d] = index4[d] + 26;
        }
        d++;
    }
    
    d = 0;
    while(d <= y-1){
        decrypted[d] = index_to_character(index4[d]);
        d++;
    }
    
    /* Example of the expected output format (using fake output strings) */


    //You can reuse this print statements in your solution (assuming you store each string
    //in the same variables).
    printf("Message: [%s]\n",message);
    printf("Key: [%s]\n",key);
    printf("Encrypted: [%s]\n",encrypted);
    printf("Decrypted: [%s]\n",decrypted);

    return 0;
}