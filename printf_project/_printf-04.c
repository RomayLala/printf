#include "main.h"

/**
 * print_char - Prints a single character
 * @args: The arguments list
 *
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
    return (_putchar(va_arg(args, int)));
}

/**
 * print_string - Prints a string
 * @args: The arguments list
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
    char *str;
    int count;

    str = va_arg(args, char *);
    if (str == NULL)
        str = "(nil)";
    count = _puts(str);
    return (count);
}

/**
 * print_number - Prints an integer as a decimal
 * @args: The arguments list
 *
 * Return: The number of characters printed
 */
int print_number(va_list args)
{
    int num;
    char buffer[12];
    int len;
    int sign;
    int i;
    char temp;

    num = va_arg(args, int);
    sign = 0;
    len = 0;

    if (num < 0)
    {
        sign = 1;
        num = -num;
    }

    do {
        buffer[len++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (sign)
        buffer[len++] = '-';

    i = 0;
    while (i < len / 2)
    {
        temp = buffer[i];
        buffer[i] = buffer[len - 1 - i];
        buffer[len - 1 - i] = temp;
        i++;
    }

    buffer[len] = '\0';
    return (_puts(buffer));
}

/**
 * print_unsigned - Prints an unsigned integer as a decimal
 * @args: The arguments list
 *
 * Return: The number of characters printed
 */
int print_unsigned(va_list args)
{
    unsigned int num;
    char buffer[11];
    int len;
    int i;
    char temp;

    num = va_arg(args, unsigned int);
    len = 0;

    if (num == 0)
        buffer[len++] = '0';

    while (num > 0)
    {
        buffer[len++] = (num % 10) + '0';
        num /= 10;
    }

    i = 0;
    while (i < len / 2)
    {
        temp = buffer[i];
        buffer[i] = buffer[len - 1 - i];
        buffer[len - 1 - i] = temp;
        i++;
    }

    buffer[len] = '\0';
    return (_puts(buffer));
}

/**
 * print_octal - Prints an unsigned integer in octal format
 * @args: The arguments list
 *
 * Return: The number of characters printed
 */
int print_octal(va_list args)
{
    unsigned int num;
    char buffer[12]; /* Enough for 32-bit octal + null terminator */
    int len;
    int i;
    char temp;

    num = va_arg(args, unsigned int);
    len = 0;

    if (num == 0)
        buffer[len++] = '0';

    while (num > 0)
    {
        buffer[len++] = (num % 8) + '0';
        num /= 8;
    }

    i = 0;
    while (i < len / 2)
    {
        temp = buffer[i];
        buffer[i] = buffer[len - 1 - i];
        buffer[len - 1 - i] = temp;
        i++;
    }

    buffer[len] = '\0';
    return (_puts(buffer));
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format
 * @args: The arguments list
 * @uppercase: Flag to determine if uppercase letters should be used
 *
 * Return: The number of characters printed
 */
int print_hex(va_list args, int uppercase)
{
    unsigned int num;
    char buffer[9]; /* Enough for 32-bit hex + null terminator */
    int len;
    int i;
    char temp;
    char *digits;

    num = va_arg(args, unsigned int);
    len = 0;

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (num == 0)
        buffer[len++] = '0';
    else
    {
        while (num > 0)
        {
            buffer[len++] = digits[num % 16];
            num /= 16;
        }
    }

    i = 0;
    while (i < len / 2)
    {
        temp = buffer[i];
        buffer[i] = buffer[len - 1 - i];
        buffer[len - 1 - i] = temp;
        i++;
    }

    buffer[len] = '\0';
    return (_puts(buffer));
}

/**
 * handle_specifier - Handles the conversion specifiers
 * @format: The format string
 * @args: The arguments list
 * @i: The current index in the format string
 *
 * Return: The number of characters printed
 */
int handle_specifier(const char *format, va_list args, int *i)
{
    int count;

    count = 0;

    if (format[*i] == 'c')
        count += print_char(args);
    else if (format[*i] == 's')
        count += print_string(args);
    else if (format[*i] == 'd' || format[*i] == 'i')
        count += print_number(args);
    else if (format[*i] == 'u')
        count += print_unsigned(args);
    else if (format[*i] == 'o')
        count += print_octal(args);
    else if (format[*i] == 'x')
        count += print_hex(args, 0);
    else if (format[*i] == 'X')
        count += print_hex(args, 1);
    else if (format[*i] == 'p')
    {
        count += _putchar('0');
        count += _putchar('x');
        count += print_hex(args, 0);
    }
    else if (format[*i] == '%')
        count += _putchar('%');
    else
        count += _putchar(format[*i]);

    return (count);
}

/**
 * _printf - A custom implementation of the printf function
 * @format: The format string containing the characters and the specifiers
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i;
    int count;

    va_start(args, format);
    i = 0;
    count = 0;
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += handle_specifier(format, args, &i);
        }
        else
            count += _putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}
