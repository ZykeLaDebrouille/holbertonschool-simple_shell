#include "shell.h"
/**
 * remove_newline - replace the '\n' by a null byte
 * @str: string to be tested
 */
void remove_newline(char *str)
{
	size_t i = 0;

	/* character or end of string is found */
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0'; /* Replace newline with null terminator */
			break;
		}
		i++;
	}
}
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
		args[1] = NULL; /*Terminaison du tableau d'arguments*/
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
 * @envp: Environment variables
 *
 * Return: Toujours 0.
 */
int main(int argc, char **argv, char **envp)
{
	char *command = NULL;
	size_t input_length = 0;
	ssize_t inputUSER;
	(void)argc; /*unused*/
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		inputUSER = getline(&command, &input_length, stdin);
		if (inputUSER == -1) /* si CTRL+D*/
		{
			printf("\n");
			break;
		}
		remove_newline(command);

		if (access(command, X_OK) == -1) /*Vérifier si la commande est exécutable*/
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
			continue;
		}

		execute_command(command, argv, envp); /*Appele fonction pour exéc commande*/
	}
	free(command);
	return (0);
}

