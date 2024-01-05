    /***********************************************************************
     * Name(s)  Maria Rodriguez and Alma Ordaz                             *
     * Assignment name: Ticker Tracker (Project 4)                         *
     *                                                                     *
     * Assignment for April 28, 2023                                       *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     CSC 161 Linked Lists (4/17) Lab & Program Management Lab (4/24) *
     *     getString() function was taken from namelist.c from Linked Lists*
     *     lab                                                             *
     *   Help obtained                                                     *
     *     Class mentor Ray, Barbara (office hours)                        *
     *                                                                     *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Alma Ordaz, Maria Rodriguez                            *
     ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project4.h"

//Here are the implementations of all the functions used in our
//Project4 file

/* pre-condition: None
   post-condition: prints a list of options in terminal
*/
void
printMenu(void){
  printf("Options Available: \n");
  printf ("1 - Create a new tracking ticket\n");
  printf ("2 - Assign a new ticket to a technician for handeling\n");
  printf ("3 - Mark a ticket complete\n");
  printf ("4 - Print a list of new tickets\n");
  printf ("5 - Print a list of assigned tickets\n");
  printf ("6 - Print a list of completed tickets\n");
  printf ("7 - Exit the program\n");
}


/* pre-condition: None  
  post-condition: attatches the response to prompt into buffer 
*/
void
getString( char * prompt, char * buffer) {
  int numTokens;
  do {
    printf ("%s", prompt);
    numTokens = scanf (SCANSTR(MAXSTRLEN), buffer);
    if (numTokens==0) {
      printf ("Error reading value. Please try again.\n");
      continue;
    }
  } while (numTokens==0);
} // getString


/* pre-condition: first must be a predefined ticket structure that 
                  had been assigned NULL. Count must be a predefined
                  int set to 1.
  post-condition: assigns the newly made ticket (assigned number count)
                  to the new tickets list.
*/
void
newTicket(ticket_t ** first, int count){
  //Variable Declarations
  ticket_t * current = *first;
  ticket_t * newTicket = (ticket_t*)malloc(sizeof(ticket_t));

  // error message if new ticket is not allocated the right space
  if (newTicket == NULL){
    perror("Space not allocated correcty");
  }

  //Assigns the new ticket it's properties
  getString ("Enter Company Name: ", newTicket->company);
  getString ("Enter Problem: ", newTicket->problem);
  strcpy(newTicket->status, "new");
  strcpy(newTicket->technician, "unassigned");
  newTicket->ticket_num = count;
  newTicket->next = NULL;

  //condition for when the list has no items      
  if(*first == NULL){
    newTicket->next = *first;
    *first = newTicket;
    return;
  }
  else //if the list does have items:
    {
      while(current->next != NULL)
        {
          current = current->next;
        }
      current->next = newTicket;
    }//else

}//newTicket


/* pre-condition: newList and assignList must be a predefined 
                  ticket structure that had been assigned NULL. 
  post-condition: adds a ticket node to the end of assignList 
                  while removing it from the front of newList.
*/
void assignTicket(ticket_t ** newList, ticket_t ** assignList){
  //variable definitions
  ticket_t * new = *newList;
  ticket_t * assigned = *assignList;
  ticket_t * prev = NULL;
  ticket_t * temp = new;
  
  // If the new ticket list is empty:
  if(*newList == NULL){
    printf("There are no new tickets to assign.\n\n");
    return;
  }

  //changes the ticket's properties
  strcpy(new->status, "assigned");
  getString("Change the technician's name: \n", new->technician);
  
  //if assigned list is empty
  if(assigned == NULL){
    *newList = new->next; //this redefines the list as without the first ticket
    new->next = NULL; //the single ticket is assigned to the list
    *assignList = new; //saves the list as having this ticket
  }

  //if assigned list is not empty, find the last spot, add the
  //ticket, and remove it from the new ticket list 
  else{
    *newList = new->next;
    while(assigned->next != NULL){
      assigned = assigned->next;     
    }
    assigned->next = temp;
    temp->next = NULL;
  } //else
}//assignTicket


/* pre-condition: assignList and completeList must be a predefined 
                  ticket structure that had been assigned NULL. 
  post-condition: searches assignList for the ticket number specified
                  then adds it to the front of the complete ticket list
*/
void completeTicket(ticket_t ** assignList, ticket_t ** completeList){
  //variable declarations
  ticket_t * assigned = *assignList;
  ticket_t * complete = *completeList;
  ticket_t * prev = NULL;
  int ticket;

  //if the assigned tickets list is empty
  if(*assignList == NULL){
    printf("There are no assigned tickets to be completed.\n\n");
    return;
  }

  //prompt the user for a ticket number
  printf("Enter ticket number: ");
  scanf("%d", &ticket);
  printf("\n");

  //if the assign ticket list has 1 ticket: (as in found->next == NULL)
  if(assigned->next == NULL){
    if(assigned->ticket_num != ticket){
      printf("Ticket number %d not found in the Assigned tickets list. \n\n", ticket);
      return;
    }
    else
      {
        *assignList = NULL;
      }
  }
  
  //if the assigned ticket is not the only one in the assign list
  if(assigned->next != NULL){
    while((assigned->next != NULL) && assigned->ticket_num != ticket){
      prev = assigned;
      assigned = assigned->next;
    }
    //after this, assigned should be the ticket, and assigned->next = NULL
    if(assigned->ticket_num != ticket){
      printf("Ticket number %d not found in the Assigned tickets list. \n\n", ticket);
      return;
    }
    //this step takes assigned out and stitches the list together
    prev->next = assigned->next;
  }
  
  if(assigned->ticket_num != ticket){
    printf("Ticket number %d is not found in the Assigned tickets list. \n\n", ticket);
    return;
  }
  
  
  //here we turn the assigned ticket into 'complete'
  strcpy(assigned->status, "completed");
  printf("Ticket number %d has been completed \n\n", ticket);
  
  //if the complete list is empty,
  if(complete == NULL){
    assigned->next = NULL;
    *completeList = assigned;
  }
  else
    {
      while(complete->next != NULL){
        complete = complete->next;
      }
      complete->next = assigned;
      assigned->next = NULL;
    }
  
}//completeTicket


/* pre-condition: None 
  post-condition: prints the specified list 
*/
void printList(ticket_t * list){
  // error msg if the list you're trying to print is empty
  if(list == NULL)
    printf("There are no tickets. \n\n");
  
  for(ticket_t * current = list; current != NULL; current = current->next)
    {
      printf("Ticket Number: %d \n", current->ticket_num);
      printf("Company Identifier: %s \n", current->company);
      printf("Problem: %s \n", current->problem);
      printf("Status: %s \n", current->status);
      printf("Technician Name: %s \n", current->technician);
      printf("\n");
    }
}//printList


/* pre-condition:  None
  post-condition:  prints a farewell message and exits the program
*/
void exitProgram(void){
  printf("Thank you for working on the tickets, have a nice day! :)\n");
  return;
}//exitProgram
