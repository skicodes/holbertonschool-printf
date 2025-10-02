#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing format specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
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
				count += print_number(va_arg(ap, int));
			else if (format[i] == 'b')
				count += print_binary(va_arg(ap, unsigned int));
			else if (format[i] == 'u')
				count += print_unsigned(va_arg(ap, unsigned int));
			else if (format[i] == 'o')
				count += print_octal(va_arg(ap, unsigned int));
			else if (format[i] == 'x')
				count += print_hex(va_arg(ap, unsigned int), 0);
			else if (format[i] == 'X')
				count += print_hex(va_arg(ap, unsigned int), 1);
			else
			{
				count += print_char('%');
				count += print_char(format[i]);
			}
		}
		else
		{
			count += print_char(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
