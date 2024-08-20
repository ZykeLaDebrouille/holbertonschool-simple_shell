#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define BUFSIZE 1024

/*simple_shell.c*/
void remove_newline(char *str);/*si nouvelle ligne remplace par "\0"*/
void execute_command(char *command, char **argv, char **env);/*fork pour le child process*/

/*print_env.c*/
void print_env(char **env); /*avoir l'environnement*/

#endif
