/* temperature_data.c


   B. Bird - 11/09/2021
*/

#include <stdio.h>
#include "temperature_data.h"

/* Do not copy the typedef statements for the structure types into this file
   (they should only be in the .h file)
*/


/* read_observation(input_file, obs)
   Given a file object input_file and a pointer obs to an Observation 
   structure, try to read a single observation from the file into the structure
   pointed to by obs. If the complete observation is read successfully, return 1.
   Otherwise, return 0.

   Parameters: input_file (FILE pointer), obs (pointer to Observation object)
   Return value (integer):
     - If the observation was read successfully, return 1
     - Otherwise, return 0
*/
int read_observation(FILE* input_file, Observation* obs){
    int x;
  
    if(fscanf(input_file,"%d", &x) != 1){
        return 0;
    }
    obs->obs_date.year = x;
    
   
    fscanf(input_file,"%d", &x);
    obs->obs_date.month = x;
    
    fscanf(input_file,"%d", &x);
    obs->obs_date.day = x;
    
    fscanf(input_file,"%d", &x);
    obs->hour = x;
    
    fscanf(input_file,"%d", &x);
    obs->minute = x;
    
    fscanf(input_file,"%d", &x);
    obs->station_id = x;
    
    float y;
    fscanf(input_file,"%f", &y);
    obs->temperature = y;
    
    
    
    return 1;
}


/* count_observations(filename)
   Given a filename, count and return the number of temperature observations in
   the file. If the file cannot be opened, return -1.

   Parameters: filename (string)
   Return value (integer):
     - If the file cannot be opened for reading, return -1
     - Otherwise, return the number of temperature observations in the file.*/

int count_observations(char filename[]){
    float x = 0;
    int y = 1;
    int z = 0;
    FILE* input_file = fopen(filename,"r");
    
    if(!input_file){ 
        return -1;
    }
    while(1>0){
        while(y <= 7){
            if(fscanf(input_file,"%f", &x) != 1){
                return z;
            }
            y++;
        }
        z++;
        y = 1;
    }
    
}   

/* load_all_observations(filename, array_size, observation_array)
   Given a filename and an array of Observation objects, read as many 
   observations from the file as possible (up to the size of the array)
   and store each observation (in order) into the array.

   If the file cannot be opened, return -1. Otherwise, return the number of 
   observations read.

   If the file contains fewer observations then there are elements in the array,
   stop reading after the last observation in the file. Otherwise, stop reading
   once array_size observations are read.

   Parameters: filename (string), array_size (integer), observation_array (array of Observation)
   Return value (integer):
     - If the file could not be opened, return -1
     - Otherwise, return the total number of observations read and stored into 
       the array.*/

int load_all_observations(char filename[], int array_size, Observation observation_array[array_size]){
     FILE* input_file = fopen(filename,"r");
    
    if(!input_file){ 
        return -1;
    }
    int x = 0;
    int z = 0;
    while(z <= array_size){
        if(fscanf(input_file,"%d", &x) != 1){
        break;
    }
    observation_array[z].obs_date.year = x;
    
   
    fscanf(input_file,"%d", &x);
    observation_array[z].obs_date.month = x;
    
    fscanf(input_file,"%d", &x);
    observation_array[z].obs_date.day = x;
    
    fscanf(input_file,"%d", &x);
    observation_array[z].hour = x;
    
    fscanf(input_file,"%d", &x);
    observation_array[z].minute = x;
    
    fscanf(input_file,"%d", &x);
    observation_array[z].station_id = x;
    
    float y;
    fscanf(input_file,"%f", &y);
    observation_array[z].temperature = y;
        z++;
    }
    return z;
    
}




/* print_station_extremes(num_observations, obs_array)
   Given an array of Observation objects, compute and print the
    _extreme observations_ (lowest temperature observed and highest
   temperature observed) for each station that has at least one
   observation in the dataset.

   The output will contain one line for each station with at least one 
   observation in the dataset, using a format equivalent to the following:
      Station 1: Minimum = -1.87 degrees (2021-11-21 06:10), Maximum = 10.6 degrees (2021-01-11 01:16)

   You should use the following printf format string to achieve the correct 
   output format.
      "Station %d: Minimum = %.2f degrees (%04d-%02d-%02d %02d:%02d), Maximum = %.2f degrees (%04d-%02d-%02d %02d:%02d)\n"
 
   The output must be ordered by station number (with lower numbered station 
   numbers appearing first). No more than one line of output should be 
   generated for a particular station number.

   In cases where multiple observations achieve the extreme value (e.g. if the
   minimum temperature at a particular station is -1.87, but there are several 
   observations with this temperature), print the date/time of the 
   chronologically earliest observation with that extreme temperature.

   You may assume that all observations contain a station number between 
   1 and 250 (inclusive).

   This function must _not_ use any file I/O features whatsoever.

   Parameters: num_observations (integer), observation_array (array of Observation)
   Return value: None
   Side Effect: A printed representation of station extremes is output to the user.
*/
/*void print_station_extremes(int num_observations, Observation obs_array[num_observations]){
  int x = 0;
  int y = 0;
  int z = 0;
  int i = 0;
  Observation small_temp1;
  Observation small_temp2;
  Observation smallish_temp;
  Observation smallest_temp = {.temperature = 99999999};
  Observation big_temp1;
  Observation big_temp2;
  Observation bigish_temp;
  Observation bigest_temp = {.temperature = -99999999};
  int station;
  int stations[num_observations];
  int num_like_stations = 0;
  int prev_counter = 0;
  Observation like_obs[num_observation];
    
    while(x < num_observations){
      station = obs_array[x].station_id;
        //the above is subject to change
        while(prev_counter <= num_like_stations){
           if(num_like_stations == 0 || station != stations[prev_counter]){
               stations[num_like_stations] = station;
               num_like_stations++;
           }
            prev_counter++; 
        }
        //^this loop is in the wrong place^
        
            
            
            
            while(y < num_observations){
            if(station = obs_array[y].station_id){
                like_obs[z] = obs_array[y];
                z++;
            } 
            y++;
         }
        while(i <= z){
        small_temp1 = like_obs[i];
        small_temp2 = like_obs[i+1];
         if(small_temp1.temperature < small_temp2.temperature){
             smallish_temp = small_temp1;
         }else{
             smallish_temp = small_temp2;
         }
            if(smallish_temp.temperature < smallest_temp.temperature){
                smallest_temp = smallish_temp;
            }
        i++;
        }
        i = 0;
         while(i <= z){
        big1_temp1 = like_obs[i];
        big2_temp2 = like_obs[i+1];
         if(big_temp1.temperature > big_temp2.temperature){
             bigish_temp = big_temp1;
         }else{
             bigish_temp = big_temp2;
         }
            if(bigish_temp.temperature > bigest_temp.temperature){
                bigest_temp = bigish_temp;
            }
        i++;
        }
        printf("Station %d: Minimum = %.2f degrees (%04d-%02d-%02d %02d:%02d), Maximum = %.2f degrees (%04d-%02d-%02d %02d:%02d)\n",smallest_temp.station_id, smallest_temp.temperature, smallest_temp.obs_date.year, smallest_temp.obs_date.month, smallest_temp.obs_date.day, smallest_temp.hour, smallest_temp.minute, bigest_temp.temperature, bigest_temp.obs_date.year, bigest_temp.obs_date.month, bigest_temp.obs_date.day, bigest_temp.hour, bigest_temp.minute);
        x++;
        i = 0;
        y = x;
        z = 0;
    }
}
*/
/* print_daily_averages(num_observations, obs_array)
   Given an array of observation objects, compute and print the average 
   temperature for each day which has at least one observation in the 
   dataset.

   The output must contain only dates which actually appear in at least 
   one observation object in the array. The dates must be in ascending 
   chronological order (so an earlier date must be printed before a later 
   one) and each date may only appear once.

   Each line of output will have the form "year month day average", for 
   example "2021 11 20 10.6" (which would be interpreted to mean that 
   the average temperature on Nov. 21, 2021 was 10.6 degrees).

   Your code may assume that all dates are from years between 2015 and 2021 
   (inclusive) and that the month/day entries are all valid (that is, month
   will always be between 1 and 12 inclusive and day will always be between
   1 and 31 inclusive).
   
   This function must _not_ use any file I/O features whatsoever.

   Parameters: num_observations (integer), observation_array (array of Observation)
   Return value: None
   Side Effect: A printed representation of the average daily temperature is
                output to the user.*/

/*void print_daily_averages(int num_observations, Observation obs_array[num_observations]){
     Your code here 
}*/