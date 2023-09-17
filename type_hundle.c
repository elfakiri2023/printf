#include "main.h"

/**
*ravoinn - function.
*@c: character
*@buffer: array
*@flags: int
*@width: int
*@precision: int
*@size: int
*Return: 1 or 0
*/
int ravoinn(char c, char buffer[],
	int flags, int width, int precision, int size)
{
int a = 0;
char b = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
b = '0';
buffer[a++] = c;
buffer[a] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (a = 0; a < width - 1; a++)
buffer[BUFF_SIZE - a - 2] = b;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}

/**
*can - function.
*@is_negative: int
*@ind: int
*@buffer: an array
*@flags: int
*@width: int
*@precision: integer 5
*@size: integer6
*Return: 1 or 0
*/
int can(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - ind - 1;
char b = ' ', c = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
b = '0';
if (is_negative)
c = '-';
else if (flags & F_PLUS)
c = '+';
else if (flags & F_SPACE)
c = ' ';
return (kany(ind, buffer, flags, width, precision,
	a, b, c));
}

/**
*kany - function.
*@ind: 1st integer
*@buffer: array
*@flags: 2nd integer
*@width: 3rd integer
*@prec: 4th integer
*@length: 5th integer
*@padd: 1st character
*@extra_c: 2nd character
*Return: 1 or 0
*/
int kany(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
int a, b = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' ';
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (a = 1; a < width - length + 1; a++)
buffer[a] = padd;
buffer[a] = '\0';
if (flags & F_MINUS && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], a - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], a - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--b] = extra_c;
return (write(1, &buffer[b], a - b) +
write(1, &buffer[ind], length - (1 - b)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}
/**
*cal - function.
*@is_negative: 1st integer
*@ind: 2nd integer
*@buffer: array
*@flags: 3rd integer
*@width: 4th integer
*@precision: 5th integer
*@size: 6th integer
*Return: 1 or 0
*/
int cal(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - ind - 1, b = 0;
char c = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0);
if (precision > 0 && precision < a)
c = ' ';
while (precision > a)
{
buffer[--ind] = '0';
a++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
c = '0';
if (width > a)
{
for (b = 0; b < width - a; b++)
buffer[b] = c;
buffer[b] = '\0';
if (flags & F_MINUS)
{
return (write(1, &buffer[ind], a) + write(1, &buffer[0], b));
}
else
{
return (write(1, &buffer[0], b) + write(1, &buffer[ind], a));
}
}
return (write(1, &buffer[ind], a));
}

/**
*kaba - function
*@buffer: an array
*@ind: 1st integer
*@length: 2nd integer
*@width: 3rd integer
*@flags: 4th integer
*@padd: 1st character
*@extra_c: 2nd character
*@padd_start: 5th integer
*Return: 1 or 0
*/
int kaba(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start)
{
int a;
if (width > length)
{
for (a = 3; a < width - length + 3; a++)
buffer[a] = padd;
buffer[a] = '\0';
if (flags & F_MINUS && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], a - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], a - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

