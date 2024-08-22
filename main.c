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

		tokenised_command = split_string_in_token(command);/** Tokenised "command" */

		built_in(command, env);
		execute_command(tokenised_command, argv, env); /*fork to execute command*/
	}
	free(command);
	return (0);
}
