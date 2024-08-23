#include "simpleshell.h"

/**
 * main - A simple shell which execute commands with their complete path
 * @argc: Argument count
 * @argv: Argument array
 * @env: Var environement for main
 *
 * Return: Always 0.
 */

int main(int argc, char **argv, char **env)
{
	char *command = NULL;
	char **tokenised_command = NULL;
	int value_returned_built_in;

	(void)argc;						/*Unused var*/
	while (1)
	{
		if (isatty(STDIN_FILENO))	/* Display prompt */
			printf("$ ");

		command = read_line();

		tokenised_command = split_string_in_token(command);
		if (tokenised_command == NULL)
		{
			free(command);
			continue;
		}
		value_returned_built_in = built_in(tokenised_command, env);
		if (value_returned_built_in == 2)
		{
			free(command);
			free_tokenised_command(tokenised_command);
			exit(EXIT_SUCCESS);
		}
		else if (value_returned_built_in == 0)
		{
			free(command);
			free_tokenised_command(tokenised_command);
			continue;
		}

		execute_command(tokenised_command, env, argv[0]);

		free(command);
		free_tokenised_command(tokenised_command);
	}
	return (0);
}
