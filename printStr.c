#include "main.h"

/**
 * printStr - Prints a string and increments a count.
 * @str: The string to print.
 * @count: A pointer to an int
 */
void printStr(const char *str, int *count)
{
	int i;
	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
		(*count)++;
	}
}
