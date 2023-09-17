#include "main.h"

void buffer_print(char buffer[], int *buff_ind);

/**
 * _printf - our main function
 * @format: char
 * Return:  the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, is_printed = 0, chars_printed = 0;
	int width, flags, sizee, precision, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				buffer_print(buffer, &buff_ind);
			chars_printed++;
		}
		else
		{
			buffer_print(buffer, &buff_ind);
			flags = the_flags(format, &i);
			width = the_width(format, &i, list);
			precision = the_precision(format, &i, list);
			sizee = the_size(format, &i);
			++i;
			is_printed = print_handler(format, &i, list, buffer,
				flags, width, precision, sizee);
			if (is_printed == -1)
				return (-1);
			chars_printed += is_printed;
		}
	}

	buffer_print(buffer, &buff_ind);

	va_end(list);

	return (chars_printed);
}

/**
 * buffer_print - function to print the content of the buffer
 * @buffer: array
 * @buff_ind: the length
 */

void buffer_print(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
