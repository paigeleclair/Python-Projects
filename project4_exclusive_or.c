/////////////////////////////////////////////////////////////////////////////////
// Paige Leclair                                                               //
// Description: A program that determines if two arays, a and b, have          //
// different values (otherwise exclusive) and if they do they are added to     //
//  array c. This program uses pointer arithmetic to visit array elements.     //                               //                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
//declaring exclusive function
void exclusive_or(int *a, int n1, int *b, int n2, int *c, int *size);
//main funciton that takes in input and iterates through the input values
int main(void) {
  int i, n1, n2;
//////////////////////////   Array a   //////////////////////////////////////////
  printf("Enter length of array #1:");
  scanf("%d", &n1);
  int a[n1];                                //declaring after we take in length of n1
  printf("Enter array elements:");
  for (i = 0; i < n1; i++) {               //iterating over elements in array a and taking them in
    scanf("%d", &a[i]);
  }
/////////////////////////////    Array b  //////////////////////////////////////////
  printf("Enter length of array #2:");
  scanf("%d", &n2);
  int b[n2];                             //declaring after we take in length of n2
  printf("Enter array elements:");
  for (i = 0; i < n2; i++) {
    scanf("%d", &b[i]);                  //iterating over elements in array b and taking them in
  }
//////////////////////////////////  Array c  ////////////////////////////////////////////////
  int c[n1+n2];                           //since n2 and n1 are now have lengths, array C has a..
                                          // potential length of both a and b combine
  int size;
  exclusive_or(a, n1, b, n2, c, &size);  //since c and size are pointers we pass the
                                          //address of the two so they can grab the values
  printf("Output: ");
  for (i = 0; i < size; i++) {            //iterating over elements in array c and printing them
    printf("%d ", c[i]);
  }
  return 0; 
}
//Exclusive Function that iterates through our two arrays and determines...
//that if a value in a = value in b then it is exclusive and is put into array c.

void exclusive_or(int *a, int n1, int *b, int n2, int *c, int *size) {
  int *p, *q;                       //initializing pointers used in for loops
  *size = 0;                        //size of c starts with a 0
  int similar = 0;                  //helps keep track of similarities through alliterations
  
  for (p = a; p < a + n1; p++) {    // setting p to a is like setting p to a[0].
                                    // Now say n1 is 4 and since we want to 
    similar = 0;                    //stop when when p goes over 4, we use p < a[0+4].
    for (q = b; q < b + n2; q++) {  //q for loop uses the same logic as above
      if (*p == *q) {               //these next two if statements find if the numbers are exclusive.
        similar = 1;                //It says if val at p (array a val) is = to val at q (array b val)..
      }
    }
    if (similar == 0){       //if q iterates through b and finds that none are similar to the first value
      c[(*size)++] = *p;     //of array a then we need to + that value to array C and inc c's index
    }
  }

  //this section uses the same code and logic as above, just flipping nested loop and outer loop

    for (q = b; q < b + n2; q++) {      //this is that same for loop logic from lines 58 and 61 
      similar = 0;                      
                                          
      for (p = a; p < a + n1; p++) {   //same logic as lines 58 and 61
       
        if (*q == *p) {               //these next two if statements find if the numbers are exclusive.
          similar = 1;               
        }
      }
      if (similar == 0){      //if p iterates through a and finds that none are similar to the first val...
        c[(*size)++] = *q;    //of array b then we need to + that val to array c and then inc C's index.
      }
    } 
}
