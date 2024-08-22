#include "simpleshell.h"

/**
 * execute_command - Crée un processus enfant pour exécuter une commande
 * @command: Commande à exécuter
 * @argv: Nom du programme pour les messages d'erreur
 * @env: Variables d'environnement
 */
void execute_command(char *command, char **argv, char **env)
{
	pid_t child_pid;
	int child_status;
	char *args[2];

	child_pid = fork(); /*Créer un processus enfant*/
	if (child_pid == -1)
	{
		perror("Erreur de fork");
		return;
	}

	if (child_pid == 0)
	{
		args[0] = command; /*Commande à exécuter*/
		args[1] = NULL;	   /*Terminaison du tableau d'arguments*/
		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&child_status); /*Attendre que l'enfant se termine*/
	}
}
