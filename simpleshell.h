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
#include <signal.h>

/** Past functions created in previous projects */

int _strlen(char *s);
/** Function to count a string lenght */

char *_memset(char *s, char b, unsigned int n);
/** 
 * Fonction permettant d'enregistrer un byte (ou valeur) 
 * dans la mémoire sélectionnée
 */

void *_calloc(unsigned int nmemb, unsigned int size);
/** Function that allocates memory for an array, using malloc */

/** Past functions created in previous projects */

char *read_line(void);
/** Reads the input and print it */

char **split_string_in_token(char *str);
/** Splits a string into tokens with a delimiter */

char *remove_newline(char *line);
/** Remove the new_line of a given input */

void execute_command(char **command, char **env, char *shell_name);
/** Fork to creat a child process to execute a command*/

void print_env(char **env);
/** Print environment */

int help_builtin(char **command);
/** display help command */

void help_builtin_cmd(char **command);
/** help with "command" */

int built_in(char **command, char **env);
/** Exit if "exit" typed, print environment if "env" typed */

void free_tokenised_command(char **tokenised_command);
/** Function to free an array of strings */

#endif
