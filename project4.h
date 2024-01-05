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
#ifndef __PROJECT4_H__
#define __PROJECT4_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRLEN 127


/* Stringify a literal without macro expansion */
#define STR(EXPR) #EXPR

/* Construct a size-limited scanf format string for a character buffer */
#define SCANSTR(LEN) "%" STR(LEN) "s"

//Here is our ticket struct
typedef struct ticket ticket_t;

struct ticket{
  int ticket_num;
  char company[MAXSTRLEN + 1];
  char problem[MAXSTRLEN + 1];
  char status[MAXSTRLEN + 1];
  char technician[MAXSTRLEN + 1];
  ticket_t * next;
};


//Function Prototypes
void getString(char * prompt, char * buffer);

void printMenu(void);

void newTicket(ticket_t ** first, int count);

void assignTicket(ticket_t ** first, ticket_t ** assign);

void completeTicket(ticket_t ** first, ticket_t ** complete);

void printList(ticket_t * first);

void printAssign(ticket_t * first);

void printComplete(ticket_t * first);

void exitProgram(void);

#endif
