/////////////////////////////////////////////////////////////////////////////////
// Paige Leclair                                                               //
// Description: A program that prompts the user with a tool selection 1-4 and  //
// calculates their charge based on the hours, days, and possible weeks user   //
// rents tool for.                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

//MAIN FUNCTION
int main(){

//Establishing Variables
  int selection;
  int hours;
  int days;
  int week_charge = 0;
  int day_charge = 0;
  int total_charge = 0;
  int hour_charge = 0;

//User input for selection
  printf("Please select from four equipment: 1, 2, 3, and 4\nEnter equipment selection: ");
  scanf("%d", &selection);

//Input validation if selection is >4 or <1. Exits if invalid
  while ((selection > 4) || (selection < 1)) {
    printf("Invalid selection. Select from 1 to 4.");
    return 0; //exits program
    } 
//User input for Days
  printf("Enter days: ");
  scanf("%d", &days);

//User Input for hours
  printf("Enter hours: ");
  scanf("%d", &hours);

//Input Validation for hours <1 or >24. Exits if invalid
  while ((hours <= 0) || (hours > 24)) {
    printf("Invalid hours.");
    return 0;
  }


////////////////////////////////////CALCULATIONS//////////////////////////////////////////
///Same format for each selection except changing hourly, daily, and weekly price depending on selection num
  
//////////////////////////////////////Selection 1///////////////////////////////////////////////////

  if (selection == 1) {

////1. Figuring out if weekly charge needs to be applied, and if so, find the remainder of days:
    if (days > 4) {                      // If days are > 4, then weekly charge should be applied.
      week_charge = (days / 7) * 40;

/////////1a. If days can be divided by 7:
      if ((days % 7) > 4) {              // If the days / 7 has a remainder that is...
        day_charge = 40;                 // greater than 4, then weekly charge applied again
      }                                  // because days take on weekly rate when above 4
      else if ((days % 7) <= 4) {        // On the other hand, if days / 7 has a remainder...
        day_charge = (days % 7) * 10;    // <= 4, Then daily charge * days is applied...
      }                                  // because <=4 takes on the daily charge
    } 

///////1b. If days can't be divided by 7:
    else if (days <= 4) {                // if days <= 4, than there is no weekly charge to apply.
      week_charge = 0;
      day_charge = days * 10;            // and <= 4 means those days need to be * by daily charge.
    }                           
      
////2. Figuring out if hours should receive a daily charge or a 4-hour charge:
    if (hours <= 4) {                    // hours <= 4 takes on 4-hour price BUT... 
      hour_charge = 7;
      } 
    else if (hours > 4) {            //hours >4 takes on daily OR weekly depending on the days we have:
      if (days <= 4) {               //if hours > 4 and days  < 4,  it wouldn't do any good...
        hour_charge = 10;            //hours added as a day because days won't be a weekly charge...
          }                          //even with hours being a +1 day. Ex. 3 days + 10 hours == 4 days,
                                     //but this doesnt save money for user since days would still be <= 4.
      else if (days > 4){
        days = days + 1;             // since hours are above 4, and days are > 4, then days takes on ...
        hour_charge = 0;             // one more day (lower cost than doing 3 * weeks + daily * 5 + hourly charge).
      }                              // EX: For selection3 26 days + 8 hours = 3 weeks, 5 days + 1 
    }                                // because it saves money. $1392 rather than 1479 when 
  }                                  // weekly cost (1044) + daily cost (348) + hourly cost (87 (takes on daily)). 

  
/////////////////////////////////////SELECTION 2//////////////////////////////////////////////////////
  if (selection == 2) {

////1. Figuring out if weekly charge needs to be applied, and if so, find the remainder of days:
    if (days > 4) {                     // If days are > 4, then weekly charge should be applied.
      week_charge = (days / 7) * 156;

/////////1a. If days can be divided by 7:
      if ((days % 7) > 4) {               // In addition, if the days / 7 has a remainder that is...
        day_charge = 156;                 // greater than 4, then weekly charge applied again.
      } 
      else if ((days % 7) <= 4) {         // On the other hand, if days / 7 has a remainder...
        day_charge = (days % 7) * 39;     // <= 4, then daily charge * days is applied
      }
    }
  
/////////1b. If days can't be divided by 7:
    else if (days <= 4){                 // if days <= 4, then there is no weekly charge to apply.
      week_charge = 0;
      day_charge = days * 39;            // <= 4 means those days need to be * by daily charge
    }
    
////2. Figuring out if hours should receive a daily charge or a 4-hour charge:
    if (hours <= 4){                     // <= 4 takes on 4-hour price
      hour_charge = 27;
    } 
    else if (hours > 4) {                // >4 takes on daily price
      if (days <= 4) {
        hour_charge = 39;
      }
      else if (days > 4){
        days = days + 1;                 // since hours are > 4, and days are > 4, then days 
        hour_charge = 0;                 // takes on one more day, taking on the weekly charge.
      }
    }
  }
  
  /////////////////////////////////SELECTION 3////////////////////////////////////////
  if (selection == 3) {

////1. Figuring out if weekly charge needs to be applied, and if so, find the remainder of days:
    if (days > 4) {                         // If days are > 4, then weekly charge should be applied.
      week_charge = (days / 7) * 348;

/////////1a. If days can be divided by 7:
      if ((days % 7) > 4) {                 // If the days / 7 has a remainder that is...
        day_charge = 348;                   // Greater than 4, then weekly charge applied again.
      } 
      else if ((days % 7) <= 4) {           // On the other hand, if days / 7 has a remainder...
        day_charge = (days % 7) * 87;       // <= 4, Then daily charge * days is applied
      }
    }

/////////1b. If days can't be divided by 7: 
    else if (days <= 4) {                    // if days <= 4, than there is no weekly charge to apply.
      week_charge = 0;
      day_charge = days * 87;               // and <= 4 means those days need to be * by
    }                                       // daily charge.
      
////2. Figuring out if hours should receive daily charge or 4-hour charge:
    if (hours <= 4) {                      // <= 4 takes on 4-hour price
      hour_charge = 61;
    } 
    else if (hours > 4) {                  // >4 takes on daily price
      if (days <= 4) {
        hour_charge = 87;
      }
      else if (days > 4){
        days = days + 1;                   // since hours are > 4, and days are > 4, then days 
        hour_charge = 0;                   //takes on one more day, taking on the weekly charge 
      }
    }
  }
//////////////////////////////SELECTION 4//////////////////////////////////////////////
  if (selection == 4) {

////1. Figuring out if the weekly charge needs to be applied, and if so, find the remainder of days:
    if (days > 4) {                        // If days are > 4, then weekly charge applied.
      week_charge = (days / 7) * 336;

/////////1a. If days can be divided by 7:
      if ((days % 7) > 4) {                // In addition, if the days / 7 has a remainder 
        day_charge = 336;                  // that is > 4, then weekly charge applied again.
      } 
      else if ((days % 7) <= 4) {          // On the other hand, if days / 7 has a remainder...
        day_charge = (days % 7) * 84;      // <= 4, Then daily charge * days is applied
      }
    }

/////////1b. If days can't be divided by 7:
    else if (days <= 4) {                 // if days <= 4, than there is no weekly charge to apply.
      week_charge = 0;
      day_charge = days * 84;             // and <= 4 means those days need to be * by daily charge.
    }
      
////2. Figuring out if hours should receive daily charge or 4-hour charge:
    if (hours <= 4) {                     // <= 4 takes on 4-hour price
      hour_charge = 59;
    } 
    else if (hours > 4) {                 //if hours >4, we need to figure out where to put these hours 
      if (days <= 4) {                    // Ex: should hours be added as a separate day charge or add them to days to 
        hour_charge = 84;                 // get a week charge. Thats the logic here. 
      }
      else if (days > 4){
        days = days + 1;                  // since hours are above 4, and days are > 4, then
        hour_charge = 0;                  // days takes on one more day (hours now = 0), taking on  
      }                                   // the weekly charge becuase cost will be lower
    }
  }

///////Total Charge ///////////////////////// 
  total_charge = week_charge + day_charge + hour_charge;    // total adding up all the charges
  printf("Charge($): %d", total_charge);
  return 0;
}
