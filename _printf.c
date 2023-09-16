#include "main.h"
#include <stdarg.h>

/**
* _printf - print clone
* @format: constant string literal
* Return: 0 Success
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i, j = 0;
	char c, *str;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{

			i++;
			switch (format[i])
			{
			case 'c':
				c = (char) va_arg(args, int);
				_putchar(c);
				break;
			case 's':
				str = va_arg(args, char *);

				while (str[j] != '\0')
				{
					_putchar(*str);
					str++;
				}
				break;
			}
		}

		else
		{
			char c = format[i];

			_putchar(c);
		}
		}
	va_end(args);
	_putchar('\n');
	return (0);

}
