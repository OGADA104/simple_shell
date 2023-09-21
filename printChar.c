#include "main.h"

/**
 * printChar - Prints a character and increments a count.
 * @c: The character to print.
 * @count: A pointer to an integer
 */
void printChar(char c, int *count)
{
	putchar(c);
	(*count)++;
}
