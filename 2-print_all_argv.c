#include "simpleshell.h"

/**
 * print_all_argv - Entry point of the program
 * @argc: Argument count (not used in this program)
 * @argv: Argument vector (array of strings)
 *
 * Return: 0 on success
 */

int print_all_argv(int argc, char *argv[])
{
	int index = 0;
	/** Iterate over the arguments until reaching the end (NULL) */
	for (index = 0; argv[index] != NULL; index++)
	{
		/** Print each argument followed by a space */
		printf("%s ", argv[index]);
	}

	(void)argc; /** Casting argc to void to indicate it's unused */
	/** Print a newline at the end */
	printf("\n");

	return (0);
	}
