/* main.h */
#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);

#endif /* MAIN_H */

/* _printf-11.c */
#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 * 
 * Return: On success 1, on error -1, and errno is set appropriately.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_number - Prints an integer with optional zero-padding.
 * @n: The number to print.
 * @width: The minimum width for the output.
 * @pad_zero: Whether to pad with zeros.
 * 
 * Return: The number of characters printed.
 */
int print_number(int n, int width, int pad_zero)
{
    char buffer[50];
    int i = 0, num_len = 0, temp = n;
    int len, leading_zeros;

    /* Handle special case for zero */
    if (n == 0)
    {
        buffer[i++] = '0';
        num_len = 1;
    }
    else
    {
        /* Convert number to string */
        while (temp != 0)
        {
            buffer[i++] = '0' + (temp % 10);
            temp /= 10;
        }
        num_len = i;
    }

    len = num_len;
    leading_zeros = 0;

    /* Print leading zeros if needed */
    if (pad_zero && width > len)
    {
        leading_zeros = width - len;
        len = width;  /* Update length to account for padding */
    }

    /* Print leading zeros */
    while (leading_zeros--)
        _putchar('0');

    /* Print the number in reverse order */
    while (num_len--)
        _putchar(buffer[num_len]);

    return len;  /* Return the number of characters printed */
}

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @...: The variables to format and print.
 * 
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    unsigned int i = 0, count = 0;
    int width = 0;
    int pad_zero = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1] == '0')
        {
            pad_zero = 1;
            i += 2;

            /* Extract width (if provided) */
            if (format[i] >= '1' && format[i] <= '9')
                width = format[i] - '0';
        }
        else if (format[i] == '%' && (format[i + 1] == 'd' ||
                                      format[i + 1] == 'i'))
        {
            int num = va_arg(args, int);
            count += print_number(num, width, pad_zero);
            i += 2;
        }
        else
        {
            _putchar(format[i]);
            count++;
            i++;
        }
    }

    va_end(args);
    return count;
}
