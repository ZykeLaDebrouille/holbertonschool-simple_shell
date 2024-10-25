/**
 * _strlen - Function to count a string length
 * @s: string to count
 * Return: lengh
 */

int _strlen(char *s)
{
	int count;

	count = 0;

	/** Iterate through the string */
	while (*s != '\0')
	{
		/** Increment count for each character */
		count++;
		/* Move to the next character */
		s++;
	}

	/** Return the total count (length of the string) */
	return (count);
}
