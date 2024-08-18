#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * main - Un shell simple qui exécute des commandes avec leur chemin complet
 *
 * Return: Toujours 0.
 */
int main(void)
{
    char *input_user = NULL;
    size_t input_length = 0;
    ssize_t command_size;
    pid_t child_pid;
    int child_status;
    char *args[2];

    while (1)
    {
        /* Afficher le prompt */
        printf("$ ");
        command_size = getline(&input_user, &input_length, stdin);
        if (command_size == -1)
        {
            if (errno == 0)
            {
                /* EOF atteint, quitter la boucle */
                printf("\n");
                break;
            }
            else
            {
                perror("Erreur de lecture de la ligne");
                continue;
            }
        }

        /* Supprimer le caractère de nouvelle ligne */
        if (input_user[command_size - 1] == '\n')
            input_user[command_size - 1] = '\0';

        /* Vérifier si l'utilisateur veut quitter */
        if (strcmp(input_user, "exit") == 0)
            break;

        /* Créer un processus enfant */
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Erreur de fork");
            continue;
        }

        if (child_pid == 0)
        {
            /* Dans le processus enfant */
            args[0] = input_user; /* Commande à exécuter */
            args[1] = NULL; /* Terminaison du tableau d'arguments */
            if (execve(args[0], args, NULL) == -1)
            {
                perror("Erreur d'exécution de la commande");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* Dans le processus parent */
            wait(&child_status); /* Attendre que l'enfant se termine */
        }
    }

    free(input_user);
    return (0);
}
