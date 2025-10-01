#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing format specifiers
 * Return: Number of characters printed
 */
int print_binary(unsigned int n)
{
    int count = 0;
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
    int started = 0;

    if (n == 0)
        return print_char('0');

    while (mask)
    {
        if (n & mask)
        {
            count += print_char('1');
            started = 1;
        }
        else if (started)
        {
            count += print_char('0');
        }
        mask >>= 1;
    }
    return count;
}
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(ap);
				return (-1);
			}
			if (format[i] == 'c')
				count += print_char((char)va_arg(ap, int));
			else if (format[i] == 's')
				count += print_string(va_arg(ap, char *));
			else if (format[i] == '%')
				count += print_char('%');
			else if (format[i] == 'd' || format[i] == 'i')
			{
                                count += print_number(va_arg(ap, int));
			}
			else if (format[i] == 'b')
			{
				unsigned int val = va_arg(ap, unsigned int);
				count += print_binary(val);
			}
			else
			{
				count += print_char('%');
				count += print_char(format[i]);
			}
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
