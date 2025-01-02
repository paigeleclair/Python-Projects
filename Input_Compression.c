/////////////////////////////////////////////////////////////////////////////////
// Paige Leclair                                                               //
// Description: Program that takes in input and compresses strings that        //
// contain more than two of the same character                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
void compress(char *input, char *output);
int main() {
  char input[1001], output[1001]; //since array is in form char, need to account for null
  printf("Enter message:");
  scanf("%s", input);
  compress(input, output);
  printf("Output: %s\n", output);
  return 0;
}
void compress(char *input, char *output) { //sending in val of input and sending out vals of Output
  int count = 1;        //since we start out with an initial letter, repetition or not, set count to 1
  char *p = input, *q = output; //p points to input and q to output
  while (*p != '\0') { //while the input value is a null
    if (*p == *(p+1)){  //if value at that input index is = to val of the next input index

      count++; //we add 1 to count
    }
    else{
      if (count == 2) //HOWEVER if count is ONLY = 2, we want to print both of that letter out
        *q++ = *p; //this just adds that letter to the output when count =2
      if (count > 2){ //if count is > 1, there are repetitions (disregarding initial letter)
        *q++ = count + '0';  //this adds the number of repetitions to output by converting to
                            //string value. Example, 3 + '0' = '3'
      }
      *q++ = *p;  //gets char of p input and stores it in q output and then moves to next q index
  
      count = 1; //resetting count for next letter
    }
    p++; //increase the index of input so we can continue the loop
  }
  *q = '\0'; //adding null to end of output
}
