#include "shell.h"
/**
 * print_env - Imprime toutes les variables d'environnement
 * @env: Tableau de chaînes de caractères des variables d'environnement
 */
void print_env(char **env)
{
	int i = 0;

	while (env[i]) /*parcours env*/
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
 * _getenv - Récupère la valeur d'une variable d'environnement
 * @name: Nom de la variable d'environnement à rechercher
 * @env: Tableau de chaînes de caractères des variables d'environnement
 *
 * Return: Valeur de la variable d'environnement ou NULL si non trouvé
 */
char *_getenv(const char *name, char **env)
{
	int i = 0;
	size_t len = strlen(name);

	while (env[i] != NULL)
	{
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (env[i] + len + 1); /*Retourne la valeur après le '='*/
		}
		i++;
	}
	return (NULL);
}
