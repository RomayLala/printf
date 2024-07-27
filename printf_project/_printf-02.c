#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 * 
 * Return: On success 1, On error -1.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_binary - Converts an unsigned integer to binary and prints it.
 * @n: The unsigned integer to convert and print.
 */
void print_binary(unsigned int n)
{
    if (n / 2)
        print_binary(n / 2);
    _putchar((n % 2) + '0');
}

/**
 * handle_format - Processes a format specifier and prints the corresponding value.
 * @format: The format specifier.
 * @args: The argument list.
 * 
 * Return: The number of characters printed.
 */
int handle_format(char format, va_list args)
{
    int count = 0;
    
    if (format == 'b')
    {
        print_binary(va_arg(args, unsigned int));
        while (va_arg(args, unsigned int)) /* Count the number of characters printed */
            count++;
    }
    else
    {
        _putchar('%');
        _putchar(format);
        count += 2;
    }
    return (count);
}

/**
 * _printf - A custom printf function to handle %b specifier.
 * @format: The format string.
 * @...: The values to format and print.
 * 
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            count += handle_format(*format, args);
        }
        else
        {
            _putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return (count);
}
