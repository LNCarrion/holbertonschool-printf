#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * print_number - a function that prints a number digit by digit
 * @number: Number to be printed
 */

int print_number(long int number) {
	
	int i, count = 0;
	
	if (number < 0)
	{
		putchar('-');
		number = -number;
	}
	
	if (number == 0) 
	{
		putchar('0');
	} 
	else 
	{
		char digits[20];
		int count = 0;
		
		while (number > 0)
		{
			digits[count] = '0' + (number % 10);
			number /= 10;
			count++;
		}
		for (i = count - 1; i >= 0; i--) 
		{
			putchar(digits[i]);
		}
	}

	return (count);
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
          
        /*If the format is a d is an integer*/
				case 'd':
					n = va_arg(args, int);
					count = print_number(n);
					break;

        /*if format is i is a long integer*/
				case 'i':
					nl = va_arg(args, long int);
					count = print_number(nl);
					if (count != 0)
						count = count - 1;
					break;

				default:
					putchar('%');
					putchar(*ptr);
					count =+ 2;
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
	count++;

	return (count);
}

