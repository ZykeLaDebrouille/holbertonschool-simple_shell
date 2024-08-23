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
			exit(127);  /** 127 is the standard exit code for "command not found" */
		}

		if (execve(command[0], command, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", shell_name, command[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &child_status, 0);
		if (WIFEXITED(child_status))
		{
			return (WEXITSTATUS(child_status));
		}
		else if (WIFSIGNALED(child_status))
		{
			return (WTERMSIG(child_status) + 128);
		}
	}
	return (1);  /** This should never be reached */
}
