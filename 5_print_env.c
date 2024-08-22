#include "simpleshell.h"
/**
 * print_env - Print all variables of the environnement
 * @env: Array of strings of environnement variables
 */
void print_env(char **env)
{
	int index = 0;

	while (env[index]) /*go through environnement*/
	{
		printf("%s\n", env[index]);
		index++;
	}
}

/**
 * _getenv - Get the value of the environnement variable
 * @name: Name of the environnement var to look for
 * @env: Array of strings of environnement variables
 *
 * Return: Value of the environnement var or NULL if not found.
 */

char *_getenv(const char *name, char **env)
{
	int index = 0;
	size_t len = strlen(name);

	while (env[index] != NULL)
	{
		/** Check if current env var matches the name */
		if (strncmp(env[index], name, len) == 0 && env[index][len] == '=')
		{
			return (env[index] + len + 1); /** Return value after '=' */
		}
		index++;
	}
	return (NULL);							/** Return NULL if not found */
}
