#include <unistd.h>
/**
 * _putchar - function to write a character to the stdout
 * @c: the character to write
 * Return: `1` on success, `-1` otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
