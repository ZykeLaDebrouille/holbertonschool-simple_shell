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
