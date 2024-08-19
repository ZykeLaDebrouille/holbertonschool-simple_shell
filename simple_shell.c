#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
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
 * main - Un shell simple qui exécute des commandes avec leur chemin complet
 * @argc: Argument count
 * @argv: Argument array
 * @envp: Environment variables
 *
 * Return: Toujours 0.
 */
int main(int argc, char **argv, char **envp)
{
	char *command = NULL, *args[2];
	size_t input_length = 0;
	ssize_t inputUSER;
	pid_t child_pid;
	int child_status;
	(void)argc; /*unused*/
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		inputUSER = getline(&command, &input_length, stdin);
		if (inputUSER == -1) /*CTRL+D*/
		{
			printf("\n");
			break;
		}
		remove_newline(command);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Erreur de fork");
			continue;
		}
		if (child_pid == 0)
		{
			args[0] = command; /* Commande à exécuter */
			args[1] = NULL; /* Terminaison du tableau d'arguments */
			if (execve(args[0], args, envp) == -1)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&child_status); /* Attendre que l'enfant se termine */
	}
	free(command);
	return (0);
}

