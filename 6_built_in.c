#include "simpleshell.h"

/**
 * built_in - Handle built-in commands
 * @command: command to check
 * @env: environment variables
 *
 * Return: 2 for exit, 0 for other built-ins, 1 for non-built-ins
 */

int built_in(char **command, char **env)
{
	if (command == NULL)
		return (1);		/** Treat NULL command as non-built-in */

	if (strcmp(command[0], "exit") == 0)
		return (2);		/** Special return value for exit */

	if (strcmp(command[0], "env") == 0)
	{
		print_env(env);	/** Print environment variables */
		return (0);		/** Indicate built-in command was executed */
	}
	if (strcmp(command[0], "help") == 0)
		return (help_builtin(command));

	return (1);
}

/**
 * help_builtin - Provide information on internal orders.
 * @command: Array of command arguments.
 *
 * Return: return (0) function has been completed successfully.
 */
int help_builtin(char **command)
{
	if (command[1] == NULL)
	{
		printf("here are the builtins commands we've implemented so far\n\n");
		printf("use this command to get more help about exit:  help exit\n");
		printf("use this command to get more help about env:  help env\n");
	}
	else
	{
		/* Show help for specific command */
		help_builtin_cmd(command);
	}
	return (0);
}

/**
 * help_builtin_cmd - displays help for builtins cmd
 * @command: command to display help for
 */
void help_builtin_cmd(char **command)
{
	/* Display help for 'exit' command */
	if (strcmp(command[1], "exit") == 0)
	{
		printf("exit: quits the shell programm.\n");
		printf("Usage: $exit\n");
	}
	/* Display help for 'env' command */
	if (strcmp(command[1], "env") == 0)
	{
		printf("env: display environnement.\n");
		printf("Usage: $env\n");
	}
	/* Display help for 'help' command */
	else if (strcmp(command[1], "help") == 0)
	{
		printf("help: what a command do and how to use it.\n");
		printf("Usage: $help \"command\"\n");
	}
}
