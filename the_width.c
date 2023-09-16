#include "main.h"

/**
 * the_width - function to calculates the width.
 * @format: char
 * @i: int
 * @list: va_list
 * Return: the width
 */

int the_width(const char *format, int *i, va_list list)
{
	int width = 0;
	int i2;

	for (i2 = *i + 1; format[i2] != '\0'; i2++)
	{
		if (check_if_digit(format[i2]))
		{
			width *= 10;
			width += format[i2] - '0';
		}
		else if (format[i2] == '*')
		{
			i2++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = i2 - 1;

	return (width);
}

