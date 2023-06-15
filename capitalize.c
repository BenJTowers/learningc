#include <stdio.h> 
#include <ctype.h>


int main(){
  
    int toupper(int ch);
    int tolower(int ch);
    int ch;
    ch = getchar();
    int space;
    int upper;
    int lower;
    int alpha;
    while(ch != '#'){ 
        space = isspace(ch);
        upper = isupper(ch);
        lower = islower(ch);
        alpha = isalpha(ch);
        if(space == 0){
            while(alpha == 0 && ch != 10 && space == 0 && ch != '#'){
            printf("%c", ch); 
           ch = getchar();
            space = isspace(ch);
            }
            while(upper != 0 && ch != 10 && space == 0 && ch != '#'){
            printf("%c", toupper(ch)); 
           ch = getchar();
            space = isspace(ch);
            }
              while(lower != 0 && ch != 10 && space == 0 && ch != '#'){
            printf("%c", tolower(ch)); 
           ch = getchar();
            space = isspace(ch);
            }
        }
        if(space != 0 && ch != 10){
           printf(" ");
        ch = getchar();
        }else if(ch != '#'){
            printf("%c", ch); 
           ch = getchar();
            
        }
        
    }
   printf("\n");
    return 0;
}