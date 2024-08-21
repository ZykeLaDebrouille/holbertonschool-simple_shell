#include "simpleshell.h"
/**
 * built_in - command built_in
 * @command: command
 * @environ: variable environnement
 *
 * Return: int
*/
int built_in(char *command, char **environ)
{
	if (command == NULL) /*si pas de commande*/
	{
		return (1);
	}

	if (strcmp(command, "exit") == 0) /* si commande = "exit" */
	{
		free(command);
		exit(EXIT_SUCCESS);
		return (0);
	}

	if (strcmp(command, "env") == 0) /* si commande = "env "*/
	{
		print_env(environ);
		return (0);
	}
}
