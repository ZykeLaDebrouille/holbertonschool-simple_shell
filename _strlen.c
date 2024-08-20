/**
 * _strlen - Function to count a string lenght
 * @s: string to count
 * Return: lengh
 */

int _strlen(char *s)
{
	int count;

	count = 0;

	while (*s != '\0')

		/**
		* Allows to traverse the array to which point s
		* "*s" literally designates this array I do not need
		* its memory address with p = &s or other.
		*/
	{
		count++;
		s++;
	}

	return (count);
}
