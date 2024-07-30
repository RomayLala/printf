#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1, On error -1
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_reversed - Prints a reversed string
 * @args: The argument list containing the string
 *
 * Return: Number of characters printed
 */
int print_reversed(va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0, i;

    if (!str)
        str = "(nil)";

    while (str[len])
        len++;

    for (i = len - 1; i >= 0; i--)
        _putchar(str[i]);

    return (len);
}

/**
 * print_integer - Prints an integer
 * @args: The argument list containing the integer
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    int divisor = 1;
    int temp = num;

    if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }

    while (temp / 10)
    {
        divisor *= 10;
        temp /= 10;
    }

    while (divisor)
    {
        _putchar((num / divisor) % 10 + '0');
        count++;
        divisor /= 10;
    }

    return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    int (*func)(va_list);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'r')
                func = print_reversed;
            else if (format[i] == 'd')
                func = print_integer;
            else if (format[i] == 'i')
                func = print_integer;
            else
                func = NULL;

            if (func)
                count += func(args);
            else
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
