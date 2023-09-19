#include "main.h"

/**
 * get_the_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_the_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	curr_i++;

	if (format[curr_i] == '*')
	{
		curr_i++;
		precision = va_arg(list, int);
	}
	else
	{
		while (is_digit(format[curr_i]))
		{
			precision = precision * 10 + (format[curr_i] - '0');
			curr_i++;
		}
	}

	*i = curr_i;

	return (precision);
}
