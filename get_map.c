#include "main.h"

/**
*fakiri - function.
*@format: character
*@i: integer
*Return: 1 or 0
*/
int fakiri(const char *format, int *i)
{
int a, b;
int c = 0;
const char d[] = {'-', '+', '0', '#', ' ', '\0'};
const int e[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (b = *i + 1; format[b] != '\0'; b++)
{
for (a = 0; d[a] != '\0'; a++)
if (format[b] == d[a])
{
c |= e[a];
break;
}
if (d[a] == 0)
break;
}
*i = b - 1;
return (c);
}
