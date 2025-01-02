/***********************************************************************************
Paige Leclair
Description: A program that reads from a file and uses quick sort to sort 
the name, age, and weight of animals in the list
************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct animal{ //this is the structure for each instance
  char name[100];
  char species[100];
  char gender[100];
  int age;
  float weight;
};


int compare(const void *a, const void *b){ //takes in pointers of what we are comparing
  struct animal *animal1 = (struct animal *)a; // animal1 pointing to the first instance
  struct animal *animal2 = (struct animal *)b;//animal2 pointing to the second instance
  
  int speciesCompare = strcmp(animal1->species, animal2->species); //comparing species
  if(speciesCompare != 0){ //if they are not the same species
    return speciesCompare;//return the speciescompare results
  }
  if (animal1->age < animal2->age){ //if the first instance is less than the second instance
    return -1;
  }
  else if (animal1->age > animal2->age){ //if the first instance is greater than the second instance
    return 1;
  }
  else{ //if the first instance is equal to the second instance
    return 0;
  }
}

int main(){
  int n = 0;  //initilaize the animal num to 0. This keeps track of how many animals there are
  struct animal instance[200]; 

  FILE *fp = fopen("animals.txt", "r"); //opening file for reading. pointing to animal file
  FILE *sp = fopen("results.txt", "w"); //open file for writing. Creating the file if it doesn't exist

   //null for loop to increment the number of animals for the qsort
  for (n = 0; fscanf(fp, "%s %s %s %d %f", instance[n].name, instance[n].species, instance[n].gender, &instance[n].age, &instance[n].weight) != EOF; n++);
 
  qsort(instance, n, sizeof(struct animal), compare); //now calling qsort to compare species and ages
  for (int i = 0; i < n; i++){ //for loop to print out the animals
    fprintf(sp, "%s %d %s %.2lf %s\n", instance[i].species, instance[i].age, instance[i].name,instance[i].weight, instance[i].gender);
  }
  fclose(fp); //closing the file
  fclose(sp); //closing the file
  printf("Output file name: results.txt");
  return 0;
}
