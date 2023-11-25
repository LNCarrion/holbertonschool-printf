#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/**
 * print - this functions prints any number
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

	if (n/10)
		print(n/10);

	putchar(n%10 + '0');
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
	char c;
	va_list args;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			switch (*(++ptr))
			{
				case 'c':
					c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						if (str == NULL)
							str = "(null)";
						while (*str)
						{
							putchar(*str++);
							count++;
						}
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;

				case 'd':
					int num = va_arg(args, int);
					print(num);
					break;

				default:
					putchar('%');
					putchar(*ptr);
					count +=2;
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

