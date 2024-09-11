#include "main.h"

/**
 * _printf - Custom implementation of printf to handle %d and %i.
 * @format: The format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'd' || format[i] == 'i')
            {
                count += print_number(va_arg(args, int));
            }
            else if (format[i] == '%')
            {
                _putchar('%');
                count++;
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
