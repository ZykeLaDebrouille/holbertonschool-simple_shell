#include "simpleshell.h"

/**
 * execute_command - Create a child process to execute a command
 * @command: command to execute
 * @argv: Name of the program for the error message
 * @env: environnement variable
 */
void execute_command(char **command, char **argv, char **env)
{
	pid_t child_pid;
	int child_status;
	char *args[20];

	child_pid = fork(); /** Create a child process */
	if (child_pid == -1)
	{
		perror("Erreur de fork");
		return;
	}

	if (child_pid == 0)
	{
		args[0] = command[0]; /** Command to execute*/
		args[1] = NULL;	   /** End of the argument array */

		if (access(args[0], X_OK) == -1) /** Check if the command can be executed */
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
			exit(EXIT_FAILURE);
		}

		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&child_status); /*Attendre que l'enfant se termine*/
	}
}
