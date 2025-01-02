/***********************************************************************************
Paige Leclair
Description: A program that reads from a file and uses structures to create a list of 
animals of the same gender and species while printing their name, age, and weight
************************************************************************************/
#include <stdio.h>
#include <string.h>
struct animal{ //this is the structure for each instance
  char name[100];
  char species[100];
  char gender[100];
  int age;
  float weight;
};

int main() {
  char species[100];
  char gender[100];
  int n = 0;  //initilaize the animal num to 0. This keeps track of how many animals there are
  struct animal instance[200]; 

  FILE *fp = fopen("animals.txt", "r"); //opening file for reading
  FILE *sp = fopen("results.txt", "w"); //open file for writing. Creating the file if it doesn't exist

  printf("Enter species: ");
  scanf("%s", species); //storing the species of the instance in species
  printf("Enter gender: ");
  scanf("%s", gender); //storing the gender of the instance in gender

  //the while loop below makes it so we continue UNTIL we reach the end of file
  //fscanf will read the data pointed to by fp and store the values in the structure
  while (fscanf(fp, "%s %s %s %d %f", instance[n].name, instance[n].species, instance[n].gender, &instance[n].age,   &instance[n].weight) != EOF){
    // if statement checks to see if the species and gender match the input
    if (strcmp(species, instance[n].species) == 0 && strcmp(gender, instance[n].gender) ==0){   
      //prints the name, age, and weight to the results file
      fprintf(sp, "%s %d %.2f\n", instance[n].name, instance[n].age, instance[n].weight);  
    }
     n +=1 ; //incremenring count by 1
  }
  fclose(fp); //closing the file
  fclose(sp); //closing the file
  printf("Output file name: results.txt");
  return 0;
}
