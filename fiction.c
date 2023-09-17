#include "main.h"
/**
*chrix - function
*@types: valist
*@buffer: array
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: Not always 0
*/
int chrix(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (ravoin(c, buffer, flags, width, precision, size));
}
/**
*gen - a function
*@types: a valist
*@buffer: an array
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int gen(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int a = 0, b;
char *c = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (c == NULL)
{
c = "(null)";
if (precision >= 6)
c = "      ";
}
while (c[a] != '\0')
a++;
if (precision >= 0 && precision < a)
a = precision;
if (width > a)
{
if (flags & F_MINUS)
{
write(1, &c[0], a);
for (b = width - a; b > 0; b--)
write(1, " ", 1);
return (width);
}
else
{
for (b = width - a; b > 0; b--)
write(1, " ", 1);
write(1, &c[0], a);
return (width);
}
}
return (write(1, c, a));
}
/**
*dolf - a function
*@types: valist
*@buffer: array
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int dolf(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/**
*ninsaz - a function
*@types: valist
*@buffer: an array
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int ninsaz(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
int b = 0;
long int d = va_arg(types, long int);
unsigned long int c;
d = winn(d, size);
if (d == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
c = (unsigned long int)d;
if (d < 0)
{
c = (unsigned long int)((-1) * d);
b = 1;
}
while (c > 0)
{
buffer[a--] = (c % 10) + '0';
c /= 10;
}
a++;
return (can(b, a, buffer, flags, width, precision, size));
}
/**
*buter - a function
*@types: valist
*@buffer: an array
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int buter(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
unsigned int a, b, add;
unsigned int d[32];
unsigned int c;
int f;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
a = va_arg(types, unsigned int);
b = 2147483648;
d[0] = a / b;
for (c = 1; c < 32; c++)
{
b /= 2;
d[c] = (a / b) % 2;
}
for (c = 0, add = 0, f = 0; c < 32; c++)
{
add += d[c];
if (add || c == 31)
{
char z = '0' + d[c];
write(1, &z, 1);
f++;
}
}
return (f);
}
