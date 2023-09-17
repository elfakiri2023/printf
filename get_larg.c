#include "main.h"

/**
*mud - function.
*@format: character
*@i: int
*@list: valist
*Return: not always 0
*/
int mud(const char *format, int *i, va_list list)
{
int a;
int b = 0;
for (a = *i + 1; format[a] != '\0'; a++)
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
