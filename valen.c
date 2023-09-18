#include "main.h"

void mucy(char buffer[], int *buff_ind);
/**
*_printf - a function
*@format: a pointer
*Return: not always 0
*/
int _printf(const char *format, ...)
{
int a, b = 0, c = 0;
int d, e, f, g, h = 0;
va_list k;
char l[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(k, format);
for (a = 0; format && format[a] != '\0'; a++)
{
if (format[a] != '%')
{
l[h++] = format[a];
if (h == BUFF_SIZE)
mucy(l, &h);
c++;
}
else
{
mucy(l, &h);
d = shim(format, &a);
e = mud(format, &a, k);
f = just(format, &a, k);
g = jul(format, &a);
a++;
b = mic(format, &a, k, l,
d, e, f, g);
if (b == -1)
return (-1);
c += b;
}
}
mucy(l, &h);
va_end(k);
return (c);
}

/**
*mucy - a function
*@buffer: an array
*@buff_ind: a pointer
*/
void mucy(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
