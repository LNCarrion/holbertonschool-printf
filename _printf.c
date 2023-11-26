#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * print - print x number
 * @n: number to printed
 */
void print(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n == 0)
		putchar('0');

	if (n / 10)
		print(n / 10);

	putchar((n % 10) + '0');
}

/**
 * print_long - print x long number
 * @n: number to be printed
 */
void print_long(long n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n == 0)
		_putchar('0');

	if (n / 10)
		print_long(n / 10);

	_putchar((n % 10) + '0');

}


/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	int count = 0, n;
	long int nl;
	const char *ptr;
	va_list args;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			switch (*(++ptr))
			{
				/* print format: %d (jahzserrano)*/
				case 'd':
					n = va_arg(args, int);

					print(n);
					break;

				/* print format: %i (jahzserrano)*/
				case 'i':
					nl = va_arg(args, long int);

					print_long(nl);
					break;

				default:
					putchar('%');
					putchar(*ptr);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*ptr);
			count++;
		}
	}
	va_end(args);

	return (count);
}
