#include "main.h"

/**
 * buffer_print - function to print the content of the buffer
 * @buffer: array
 * @buff_ind: the length
 */
 
void buffer_print(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
