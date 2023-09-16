#include "main.h"

/**
 * print_a_percent - prints a percent
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: number of chars
 */

int print_a_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_a_hexa - prints a hexadecimal number.
 * @types: char
 * @map_to: char
 * @buffer: int
 * @flags: int
 * @flag_ch: int
 * @width: int
 * @precision: int
 * @size: int
 * @size: int
 * Return: number of chars
 */

int print_a_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
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
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && num_init != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_a_int - print int
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: number of chars
 */

int print_a_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned long int num;
	int i = BUFF_SIZE - 2;
	int negative = 0;
	long int n = va_arg(types, long int);

	n = convert_number_size(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_a_number(negative, i, buffer, flags, width, precision, size));
}


/**
 * convert_unsgnd_size - casts a number.
 * @num: long int
 * @size: int
 * Return: casted value
 */

long int convert_unsgnd_size(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * print_a_char - function to print a char
 * @types: va_list
 * @buffer: char
 * @flags:  int
 * @width: int
 * @precision: int
 * @size: int
 * Return: number of chars
 */

int print_a_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_char_write(c, buffer, flags, width, precision, size));
}

