#include "main.h"

/**
 * the_flags - function to calculate the active flags.
 * @format: char string
 * @i: int
 * Return: the flags
 */
 
int the_flags(const char *format, int *i)
{
	int j, i2;
	int the_flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (i2 = *i + 1; format[i2] != '\0'; i2++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[i2] == FLAGS_CH[j])
			{
				the_flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = i2 - 1;

	return (the_flags);
}

