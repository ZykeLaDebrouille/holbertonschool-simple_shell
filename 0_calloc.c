#include "simpleshell.h"

/**
 * _memset - Fills memory with a constant byte
 * @s: Pointer to the memory area to be filled
 * @b: The constant byte to fill the memory with
 * @n: Number of bytes to be filled
 *
 * Return: Pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int count;

	/** Loop through "n" bytes of memory */
	for (count = 0; count < n; count++)
	{
		/** Set each byte to the value of "b" */
		s[count] = b;
	}

	/** Return the pointer to the memory area */
	return (s);
}

/**
 * _calloc - Function that allocates memory for an array, using malloc
 * @nmemb: number of elements
 * @size: size of elements
 *
 * Return: NULL on failure
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *totalmemsize;

	/** Check if "nmemb" or size is 0 */
	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	/** Allocate memory for the array */
	totalmemsize = malloc(nmemb * size);

	/** Check if malloc failed */
	if (totalmemsize == NULL)
	{
		return (NULL);
	}

	/** Initialize allocated memory to zero */
	_memset(totalmemsize, 0, nmemb * size);

	/** Return pointer to allocated memory */
	return (totalmemsize);
}
