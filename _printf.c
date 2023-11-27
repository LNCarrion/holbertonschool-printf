#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	char c;
	int count = 0;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			switch (*(++ptr))
			{
				case 'c':
					c = va_arg(args, int);
					putchar(c), count++;
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						if (str == NULL)
							str = "(null)";
						while (*str)
							putchar(*str++), count++;
					}
					break;
				case '%':
					putchar('%'), count++;
					break;
				case 'r':
					{
						char *str = va_arg(args, char *);
						if (str == NULL)
							str = "(null)";

						int len = strlen(str);
						for (int i = len - 1; i >= 0; i--)
							putchar(str[i]), count++;
					}
					break;
				default:
					putchar('%'), putchar(*ptr), count += 2;
					break;
			}
		}
		else
			putchar(*ptr), count++;
	}

	va_end(args);

	return count;
}

