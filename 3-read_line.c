#include "simpleshell.h"

/**
 * read_line - Read line givent in the input
 *
 * Return: Always 0.
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	remove_newline(line);
	return (line);
}
