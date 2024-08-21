#ifndef SIMPLESHELL_h
#define SIMPLESHELL_h


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* past functions created before */

int _strlen(char *s);
/** Function to count a string lenght */

char *_memset(char *s, char b, unsigned int n);
/** 
 * Fonction permettant d'enregistrer un byte (ou valeur) 
 * dans la mémoire sélectionnée */

void *_calloc(unsigned int nmemb, unsigned int size);
/* Function that allocates memory for an array, using malloc */

/* past functions created before */


int getppid(void);
/** Print the PPID */

int print_all_argv(int argc, char *argv[]);
/** Prints all argv without using ac */

char *read_line(void);
/** Reads the input and print it */

char **split_string_in_token(char *str);
/** Splits a string into tokens with a delimiter */

char *remove_newline(char *line);
/** Remove the new_line of a given input */

void print_env(char **env);
/** Print environment */

void execute_command(char *command, char **argv, char **env);
/** fork*/


#endif
