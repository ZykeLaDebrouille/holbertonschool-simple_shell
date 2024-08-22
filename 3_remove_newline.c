#include "simpleshell.h"

/**
 * remove_newline - replace the '\n' by a null byte
 * @line: string to be tested
 *
 * Return: str
 */

char *remove_newline(char *line)
{
	size_t index = 0;

	while (line[index] != '\0') /** Iterate through the string */
	{
		if (line[index] == '\n')
		{
			line[index] = '\0';	/** Replace newline with null terminator */
			break;				/** Exit loop after replacing */
		}
		index++;
	}
	return (line);
}
