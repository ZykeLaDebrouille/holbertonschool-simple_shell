#include "simpleshell.h"

/**
 * main - entry point
 *
 * Return: Always 0.
 */

int main(void)
{
	char *line_to_tokenised;
	int status = 1;

	while (status)
	{
		printf("/$ ");
		fflush(stdout);

		line_to_tokenised = read_line();
		if (!line_to_tokenised)
		{
			printf("Failed to read line\n");
			return (1);
		}

		split_string_in_token(line_to_tokenised);

	}

	free(line_to_tokenised);
	return (0);
}
