/* weekday.c
   CSC 111 - Fall 2021 - Assignment 3

   B. Bird - 08/10/2021
   (Put your Ben Towers/V00978554/2021/10/03 here when you implement your solution)
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int year = 1993;
    int month = 2;
    int day = 29;
    
    /* END OF INPUT DATA */
    /* Implement your solution below this line */
    /* (you may also add new functions above main() if needed) */
    int sum;
    int leap = 0;
    /*incorrect value measures*/
    int errorday = 0;
   int erroryear = 0;
    int errormonth = 0; 
    
    
    if(year <= 0){
        erroryear += 1;
    }
    if(year > 10000){
        erroryear += 1;
    }
    if(month <= 0){
     errormonth += 1;
    }
     if(month > 12){
     errormonth += 1;
    }
     if(day <= 0){
     errorday += 1;
    }
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day > 31){
            errorday += 1;
        }
    }
     if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
            errorday += 1;
        }
    }
     if(month == 2){
        if(day > 29){
            errorday += 1;
        }
    }
    /*leap year*/
   if(year%4 == 0){
        if(year%100 > 0){
            leap += 1;
        }
        if(year%400 == 0){
            leap += 1;
        }
    }
    if(leap == 0){
        if(day == 29){
            errorday += 1;
        }
    }
    if(erroryear == 0){
        if(errormonth == 0){
            if (errorday == 0){    
            }else{printf("Error: Invalid day\n");
                 }
        }else{printf("Error: Invalid month\n");
             }
    }else{printf("Error: Invalid year\n");
         }
    
    if(erroryear == 0 && errormonth == 0 && errorday == 0){
      
        /*day of the week calculation*/
        sum = year%100;
        sum = sum/4;
        sum = sum+day;
       
        if(month == 1 || month == 10){
            sum = sum+1;
        }
        if(month == 2 || month ==3 || month == 11){
            sum = sum+4;
        }
        if(month == 5){
            sum = sum+2;
        }
        if(month == 6){
            sum = sum+5;
        }
        if(month == 8){
            sum = sum+3;
        }
        if(month == 9 || month == 12){
            sum = sum+6;
        }
        if(leap > 0 ){
           if(month == 1 || month == 2){
            sum = sum-1;
        }
        }
      
        sum = sum-(((year/100)%4)*2);
      
        sum = sum + (year%100);
        sum = sum+12;
      
        sum = sum%7;

        if(sum == 0){
        printf("%d-%d-%d: Sunday\n",year, month, day);
    }
    if(sum == 1){
        printf("%d-%d-%d: Monday\n",year, month, day);
    }
    if(sum == 2){
        printf("%d-%d-%d: Tuesday\n",year, month, day);
    }
    if(sum == 3){
        printf("%d-%d-%d: Wednesday\n",year, month, day);
    }
    if(sum == 4){
        printf("%d-%d-%d: Thursday\n",year, month, day);
    }
    if(sum == 5){
        printf("%d-%d-%d: Friday\n",year, month, day);
    }
    if(sum == 6){
        printf("%d-%d-%d: Saturday\n",year, month, day);
    }
    }
    return 0;
}


