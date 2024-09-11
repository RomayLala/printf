#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string with zero or more directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c, *s;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            switch (format[i])
            {
                case 'c': /* Handle char */
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's': /* Handle string */
                    s = va_arg(args, char *);
                    if (!s)
                        s = "(null)";
                    while (*s)
                    {
                        write(1, s, 1);
                        s++;
                        count++;
                    }
                    break;
                case '%': /* Handle percent */
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    write(1, &format[i], 1);
                    count++;
                    break;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
