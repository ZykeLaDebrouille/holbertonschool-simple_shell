#include "simpleshell.h"

/**
 * split_string_in_token - Split a string into tokens and prints them
 * @str: the string to be tokenized
 *
 * Return: 0 if successful, or 1 if an error occurred
 */

int split_string_in_token(char *str)
{
    /** Declare variables: */
    char *token = NULL; /** Pointer to store each token */
    char string_to_tokenised[1024]; /** Array to hold the copy of the string to be tokenized */
    char **array_of_token; /** Array of strings to store each token */
    int index = 0, temporary_index = 0; /** Indices for loops */
    int size_array_of_token = 100; /** Maximum number of tokens expected */

    /** Check if the input string is NULL */
    if (str == NULL)
    {
        perror("Failed : string NULL"); /** Print an error message if str is NULL */
        return (1);  /** Return an error code to indicate failure */
    }

    remove_newline(str); /** Function to remove the newline character from the input string */

    /** Allocate memory for the array_of_token, each element is a char pointer */
    array_of_token = _calloc(size_array_of_token, sizeof(char *));
    if (array_of_token == NULL)
    {
        perror("Failed to allocate memory"); /** Print an error message if memory allocation fails */
        return (1); /** Return an error code to indicate failure */
    }

    /** Copy the content of line into string_to_tokenised */
    while (str[index] != '\0') /** Loop until the end of the string */
    {
        string_to_tokenised[index] = str[index]; /** Copy each character */
        index++;
    }

    /** Tokenize the string using space as the delimiter */
    token = strtok(string_to_tokenised, " ");

    /** Reset index to 0 for the next loop */
    index = 0;
    
    /** Loop to keep extracting tokens and storing them in array_of_token */
    while (token != NULL)
    {
        array_of_token[index] = token; /** Store the current token */
        token = strtok(NULL, " "); /** Get the next token */
		index++;
    }
    
    /** Add NULL at the end of array_of_token to indicate the end of the array */
    array_of_token[index] = NULL;

    /** Print each token stored in array_of_token */
    while (temporary_index < index)
    {
        printf("%s\n", array_of_token[temporary_index]); /** Print each token */
        temporary_index++;
    }
    
    /** Free the allocated memory for the array_of_token */
    free(array_of_token);
    return (0); /** Return 0 to indicate success */
}
