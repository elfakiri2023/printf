#include "main.h"

void buffer_print(char buffer[], int *buff_ind);

/**
 * _printf - custom function
 * @format: the format
 * Return: the printed chars
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
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
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			buffer_print(buffer, &buff_ind);
			flags = the_flags(format, &i);
			width = the_width(format, &i, list);
			precision = the_precision(format, &i, list);
			size = the_size(format, &i);
			++i;
			printed = print_handler(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	buffer_print(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * buffer_print - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void buffer_print(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
