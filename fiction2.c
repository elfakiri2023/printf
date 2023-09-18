#include "main.h"

/**
*sek - a function
*@types: valist
*@buffer: character
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: Not always 0
*/
int sek(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
char a = 0, b = ' ';
int c = BUFF_SIZE - 2, d = 2, e = 1;
unsigned long f;
char g[] = "0123456789abcdef";
void *h = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (h == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
f = (unsigned long)h;
while (f > 0)
{
buffer[c--] = g[f % 16];
f /= 16;
d++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
b = '0';
if (flags & F_PLUS)
a = '+', d++;
else if (flags & F_SPACE)
a = ' ', d++;
c++;
return (kaba(buffer, c, d,
width, flags, b, a, e));
}

/**
*audric - a function
*@types: valist
*@buffer: a function
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int audric(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
int a = 0, b = 0;
char *c = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (c == NULL)
return (write(1, "(null)", 6));
while (c[a] != '\0')
{
if (mar(c[a]))
buffer[a + b] = c[a];
else
b += uway(c[a], buffer, a + b);
a++;
}
buffer[a + b] = '\0';
return (write(1, buffer, a + b));
}

/**
*makab - a function
*@types: valist
*@buffer: character
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int makab(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
char *b;
int a = 0;
int c = 0;
char d;
b = 0;
c = b[a];
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
b = va_arg(types, char *);
if (b == NULL)
{
UNUSED(precision);
b = ")Null(";
}
for (a = 0; b[a]; a++)
;
for (a = a - 1; a >= 0; a--)
{
write(1, &d, 1);
c++;
}
return (c);
}

/**
*kiev - a function
*@types: valist
*@buffer: character
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int kiev(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
char a;
char *b;
unsigned int c, d;
int e = 0;
char f[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char g[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
b = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (b == NULL)
b = "(AHYY)";
for (c = 0; b[c]; c++)
{
for (d = 0; f[d]; d++)
{
if (f[d] == b[c])
{
a = g[d];
write(1, &a, 1);
e++;
break;
}
}
if (!f[d])
{
a = b[c];
write(1, &a, 1);
e++;
}
}
return (e);
}
