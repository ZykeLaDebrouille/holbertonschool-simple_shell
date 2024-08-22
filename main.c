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

	(void)argc; /*Unused var*/
	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Display prompt */
			printf("$ ");

		command = read_line();
		if (command == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (command[0] == '\0' || command[0] == '\n')
		{
			free(command);
			continue; /* Skip empty commands */
		}

		tokenised_command = split_string_in_token(command);
		if (tokenised_command == NULL)
		{
			free(command);
			continue;
		}

		if (built_in(tokenised_command[0], env) == 2)
		{
			free(command);
			free_tokenised_command(tokenised_command);
			exit(EXIT_SUCCESS);
		}
		else if (built_in(tokenised_command[0], env) == 0)
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
