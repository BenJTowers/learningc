/*
 * concord3.c
 *
 * Starter file provided to students for Assignment #3, SENG 265,
 * Fall 2022.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emalloc.h"
#include "seng265-list.h"
#include <ctype.h>
#define keywordlen 40
#define inputlinelen 120


void print_word(node_t *node, void *arg)
{
    char *format = (char *)arg;
    printf(format, node->line);
}
int include(node_t *exclude, char *word){
    for( ; exclude != NULL; exclude = exclude->next){
        if(strcmp(exclude->text, word) == 0){
            return 0;
        }
    }
    return 1;
}
void copy_lower(char *destination, char *source){
    int i = 0;
    while(source[i] != '\0'){
        destination[i] = tolower(source[i]);
        i++;
    }
}
void uppercase(node_t *output){
int i = 0;
int numspaces = 0;
    for( ; output != NULL; output = output->next){
        i = 0;
        numspaces = 0;
        while(output->line[i] != '\0' && numspaces <= output->numword){
            if(output->line[i] == ' '){
                numspaces++;
            }
            if(numspaces == output->numword){
                output->line[i] = toupper(output->line[i]);
            }
            i++;
        }
    }
}
void cutfront(node_t *output){
    char spacedline[inputlinelen];
    int numspaces = 0;
    int newlinestart = 0;
    int n;
    int i;
    for( ; output != NULL; output = output->next){
        n = 0;
        i = 0;
        if(output->capindex < 19){
            numspaces = 19-(output->capindex);
            while(i < numspaces+1){
                spacedline[i] = ' ';
                i++;
            }
            while(output->line[n] != '\0'){
                spacedline[i] = output->line[n];
                i++;
                n++;
            }
            spacedline[i] = '\0';
            strncpy(output->line, spacedline, sizeof(spacedline));
        }
        if(output->capindex > 19){
            newlinestart = output->capindex - 20;
            n = newlinestart;
            while(output->line[n] != ' '){
                output->line[n] = ' ';
                n++;
            }
            while(output->line[newlinestart] != '\0'){
                output->line[i] = output->line[newlinestart];
                i++;
                newlinestart++;
            }   
            output->line[i] = '\0';
        }
    }
}
void cutback(node_t *output){
    int cutoff = 50;
    int n = 0;
    for( ; output != NULL; output = output->next){
        cutoff = 50;
        n = 0;
        while(output->line[n] != '\0'){
            n++;
        }
        if(n > cutoff){
            while(output->line[cutoff] != ' '){
            cutoff--;
            }
        output->line[cutoff] = '\0';
        }
    } 
}
  
#ifdef DEBUG
/*

 * Just showing the use of the linked-list routines.


void _demo() {
printf("DEBUG: in _demo\n");
    char *words_german[] = {"Der", "Kater", "mit", "Hut."};
    int   words_german_len = 4;

    char *words_english[] = {"The", "cat", "in", "the", "hat."};
    int   words_english_len = 5;

    node_t *temp_node = NULL;
    node_t *head = NULL;

    int i;

     Add the words in German, at the front. 
    for (i = 0; i < words_german_len; i++) {
        temp_node = new_node(words_german[i]);
        head = add_front(head, temp_node);
    }

     Add the words in English, at the end. 
    for (i = 0; i < words_english_len; i++) {
        temp_node = new_node(words_english[i]);
        head = add_end(head, temp_node);
    }

     Print the list of words. 

    apply(head, print_word, "--> %s\n");

     Free up the memory. This is done rather deliberately
     * and manually.  Asserts are liberally used here as they
     * express state that *must* be true if all of the code is
     * correctly working.
    

    temp_node = head;
    while (temp_node != NULL) {
        assert(temp_node != NULL);
        head = remove_front(head);
        free(temp_node);
        temp_node = head;
    }
   
    assert(head == NULL); 
}
*/
#endif



int main()
{
    char keyword[keywordlen];
    char inputline[inputlinelen];
    int numword = 0;
    int capindex = 0;
    int i;  
    fgets(keyword, 40, stdin);
    if(keyword[0] == '1'){
       printf("Input is version 1, concord3 expected version 2");
       return 0;
    }
    fgets(keyword, 40, stdin);
    node_t *exclude_head = NULL;
    node_t *temp = NULL;
    fgets(keyword, 40, stdin);
    int x = 0;
    while(keyword[0] != '"'){
        x = 0;
        while(keyword[x] != '\n'){
            x++;
        }
        keyword[x] = '\0';
        temp = new_node(keyword, inputline, numword, capindex);   
        exclude_head = add_front(exclude_head, temp);
        fgets(keyword, 40, stdin);
    }
    char tokenizable[inputlinelen];
    char *token;
    const char delim[2] = " ";
    node_t *output_head = NULL;
    node_t *temp2 = NULL;
    while(fgets(inputline, 100, stdin) != NULL){
        while(inputline[x] != '\n'){
            x++;
        }
        inputline[x] = '\0';
        strncpy(tokenizable, inputline, sizeof(inputline));
        copy_lower(tokenizable, tokenizable);
        token = strtok(tokenizable, delim);
        i = 0;
        x = 0;
        capindex = 0;
        while(token != NULL){
            if(include(exclude_head,token)){
                temp2 = new_node(token, inputline, i, capindex);
                output_head = add_inorder(output_head, temp2);
            }
            capindex += strlen(token)+1;
            token = strtok(NULL, delim);
            i++;
         }
     }
     node_t *temp_node = NULL; 
     temp_node = exclude_head;
     while(temp_node != NULL){
         exclude_head = remove_front(exclude_head);
         free(temp_node);
         temp_node = exclude_head;
     }    
     uppercase(output_head);
     cutfront(output_head);
     cutback(output_head);
     apply(output_head, print_word, "         %s\n");
     temp_node = output_head;
     while(temp_node != NULL){
         output_head = remove_front(output_head);
         free(temp_node);
         temp_node = output_head;
     }

/* 
 * Showing some simple usage of the linked-list routines.
 */

#ifdef DEBUG
  //  _demo();
#endif

    exit(0);
}
