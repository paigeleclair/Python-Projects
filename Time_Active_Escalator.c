/////////////////////////////////////////////////////////////////////////////////
// Paige Leclair                                                               //
// U81741571                                                                   //
// Description: A program that calculates the total number of seconds          //
// an escalator was active. Takes input of the number of people and their      //
// arrival times. If a person arrives while the escalator is still active     //
// from the previous person, it accounts for this overlap to not count the     //
// same time period twice.                                                     // 
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int active_seconds(int arrival[], int n){
  int total_active = 0; 
  int end_time = 0;
  for (int i = 0; i < n; i++){      //  new variable i, to represent index. As                                                                                  // long as i is < number of people (so we don't have more indices than people),                                             // implement loop. 
    if (arrival[i] > end_time) {    //if the arrival time of one person is greater then the arrival
      total_active += 10;           //of the previous person, then there was a gap and 10 seconds meed to be added
    }
    else if  (arrival[i] > end_time - 10){  //HOWEVER if arrival time of a person is within the time of the previous person
      total_active += arrival[i] + 10 - end_time; // we need to add the overlap time by adding the time it takes current 
                                                  // person minus the end time of previous. 
    }                                             // EX: person 1 @ 12 person 2 at 15. 15+10 = 25 - 22 = 3. 3 seconds                                                         // accounted for.
    end_time = arrival[i] + 10;     //at end of each person, we update the end_time to end_time of current person
  }            
  return total_active;               //returns active to call 
}

int main() {                          //main is self explanatory. Holds all the prints and scans. 
  int n = 0;
  printf("Enter number of people: ");     //asking how many people
  scanf("%d", &n);                        //taking in # people
    
  int i;
  int arrival[n];
    
  printf("Enter arrival times: ");
  for (i = 0; i<n; i++){              // for index starting at 0, continuing until i >= num people, update i by 1. 
                                      //doing it this way accounts for the index starting at 0
    scanf("%d", &arrival[i]);        //taking in arrival times and storing in arrival array at index i
  }
  printf("Active seconds: %d", active_seconds(arrival, i)); //calling function which returns active seconds
  return 0;
}
