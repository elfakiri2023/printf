#include "main.h"

/**
*mar - a function
*@c: acharacter
*Return: not always 0
*/
int mar(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}
/**
*uway - a function
*@buffer: an array
*@i: integer
*@ascii_code: character
*Return: Always 3
*/
int uway(char ascii_code, char buffer[], int i)
{
char a[] = "0123456789ABCDEF";
if (ascii_code < 0)
ascii_code *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = a[ascii_code / 16];
buffer[i] = a[ascii_code % 16];
return (3);
}

/**
*mat - a function
*@c: character
*Return: not always 0
*/
int mat(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}
/**
*winn - a function
*@num: 1st integer
*@size: 2nd integer
*Return: not always 0
*/
long int winn(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}

/**
*bazim - a function
*@num: 1st integer
*@size: 2nd integer
*Return: not always 0
*/
long int bazim(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
