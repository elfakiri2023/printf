#include "main.h"

/**
 * the_precision - function to calculates the precision.
 * @format: char
 * @i: i
 * @list: list va_list arguments.
 * Return: the precision.
 */

int the_precision(const char *format, int *i, va_list list)
{
	int i2 = *i + 1;
	int the_precision = -1;

	if (format[i2] != '.')
		return (the_precision);

	the_precision = 0;

	for (i2 += 1; format[i2] != '\0'; i2++)
	{
		if (check_if_digit(format[i2]))
		{
			the_precision *= 10;
			the_precision += format[i2] - '0';
		}
		else if (format[i2] == '*')
		{
			i2++;
			the_precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = i2 - 1;

	return (the_precision);
}

