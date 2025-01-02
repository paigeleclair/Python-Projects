////////////////////////////////////////////////////////////
//Paige Leclair                                           //
//U81741571                                               //
// Description: A program that reads from an input file   //
// and stores the first letter of each word and then      //
//sends to output form an encrypted text.                 //
////////////////////////////////////////////////////////////


#include <stdio.h>

void decode(char words[][101], int num_words, char *result);

int main() {
  char words[1000][101]; //no more than 1000 words, where each word is no more than 100 characters
  int num_words = 0;
  char result[1001]; //result cannot be more than 1000 characters
  char file_name[101]; //no more than 100 characters

 // printf("Enter the file name: \n");
  scanf("%100s", file_name);
  FILE *file = fopen(file_name, "r"); // open file and reading

  while (fscanf(file, "%100s", words[num_words]) == 1) {
    num_words++;        //incrementing word count as long as there is a word. 
                        //Ensures we stop incrementing once we reach the end of the file
  }
  decode(words, num_words, result); //calling decode
  result[num_words] = '\0'; //adding null 
  printf("%s", result);   //after calling we can print output

  fclose(file); //after printing we will want to close the file
}

void decode(char words[][101], int num_words, char *result) {
  for (int i = 0; i < num_words; i++) { //iterating through array
    result[i] = words[i][0];     // i will be the row and 0 in the column part will
                                //ensure we store the FIRST letter of each row
  }
}
