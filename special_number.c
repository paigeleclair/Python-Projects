/////////////////////////////////////////////////////////////////////////////
// Paige Leclair                                                           //
// U81741571                                                               //
// Description: A C program that determines if a number                    //
// entered by the user is special (contains a 3 and is a multiple of 3)    //
/////////////////////////////////////////////////////////////////////////////


#include <stdio.h>

int main() {
  int num;
  printf("Enter input: ");
  scanf("%d", &num);
  int original_num = num;   //Simply used to store num. This is needed because num is set                               // to 0 inside while loop so the second if statement checking                               // if num % 3 = 0 will always be true without this variable. 
  
  int digit;
  int has_three = 0;
  while (num != 0) {     //while loop to check EACH digit in input number
    digit = num % 10;    //findings "tens" number by finding remainder
    if (digit == 3) {    //if that remainder has 3, then has_three = 1
      has_three = 1;
    }                    //need to update while loop so it doesn't run infinitely     
    num /= 10;           //I divide the input number by 10 to remove the last digit that was        
  }                      //worked on. EX: Say user enters 253. 253 enters while
                         //loop and 253 % 10 = 3. Thats our "tens" and equals 3.
                         //Now we divide 253 /10 to get 25. Now 25 goes through same process until no num/10 = 0
  if (has_three >=1 && original_num % 3 == 0) {       //if digits contain a 3 (solved in while loop above) AND 
    printf("yes");                     //number is a factor of 3 (if input number / 3 has a remainder of 0 then we know it is a 
  }                                      // multiple of 3 ), THEN number is a special number. 
  else { 
    printf("no");                      //If not both then not a special number.
  }
  return 0;
}
