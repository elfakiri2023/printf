#include "main.h"

/**
 * print_a_unsigned - Prints an unsigned number.
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: the number of chars.
 */
int print_a_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_the_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_a_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_a_octal - Prints an unsigned number in octal notation
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: the number of chars
 */
int print_a_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_the_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_a_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_a_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: the number of chars
 */
int print_a_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_a_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: va_list
 * @buffer: char
 * @flags: int
 * @width: int
 * @precision: int
 * @size: int
 * Return: the number of chars
 */
int print_a_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: va_list
 * @map_to: array
 * @buffer: char
 * @flags: int
 * @flag_ch: char
 * @width: int
 * @precision: int
 * @size: int
 * @size: int
 * Return: the number of chars.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_the_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_a_unsgnd(0, i, buffer, flags, width, precision, size));
}
