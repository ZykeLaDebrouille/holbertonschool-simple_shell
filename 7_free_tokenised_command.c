#include "simpleshell.h"

/**
 * free_tokenised_command - Frees the memory allocated for tokenised command
 * @tokenised_command: Array of tokens to be freed
 */
void free_tokenised_command(char **tokenised_command)
{
	int index = 0;

	if (tokenised_command == NULL)
		return;							/* Nothing to free if array is NULL */

	for (index = 0; tokenised_command[index] != NULL; index++)
	{
		free(tokenised_command[index]); /* Free each token string */
	}
	free(tokenised_command);			/* Free the array itself */
}
