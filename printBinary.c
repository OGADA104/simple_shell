#include "main.h"

/**
 * printBinary - Prints a binary representation of an unsigned integer.
 * @n: The unsigned integer to print in binary.
 * @count: A pointer to an integer count.
 */
void printBinary(unsigned int n, int *count)
{
	if (n / 2)
		printBinary(n / 2, count);

	putchar((n % 2) + '0');
	(*count)++;
}
