#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing format specifiers
 * Return: Number of characters printes
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
