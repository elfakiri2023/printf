#include "main.h"


/**
 * print_a_string - prints a string
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: number of chars
 */

int print_a_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int length = 0, i;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * convert_number_size - casts a number to the specified size
 * @num:int
 * @size: int
 * Return: casted value
 */
long int convert_number_size(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * check_if_printable - check if a char is printable.
 * @c: char
 * Return: 1 if c is printable and 0 otherwise
 */

int check_if_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_the_hexa_code - function to append ascci
 * @buffer: array
 * @i: index
 * @ascii_code: ascii code
 * Return: 3
 */

int append_the_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * check_if_digit - check if a char is a digit.
 * @c: char
 * Return: 1 if digit and 0 otherwise
 */
int check_if_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

