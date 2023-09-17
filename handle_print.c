#include "main.h"

/**
 * print_handler - function to print an argument
 * @fmt: char string
 * @list: List of arguments.
 * @ind: int.
 * @buffer: array buffer
 * @flags: int flags
 * @width: the width.
 * @precision: precision
 * @size: int dize
 * Return: 1 and sometimes 2
 */

int print_handler(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, len = 0, chars_printed = -1;
	fmt_t the_types[] = {
		{'c', print_a_char}, {'s', print_a_string}, {'%', print_a_percent},
		{'i', print_a_int}, {'d', print_a_int}, {'b', print_a_binary},
		{'u', print_a_unsigned}, {'o', print_a_octal}, {'x', print_a_hexadecimal},
		{'X', print_a_hexa_upper},
		{'p', print_a_pointer}, {'S', print_non_printable},
		{'r', reverse_print}, {'R', print_a_rot13string}, {'\0', NULL}
	};
	for (i = 0; the_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == the_types[i].fmt)
			return (the_types[i].fn(list, buffer, flags, width, precision, size));

	if (the_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (chars_printed);
}

