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
void remove_newline(char *str);
void execute_command(char *command, char **argv, char **env);
int main(int argc, char **argv, char **envp);

/**/

#endif
