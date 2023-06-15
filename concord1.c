#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 20
#define MAXLINE 70
#define MAXNUMLINES 100

//a structure containing one line of the output and the word capitalized in that line
typedef struct {
char outlines[MAXLINE];
char capword[MAXWORD];
} Outputlines;

//function that organizes the structures by the capital words
int capsort(const void *a, const void *b){
Outputlines *pa = (Outputlines *)a;
Outputlines *pb = (Outputlines *)b;
return strcmp(pa->capword, pb->capword);
}



int main() {
char c;
char nono[MAXWORD][MAXWORD];
int length = 0;
int line = 0;

for(int x = 0;x < 7; x++){
getchar();
}
//make a 2d array with the words to not capitalize
while((c = getchar()) != '"'){
        	if(c != '\n'){
			nono[line][length] = c;
			length++;
		}else{
       			nono[line][length] = '\0';
			line++;
			length = 0;
		}
}

for(int x = 0;x < 4; x++){
getchar();
}
//make a 2d array with the lines to go thorugh and capitalize 
char index[MAXNUMLINES][MAXLINE];
int linedex = 0;
int lengthdex = 0;
while((c = getchar()) != EOF){
	if(c != '\n'){
            index[linedex][lengthdex] = c;
	    lengthdex++;
	}else{
	    index[linedex][lengthdex] = '\0';
	    linedex++;
	    lengthdex = 0;
	}
}

Outputlines output[MAXNUMLINES];
int x = 0;
char *token;
int comp = 0;
int tokrement = 0;
int outputline = 0;
const char delim[2] = " ";
char parser[MAXNUMLINES][MAXLINE];
//a loop that capitalizes all the neccesary words and forms the output in non-alphabetical order
for(int indexline = 0; indexline < linedex; indexline++){
strncpy(parser[indexline], index[indexline], sizeof(index[indexline]));
token = strtok(parser[indexline], delim);
	//a loop that goes through each line of the input lines
	while(index[indexline][x] != '\0' && token != NULL){
	if(tokrement > 0){
		token = strtok(NULL, delim);
	}
	tokrement++;
		//a loop that determines if a word in the sentence is one that needs to be capitalized or not
		for(int i = 0; i < line; i++){	
			if(strcmp(token,nono[i]) == 0){
			comp = 1;
			}	
		}
		//if it needs to be capitalized capitalize it and place that line in the array of output structures along with the word that needs to be capitalized 
		if(comp == 0){
		strncpy( output[outputline].outlines, index[indexline],sizeof(index[indexline]));
		strncpy( output[outputline].capword, token, sizeof(char)*MAXWORD);
			while(output[outputline].outlines[x] != ' ' && output[outputline].outlines[x] != '\0'){
			output[outputline].outlines[x] = toupper(output[outputline].outlines[x]);
			x++;
			}
			if(index[indexline][x] != '\0'){
				x++;
			}
			outputline++;
		//if it doesn't need to be capitalized index past that word and ignore it	
		}else{
			while(index[indexline][x] != ' ' && index[indexline][x] != '\0'){
			x++;
	 		}
			
			if(index[indexline][x] != '\0'){
			x++;
			}	
		}
	comp = 0;
	}
x = 0;
tokrement = 0;
}
//sort the array of structures into alphabetical order by the word that is capitalized in each line
qsort(output, outputline, sizeof(Outputlines), capsort);
//output the array lines in the array of structures
int m = 0;
for(int n = 0; n < outputline; n++){
	while(output[n].outlines[m] != '\0'){
		putchar(output[n].outlines[m]);
		m++;
}
putchar('\n');
m = 0;
}
//tada the end
return 0;
}

