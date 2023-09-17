#include "main.h"

/**
*matab - a function
*@types: valist
*@buffer: character
*@flags: innteger 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int matab(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int b = va_arg(types, unsigned long int);
b = bazim(b, size);
if (b == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (b > 0)
{
buffer[a--] = (b % 10) + '0';
b /= 10;
}
a++;
return (cal(0, a, buffer, flags, width, precision, size));
}

/**
*gran - Prints an unsigned number in octal notation
*@types: Lista of arguments
*@buffer: Buffer array to handle print
*@flags:  Calculates active flags
*@width: get width
*@precision: Precision specification
*@size: Size specifier
*Return: Number of chars printed
*/
int gran(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int b = va_arg(types, unsigned long int);
unsigned long int c = b;
UNUSED(width);
b = bazim(b, size);
if (b == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (b > 0)
{
buffer[a--] = (b % 8) + '0';
b /= 8;
}
if (flags & F_HASH && c != 0)
buffer[a--] = '0';
a++;
return (cal(0, a, buffer, flags, width, precision, size));
}

/**
*josh - a function
*@types: valist
*@buffer: character
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int josh(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
return (ced(types, "0123456789abcdef", buffer,
	flags, 'x', width, precision, size));
}

/**
*sizeri - a function
*@types: valist
*@buffer: character
*@flags: integer 1
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int sizeri(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
return (ced(types, "0123456789ABCDEF", buffer,
	flags, 'X', width, precision, size));
}

/**
*ced - a function
*@types: valist
*@map_to: character 1
*@buffer: character 2
*@flags:  integer 1
*@flag_ch: Character 3
*@width: integer 2
*@precision: integer 3
*@size: integer 4
*Return: not always 0
*/
int ced(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int b = va_arg(types, unsigned long int);
unsigned long int c = b;
UNUSED(width);
b = bazim(b, size);
if (b == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (b > 0)
{
buffer[a--] = map_to[b % 16];
b /= 16;
}
if (flags & F_HASH && c != 0)
{
buffer[a--] = flag_ch;
buffer[a--] = '0';
}
a++;
return (cal(0, a, buffer, flags, width, precision, size));
}
