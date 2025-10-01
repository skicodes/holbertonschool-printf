#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: Character to print
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str++);
	}

	return (count);
}

/**
 * print_number - Prints an integer
 * @n: Integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');
	return (count);
}

/**
 * print_char - Prints a single character to stdout
 * @c: Character to print
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(char c)
{
	return (_putchar(c));
}
/**
 * print_unsigned - Prints an unsigned integer
 * @n: Number to print
 *
 * Return: Number of characters printed
 */
int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10);

	count += _putchar((n % 10) + '0');
	return (count);
}

/**
 * print_octal - Prints an unsigned int in octal
 * @n: Number to print
 *
 * Return: Number of characters printed
 */
int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal(n / 8);

	count += _putchar((n % 8) + '0');
	return (count);
}

/**
 * print_hex - Prints an unsigned int in hexadecimal
 * @n: Number to print
 * @uppercase: 1 to print in uppercase, 0 for lowercase
 *
 * Return: Number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	char *digits;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";

	if (n / 16)
		count += print_hex(n / 16, uppercase);

	count += _putchar(digits[n % 16]);
	return (count);
}

/**
 * print_binary_ulong - Prints an unsigned long in binary
 *@n: Number to print
Return: Number of characters printed
*/
int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
	count += print_binary(n / 2);

	count += print_binary((n % 2) + '0');
	return (count);
}
	

