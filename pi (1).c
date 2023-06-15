/* pi.c
   CSC 111 - Fall 2021 - Assignment 2

   B. Bird - 08/05/2021
   (Put your Ben Towers/V00978554/sep.23 here when you implement your solution)
*/

#include <stdio.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int n = 20; //Number of terms in summation
    
    /* END OF INPUT DATA */
    /* Implement your solution below this line */
   double d = 1;
    double b = 1;
    double c = 1;
    double f = 1;
    double e = 1;
    double g = 1;
    double h = 1;
    double j = 1;
    double a = 1;
    double sum = 0;
    int i;
    
    for(i = 1; i <= n; i = i + 1){
    b = b*3.0;
    f = f*7.0;
    c = 8.0/b;
    e = 4.0/f;
    g = d/a;
    h = c+e;
    j = g*h;
    sum = sum+j;
    d = -d;
    a += 2;
    b = b*3;
    f = f*7;
    }
   i = i-1;
    printf("With %d terms: pi = %.15f\n", i, sum);
    
    return 0;
}


