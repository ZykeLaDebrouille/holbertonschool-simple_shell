#include "simpleshell.h"

/**
 * split_string_in_token - Split a string into tokens and prints them
 * @str: the string to be tokenized
 *
 * Return: Array of tokens or NULL if an error occurred
 */

char **split_string_in_token(char *str)
{
	char *token = NULL;
	char **array_of_token;				/** Array to store tokenized strings */
	char *string_to_tokenized = NULL;
	int index = 0;						/** Index for array_of_token loop */
	int size_array_of_token = 100;		/** Unreachable maximum number of tokens */

	if (str == NULL)
		return (NULL);

	string_to_tokenized = strdup(str);	/** Create a copy to avoid modifying str */
	if (string_to_tokenized == NULL)
		return (NULL);

	/** Allocate memory for the array of tokens */
	array_of_token = _calloc(size_array_of_token, sizeof(char *));
	if (array_of_token == NULL)
	{
		free(string_to_tokenized);
		return (NULL);
	}

	/* Tokenize the string using space, tab, and newline as delimiters */
	token = strtok(string_to_tokenized, " \t\n");
	while (token != NULL && index < size_array_of_token - 1)
	{
		array_of_token[index] = strdup(token);
		if (array_of_token[index] == NULL)
		{
			free_tokenised_command(array_of_token);
			free(string_to_tokenized);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
		index++;
	}
	array_of_token[index] = NULL;		/* Terminate the array with NULL */

	free(string_to_tokenized);
	return (array_of_token);
}
