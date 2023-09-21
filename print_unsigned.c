#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer and increments a count.
 * @n: The unsigned integer to print.
 * @count: A pointer to an integer count.
 */

void print_unsigned(unsigned int n, int *count)
{
	if (n / 10)
		print_unsigned(n / 10, count);

	putchar(n % 10 + '0');
	(*count)++;
}
