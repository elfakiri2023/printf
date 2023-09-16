#include "main.h"

/**
 * _printf - our main function
 * @format: char
 * Return:  the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, is_printed = 0, chars_printed = 0;
	int width, flags, the_size, precision, index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == BUFF_SIZE)
				buffer_print(buffer, &index);
			chars_printed++;
		}
		else
		{
			buffer_print(buffer, &index);
			flags = the_flags(format, &i);
			width = the_width(format, &i, list);
			precision = the_precision(format, &i, list);
			the_size = the_size(format, &i);
			++i;
			is_printed = print_handler(format, &i, list, buffer,
				flags, width, precision, the_size);
			if (is_printed == -1)
				return (-1);
			chars_printed += is_printed;
		}
	}

	buffer_print(buffer, &index);

	va_end(list);

	return (chars_printed);
}

