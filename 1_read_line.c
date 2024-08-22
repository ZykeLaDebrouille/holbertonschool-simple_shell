#include "simpleshell.h"

/**
 * read_line - Read line given in the standard input(keyboard)
 *
 * Return: Always 0.
 */

char *read_line(void)
{
	char *line = NULL;		/** Pointer to store the input line */
	size_t len = 0;			/* Initial buffer size for getline */
	ssize_t read;

	read = getline(&line, &len, stdin);
	/** "read" stores the number of characters read by getline */

	if (read == -1)			/* Check if getline failed or reached EOF */
	{
		free(line);			/** Free the stored line */
		exit(EXIT_FAILURE); /** Exit if failure */
	}
	signal(2, SIG_IGN);		/** Ignore "Ctrl+C" (no exit when ^C)  */
	remove_newline(line);	/** Replace the "\n" by "\0" at the end */
	return (line);
}
