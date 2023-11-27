#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
<<<<<<< HEAD
 * _printf - Custom printf function.
=======
 * print_number - a function that prints a number digit by digit
 * @number: Number to be printed
 */
int print_long(long int number) {

        int i, count = 0;

        if (number < 0)
        {
                number = -number;
		count = count + 1;
        }
        if (number == 0)
        {
                putchar('0');
        }
        else
        {
                char digits[20];

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


int print_number(int number) {
	
	int i, count = 0;
	
	if (number < 0)
	{
		putchar('-');
		number = -number;
		count = 1;
	}
	if (number == 0)
	{
		putchar('0');
	} 
	else 
	{
		char digits[20];
		
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
>>>>>>> c207f1701960ccecc14c9871c34fabe8eb405afc
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
					if (n > 0)
                                        {
                                                count = count + (print_long(n) - 1);
                                        }
                                        else
                                        {
                                                count = count + (print_long(n));
                                        }
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
	count++;

	return (count);
}

