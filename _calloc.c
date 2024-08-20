#include "simpleshell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _memset - Fonction permettant d'enregistrer un byte (ou valeur)
 * dans la mémoire sélectionnée
 * @s: mémoire selectionnée
 * @b: byte ou valeur à ajouter
 * @n: nombre de bytes qui doivent être recouverts
 * Return: *s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int count;

	for (count = 0 ; count != n ; count++)
	{
		s[count] = b;
	}

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

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	totalmemsize = malloc(nmemb * size);

	if (totalmemsize == NULL)
	{
		return (NULL);
	}

	_memset(totalmemsize, 0, nmemb * size);

	return (totalmemsize);
}
