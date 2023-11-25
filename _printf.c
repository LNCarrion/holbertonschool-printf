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
		putchar('-');

	if (n / 10)
		print(n / 10);

	putchar((n % 10) + '0');
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	int count = 0;
	const char *ptr;
	va_list args;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			switch (*(++ptr))
			{

				case 'd':
					int num = va_arg(args, int);

					_putchar(num);
					break;

				case 'i':
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
