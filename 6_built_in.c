#include "simpleshell.h"

/**
 * built_in - Handle built-in commands
 * @command: command to check
 * @env: environment variables
 *
 * Return: 2 for exit, 0 for other built-ins, 1 for non-built-ins
 */

int built_in(char *command, char **env)
{
	if (command == NULL)
		return (1);		/** Treat NULL command as non-built-in */

	if (strcmp(command, "exit") == 0)
		return (2);		/** Special return value for exit */

	if (strcmp(command, "env") == 0)
	{
		print_env(env);	/** Print environment variables */
		return (0);		/** Indicate built-in command was executed */
	}

	return (1);			/** Indicate command is not a built-in */
}
