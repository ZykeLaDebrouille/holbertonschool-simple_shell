#include <stdio.h>
#include <unistd.h>

/**
 * getppid - get the ppid
 *
 * Return: Always 0.
 */

int getppid(void)
{
	pid_t my_pid;

	my_pid = getppid();
	printf("%u\n", my_pid);
	return (0);
}
