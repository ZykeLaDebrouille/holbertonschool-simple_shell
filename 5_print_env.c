#include "simpleshell.h"
/**
 * print_env - Print all variables of the environnement
 * @env: Array of strings of environnement variables
 */
void print_env(char **env)
{
	int i = 0;

	while (env[i]) /*go through environnement*/
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
 * _getenv - Get the value of the environnement variable
 * @name: Name of the environnement car to look for
 * @env: Array of strings of environnement variables
 *
 * Return: Value of the environnement var or NULL if not found.
 */
char *_getenv(const char *name, char **env)
{
	int i = 0;
	size_t len = strlen(name);

	while (env[i] != NULL)
	{
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (env[i] + len + 1); /*return the value after '='*/
		}
		i++;
	}
	return (NULL);
}
