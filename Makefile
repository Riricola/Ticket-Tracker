# File:          Makefile
# Author:        Maria Roriguez and Alma Ordaz
# Created:       24 April 2023
# Acknowledgement:  adapted from an example by Marge Coahran
#-------------------------------------------------------------
# Use the clang compiler
CC = clang

# Set compilation flags
#   -ansi       check syntax against the American National Standard for C
#   -g          include debugging information
#   -Wall       report all warnings
#   -std=gnu99  use the GNU extensions of the C99 standard

#----------------------------------------------------------------------------
# build rules:
#
# Each rule takes the following form  (Note there MUST be a tab,
# as opposed to several spaces, preceeding each command.
#
# target_name:  dependency_list
#	command(s)

all: project4

# List program components, what they depend on, and how to compile or link each

project4: project4-test.o 
	$(CC) -o project4 project4-test.o

project4-test.o: project4-test.c project4.h
	$(CC) $(CFLAGS) -c project4-test.c

#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   the built program, object files, old emacs source versions, and core dumps.

clean:
	rm -f list *.o *~ core*
