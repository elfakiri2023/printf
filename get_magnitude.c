#include "main.h"

/**
*jul - function.
*@format: character
*@i: int
*Return: not always 0
*/
int jul(const char *format, int *i)
{
int a = *i + 1;
int b = 0;
if (format[a] == 'l')
b = S_LONG;
else if (format[a] == 'h')
b = S_SHORT;
if (b == 0)
*i = a - 1;
else
*i = a;
return (b);
}
