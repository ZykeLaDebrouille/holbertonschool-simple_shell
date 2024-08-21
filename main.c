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
/**
 * main - Un shell simple qui exécute des commandes avec leur chemin complet
 * @argc: Argument count
 * @argv: Argument array
 * @env: Environment variables pour le main
 *
 * Return: Toujours 0.
 */
int main(int argc, char **argv, char **env)
{
	char *command = NULL;
	char **tokenised_command = NULL;
	size_t command_size = 0;

	(void)argc; /*UNUSED*/
	while (1)
	{
		if (isatty(STDIN_FILENO)) /* DISPLAY PROMPT */
			printf("$ ");

		command = read_line;

		tokenised_command = split_string_in_token(command);/*TOKENISE LA COMMAND*/
		if (access(tokenised_command, X_OK) == -1) /*Vérif command est exécutable*/
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], tokenised_command);
			continue;
		}

		execute_command(tokenised_command, argv, env); /*fork pour exéc commande*/
	}
	free(command);
	return (0);
}
