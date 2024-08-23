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
	char *command = NULL;											/** Store user input command */
	char **tokenised_command = NULL;								/** Store tokenized command */
	int value_returned_built_in, status = 0, exitstatus = 0;

	(void)argc;														/** Suppress unused variable warning */
	while (1)														/** Infinite loop for shell prompt */
	{
		if (isatty(STDIN_FILENO))									/** Check if input is from terminal */
			printf("$ ");											/** Display shell prompt */

		command = read_line();										/** Read user input and stores in command */

		tokenised_command = split_string_in_token(command);			/** Token command */
		if (tokenised_command == NULL)								/** Check if tokenization failed */
		{
			free(command);											/** Free memory allocated for command */
			continue;												/** Skip to next iteration */
		}
		value_returned_built_in = built_in(tokenised_command, env);
		if (value_returned_built_in == 2)							/** If returned "2": exit command */
		{
			free(command);											/** Free memory allocated for command */
			free_tokenised_command(tokenised_command);				/** Free tokenized command */
			exit(EXIT_SUCCESS);										/** Exit shell */
		}
		else if (value_returned_built_in == 0)						/** If other built-in command */
		{
			free(command);											/** Free memory allocated for command */
			free_tokenised_command(tokenised_command);				/** Free tokenized command */
			continue;												/** Skip to next iteration */
		}

		status = execute_command(tokenised_command, env, argv[0]);
		exitstatus = status;
		free(command);												/** Free memory allocated for command */
		free_tokenised_command(tokenised_command);					/** Free tokenized command */
	}
		return (exitstatus);
}
