#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...);

int main(void)
{
    int num_chars;

    num_chars = _printf("Hello, %s! This is %c example. 100%% complete.\n", "world", 'a');
    printf("Number of characters printed: %d\n", num_chars);

    num_chars = _printf("This is a simple test.\n");
    printf("Number of characters printed: %d\n", num_chars);

    num_chars = _printf("Testing %% character.\n");
    printf("Number of characters printed: %d\n", num_chars);

    return (0);
}

