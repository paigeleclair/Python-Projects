/***********************************************************************************
Paige Leclair
U81741571
Description: A program that  manages and tracks the guest list for a
local restaurant. Each group of guests is stored with phone number,
last name and first name, and party size.
************************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 30
#define PHONE_LEN 20
struct guest {
  char phone[PHONE_LEN + 1];
  char last[NAME_LEN + 1];
  char first[NAME_LEN + 1];
  int party_size;
  struct guest *next;
};
struct guest *add_guest(struct guest *list);
void print_list(struct guest *list);
void clear_list(struct guest *list);
struct guest *remove_guest(struct guest *list);
int read_line(char str[], int n);
/**********************************************************
 * main: Prompts the user to enter an operation code, *
 * then calls a function to perform the requested *
 * action. Repeats until the user enters the *
 * command 'q'. Prints an error message if the user *
 * enters an illegal code. *
 **********************************************************/
int main(void) {
  char code;
  struct guest *new_list = NULL;
  printf("Operation Code: a for adding to the list at the end, r for removing "
         "from the list, p for printing "
         "the list; q for quit.\n");
  for (;;){
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n') /* skips to end of line */
      ;
    switch (code) {
    case 'a':
      new_list = add_guest(new_list);
      break;
    case 'r': //remove case
      new_list = remove_guest(new_list);
      break;
    case 'p':
      print_list(new_list);
      break;
    case 'q':
      clear_list(new_list);
      return 0;
    default:
      printf("Illegal code\n");
    }
    printf("\n");
  }
}

////////////////////////ADD GUEST////////////////////////////////////////////
struct guest *add_guest(struct guest *list){
  struct guest *p; // p will be set to list
  struct guest *new_guest = malloc(sizeof(struct guest)); // making space
  struct guest *end = list; // end will be initially set to first node

  printf("Enter phone number: ");
  read_line(new_guest->phone, PHONE_LEN);

  for (p = list; p != NULL; p = p->next){ // iterating until last node
    if (strcmp(new_guest->phone, p->phone) == 0) { // if new_guest phone is equal to phone in list already
      printf("guest already exists.");
      free(new_guest);  // freeing that space we made since its not needed
      new_guest = NULL; // used to prevent dangling pointer
      return list;      // returning list
    }
  }
  // new guest details
  printf("Enter guest's last name: ");
  read_line(new_guest->last, NAME_LEN);
  printf("Enter guest's first name: ");
  read_line(new_guest->first, NAME_LEN);
  printf("Enter party size: ");
  scanf("%d", &(new_guest->party_size));

  new_guest->next = NULL; // setting next to null that way new_guest can be set to last node
            // and new_guest->next matks the end of the chain

  if (list == NULL){ // If the list is empty....
    list = new_guest; //  set first node to new_guest so it will be first in chain
    return new_guest; // returning new_guest pointer
  } 
  else{            // otherwise...
    for (end = list; end->next != NULL; end = end->next);   //iterate until end-next = end
    end->next = new_guest; // that way we can finally add our guest to the end
  }
  return list; // return list
}

////////////////////////////////// REMOVE GUEST ////////////////////////////////////
struct guest *remove_guest(struct guest *list){
  struct guest *current = list; // current == first in node
  struct guest *prev = NULL;    // prev points to nothing right now
  struct guest *remove_guest = malloc(sizeof(struct guest)); // making space
  printf("Enter phone number: ");
  scanf("%s", remove_guest->phone); // saving new guest phone to list->phone
  printf("Enter guest's last name: ");
  read_line(remove_guest->last, NAME_LEN); // saving new guest last name list->laast
  printf("Enter guest's first name: ");
  read_line(remove_guest->first, NAME_LEN); // reading new guest first name list->first


  ////null for loop to iterate through list and find guest
  for (current = list, prev = NULL; current != NULL && (strcmp(current->phone, remove_guest->phone) != 0) &&(strcmp(current->first, remove_guest->first) != 0) && (strcmp(current->last, remove_guest->last) != 0); prev = current, current = current->next);

  // if statment to check if the guest was found and comparing guest info
  if (current != NULL && (strcmp(current->phone, remove_guest->phone) == 0) && (strcmp(current->first, remove_guest->first) == 0) && (strcmp(current->last, remove_guest->last) == 0)){  

    if (prev != NULL){ // If the guest is not the first node
      prev->next = current->next; // Set the previous node to the next node of current so we skip over that guest 
    } 
    else{ // However, if guest is the first node
      list = current->next; //we will want to set list to the next node of current (NULL) so we skip over that guest 
    }
    free(remove_guest); //freeing current 
    remove_guest = NULL; // used to prevent dangling pointer
  }

  else{ // howver if current goes through loop until the end and does not find the phone number
    printf("guest not found.");
  }

  return list; // Return the updated list back to function call
}


////////////////////////PRINT GUEST////////////////////////////////////////////
void print_list(struct guest *list){
  struct guest *p;
  for (p = list; p != NULL; p = p->next){ // continues until last node
    // printing the phone, last, first, and size of the node we are at
    printf("%-15s%-20s%-20s%5d\n", p->phone, p->last, p->first, p->party_size);
  }
}

////////////////////////CLEAR GUEST////////////////////////////////////////////

void clear_list(struct guest *list){
  struct guest *p;
  // This is basically incrementing up the chain so we can continue clearing
  while (list != NULL){
    p = list;          // p= first node of chain
    list = list->next; // first node of chain now = next node of chain.

    if (p != NULL) { // if p is not null
      free(p);  // free the memory of p. implement until we reach the last node
      p = NULL; // setting p =NULL to avoid daqngling pointers
    }
  }
}

////////////////////////READ LINE
/// FUNC////////////////////////////////////////////

int read_line(char str[], int n) {
  int ch, i = 0;
  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}
