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
#include "project4.c"


int
main(){
  
  //variable declarations
  ticket_t * new = NULL;
  ticket_t * assign = NULL;
  ticket_t * complete = NULL;
  int option;  
  int count = 1;

  printf("Hello! This program will create, assign, and complete the tickets \nyou enter. Start by choosing one of the options below.\n");
  
  while (1) {
    printMenu();
    printf("Enter desired option: ");
    scanf("%d", &option);
    printf("\n");
    
    
    switch (option) {
    case 1: newTicket(&new, count);
      count++;
      break;
    case 2: assignTicket(&new, &assign);
      break;
    case 3: completeTicket(&assign, &complete);
      break;
    case 4: printList(new);
      break;
    case 5: printList(assign);
      break;
    case 6: printList(complete);
      break;
    case 7: exitProgram();
      return 0;
      break;
    default: printf ("Invalid Option - Try Again!\n");
      return 0;
      continue;
    } // switch
  } // while 
}//main
