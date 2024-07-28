#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success 1, On error -1, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_number - Prints an integer with precision.
 * @n: The integer to print.
 * @precision: The precision value.
 *
 * Return: The number of characters printed.
 */
int print_number(int n, int precision)
{
    char buffer[100];
    int i = 0, len, j;
    int count = 0;

    if (n == 0 && precision != 0)
        buffer[i++] = '0';

    if (n < 0)
    {
        _putchar('-');
        n = -n;
        count++;
    }

    while (n > 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    len = i;

    if (precision > len)
    {
        for (j = 0; j < precision - len; j++)
            _putchar('0');
        count += precision - len;
    }

    for (i--; i >= 0; i--)
        _putchar(buffer[i]);
    count += len;

    return (count);
}

/**
 * print_unsigned - Prints an unsigned integer with precision.
 * @n: The unsigned integer to print.
 * @base: The base for conversion (e.g., 10 for decimal, 8 for octal).
 * @precision: The precision value.
 * @uppercase: Non-zero if uppercase letters are used for hexadecimal.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int n, int base, int precision, int uppercase)
{
    char buffer[100];
    int i = 0, len, j;
    int count = 0;
    char digits[] = "0123456789abcdef";
    char digits_upper[] = "0123456789ABCDEF";

    if (n == 0 && precision != 0)
        buffer[i++] = '0';

    while (n > 0)
    {
        buffer[i++] = (uppercase ? digits_upper[n % base] : digits[n % base]);
        n /= base;
    }

    len = i;

    if (precision > len)
    {
        for (j = 0; j < precision - len; j++)
            _putchar('0');
        count += precision - len;
    }

    for (i--; i >= 0; i--)
        _putchar(buffer[i]);
    count += len;

    return (count);
}

/**
 * print_string - Prints a string with precision.
 * @str: The string to print.
 * @precision: The precision value.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str, int precision)
{
    int i;
    int count = 0;

    if (str == NULL)
        str = "(null)";

    for (i = 0; str[i] && (precision < 0 || i < precision); i++)
    {
        _putchar(str[i]);
        count++;
    }

    return (count);
}

/**
 * _printf - Custom printf function with precision support.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    unsigned int i = 0, count = 0;
    int precision;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i' ||
                format[i + 1] == 's' || format[i + 1] == 'c' ||
                format[i + 1] == 'u' || format[i + 1] == 'o' ||
                format[i + 1] == 'x' || format[i + 1] == 'X' ||
                format[i + 1] == 'p'))
        {
            precision = -1;
            i += 1;

            if (format[i] == '.')
            {
                precision = 0;
                i++;
                while (format[i] >= '0' && format[i] <= '9')
                {
                    precision = precision * 10 + (format[i] - '0');
                    i++;
                }
            }

            switch (format[i])
            {
            case 'c':
                _putchar(va_arg(args, int));
                count++;
                break;
            case 's':
                count += print_string(va_arg(args, char *), precision);
                break;
            case 'd':
            case 'i':
                count += print_number(va_arg(args, int), precision);
                break;
            case 'u':
                count += print_unsigned(va_arg(args, unsigned int), 10, precision, 0);
                break;
            case 'o':
                count += print_unsigned(va_arg(args, unsigned int), 8, precision, 0);
                break;
            case 'x':
                count += print_unsigned(va_arg(args, unsigned int), 16, precision, 0);
                break;
            case 'X':
                count += print_unsigned(va_arg(args, unsigned int), 16, precision, 1);
                break;
            case 'p':
                count += _printf("0x"); /* Address format prefix */
                count += print_unsigned((unsigned long)va_arg(args, void *), 16, -1, 0);
                break;
            }

            i++;
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
