#include "simpleshell.h"

/**
 * execute_command - Create a child process to execute a command
 * @command: command to execute
 * @env: environment variables
 * @shell_name: name of the shell (argv[0])
 *
 * Return: 1 if error, 0 if success
 */

int execute_command(char **command, char **env, char *shell_name)
{
	pid_t child_pid;
	int child_status;

	if (command == NULL || command[0] == NULL || command[0][0] == '\0')
		return (0);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error");
		return (1);
	}

	if (child_pid == 0)
	{
		if (access(command[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", shell_name, command[0]);
			exit(EXIT_FAILURE);
		}

		if (execve(command[0], command, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", shell_name, command[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&child_status); /** Wait for child status */
	}
}
