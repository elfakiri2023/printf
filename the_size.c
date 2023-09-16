#include "main.h"

/**
 * the_size - function to calculate the size
 * @format: char
 * @i: int
 * Return: the precision.
 */

int the_size(const char *format, int *i)
{
	int i2 = *i + 1;
	int size = 0;

	if (format[i2] == 'l')
		size = S_LONG;
	else if (format[i2] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = i2 - 1;
	else
		*i = i2;

	return (size);
}

