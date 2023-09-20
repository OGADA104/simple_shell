#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * custom_getline - Read a line of text from standard input
 *
 * Return: A pointer to the line read from stdin, or
 * NULL on failure or end of file.
 */
char *custom_getline(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nread = getline(&buffer, &bufsize, stdin);

	if (nread == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			return (NULL);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	return (buffer);
}
