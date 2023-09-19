#include "main.h"

/**
 * get_the_flags - Calculates active flags so it can handle them.
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter as an input
 * Return: Flags:
 */
int get_the_flags(const char *format, int *i)
{
	int curr_i, a;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}
