#include "simpleshell.h"

/**
 * remove_newline - replace the '\n' by a null byte
 * @line: string to be tested
 * Return: str
 */

char *remove_newline(char *line)
{
	size_t index = 0;
	/* character or end of string is found */
	while (line[index] != '\0')
	{
		if (line[index] == '\n')
		{
			line[index] = '\0'; /* Replace newline with null terminator */
			break;
		}
		index++;
	}
	return (line);
}
