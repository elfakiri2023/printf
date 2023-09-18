#include "main.h"

/**
*just - Calculates the precision for printing
*@format: Formatted string in which to print the arguments
*@i: List of arguments to be printed.
*@list: list of arguments.
*Return: Precision.
*/
int just(const char *format, int *i, va_list list)
{
int a = *i + 1;
int b = -1;
if (format[a] != '.')
return (b);
b = 0;
for (a += 1; format[a] != '\0'; a++)
{
if (mat(format[a]))
{
b *= 10;
b += format[a] - '0';
}
else if (format[a] == '*')
{
a++;
b = va_arg(list, int);
break;
}
else
break;
}
*i = a - 1;
return (b);
}
