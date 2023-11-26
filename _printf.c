#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * print_number - a function that prints a number digit by digit
 * @number: Number to be printed
 */i

void print_number(long int number) {
    // Check if the number is negative
    if (number < 0) {
        putchar('-');
        number = -number; // Make the number positive
    }

    // Handle the case of 0 separately
    if (number == 0) {
        putchar('0');
    } else {
        // Temporary array to store individual digits
        char digits[20]; // Assuming a maximum of 20 digits for the number
        int count = 0;

        // Extract digits by repeatedly dividing by 10
        while (number > 0) {
            digits[count] = '0' + (number % 10); // Store the digit as a character
            number /= 10;
            count++;
        }

        // Print the digits in reverse order
        for (int i = count - 1; i >= 0; i--) {
            putchar(digits[i]);
        }
    }
}
                                                                                      ~                                                                                         ~                                                                                         ~         
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

					print_number(n);
					break;

        /*if format is i is a long integer*/
				case 'i':
					nl = va_arg(args, long int);

					print_number(nl);
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

