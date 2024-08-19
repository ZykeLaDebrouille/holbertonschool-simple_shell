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
 *
 * Return: Toujours 0.
 */
int main(void)
{
	char *input_user = NULL, *args[2];
	size_t input_length = 0;
	ssize_t command_size;
	pid_t child_pid;
	int child_status;

	while (1)
	{	printf("$ ");
		command_size = getline(&input_user, &input_length, stdin);
		if (command_size == -1)
		{
			printf("\n");
			break;
		}
		remove_newline(input_user);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Erreur de fork");
			break;
		}
		if (child_pid == 0)
		{
			args[0] = input_user; /* Commande à exécuter */
			args[1] = NULL; /* Terminaison du tableau d'arguments */
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Erreur d'exécution de la commande");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&child_status); /* Attendre que l'enfant se termine */
	}
	free(input_user);
	return (0);
}

