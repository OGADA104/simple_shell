#include "main.h"

/**
 * print_number - Prints an integer and increments a count.
 * @n: The integer to print.
 * @count: A pointer to an integer count.
 *
 */
void print_number(int n, int *count)
{
	if (n < 0)
	{
		putchar('-');
		(*count)++;
		n = -n;
	}

	if (n / 10)
		print_number(n / 10, count);

	putchar(n % 10 + '0');
	(*count)++;
}
