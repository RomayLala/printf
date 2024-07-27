#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1, On error -1, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_string - Prints a string with non-printable characters in hexadecimal
 * @str: The string to be printed
 */
void print_string(char *str)
{
    char hex_digits[] = "0123456789ABCDEF";

    while (*str)
    {
        if (*str < 32 || *str >= 127)
        {
            _putchar('\\');
            _putchar('x');
            _putchar(hex_digits[(*str >> 4) & 0x0F]);
            _putchar(hex_digits[*str & 0x0F]);
        }
        else
        {
            _putchar(*str);
        }
        str++;
    }
}

/**
 * _printf - Custom printf function with support for %S
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    const char *ptr;
    int count = 0;

    va_start(args, format);

    for (ptr = format; *ptr; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) == 'S')
        {
            char *str = va_arg(args, char *);
            print_string(str);
            ptr++;
            count += 2; /* Account for the '%S' in the format */
        }
        else
        {
            _putchar(*ptr);
            count++;
        }
    }

    va_end(args);
    return (count);
}
