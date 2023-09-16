#include "main.h"

/**
 * print_a_octal - prints an unsigned number.
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: number of chars.
 */

int print_a_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int num_init = num;

	UNUSED(width);

	num = convert_unsgnd_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && num_init != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_a_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_a_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_a_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_a_hexa_upper - prints an unsigned number.
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: number of chars.
 */

int print_a_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_a_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * print_a_binary - function to print an unsigned number
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: numbers of char.
 */

int print_a_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int count;
	unsigned int n, m, i, total;
	unsigned int a[32];

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, total = 0, count = 0; i < 32; i++)
	{
		total += a[i];
		if (total || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/**
 * print_a_unsigned - prints an unsigned number
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: number of chars.
 */

int print_a_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_unsgnd_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
