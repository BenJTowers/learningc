/* formatted_file_reading.c

   Example of using fopen to open a file in mode "r" (read) and
   using fscanf to read formatted numerical data from the file.

   Remember that fopen will return NULL if it is unable to open the file.
   If this occurs, attempting to use the returned value will almost 
   certainly result in a crash (and, even if it doesn't cause a crash,
   will not produce any useful effect).

   B. Bird - 11/01/2020
*/

#include <stdio.h>

int main(){

    FILE* input_file = fopen("a_data_file.txt", "r");

    if (input_file == NULL){
        printf("Unable to open the file for reading\n");
        return 1; //Exit the program (since we can't do anything else without a file)
    }

    //Now read single values from the file until fscanf stops
    //finding them.

    //Note that reading double values with fscanf requires
    //the use of the "%lf" specifier, not "%f" (which is just
    //for floats).

    double v;
    while( fscanf(input_file,"%lf", &v) == 1){
        printf("Read %f\n", v);
    }

    //Don't forget to close the file
    fclose(input_file);
    return 0;
}