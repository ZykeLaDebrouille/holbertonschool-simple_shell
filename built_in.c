#include "shell.h"
/**
 * built_in - command built_in
 * @command: command
 * @environ: variable environnement
 *
 * Return: int
*/
int built_in(char *command, char **environ)
{
	if (strcmp(command, "exit") == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(command, "env") == 0)
	{
		print_env(environ);
	}

}
