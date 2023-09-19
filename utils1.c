#include "main.h"

/**
 * check_is_printable - Evaluates if a char is printable.
 * @c: Char to be evaluated
 * Return: 1 if c is printable
 */
int check_is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_a_hexa_code - Append ascci.
 * @buffer: Array
 * @i: int
 * @ascii_code: char
 * Return: Always 3.
 */
int append_a_hexa_code(char ascii_code, char buffer[], int i)
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
 * check_is_digit - check if a char is num.
 * @c: chat
 * Return: 1 if digit.
 */
int check_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_the_size_number - Casts a number.
 * @num: int
 * @size: int
 * Return: Casted value
 */
long int convert_the_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_the_size_unsgnd - Casts a number.
 * @num: int
 * @size: int
 * Return: int
 */
long int convert_the_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
