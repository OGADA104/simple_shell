#include "main.h"
#include <stdio.h>
#include <stddef.h>
/**
 * custom_getline - Read a line of text from standard input
 *
 * Return: A pointer to the line read from stdin, or
 * NULL on failure or end of file.
 */
char *custom_getline(void)
{
	size_t bufsize = 0;
	char *line = NULL;

	getline(&line, &bufsize, stdin);
	return (line);
}
