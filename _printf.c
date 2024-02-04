#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
int _putchar(char c);
/**
 * _printf - a simple printf()
 * @format: format string
 *
 * Return: length of strings printed to console or -1 on failure
 */
int _printf(const char *format, ...)
{
	int count = 0; /* count of printed characters */
	va_list args;

	va_start(args, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
			/* handle format specifier */
			if (*(format + 1) == 'c')
			{
				char c = va_arg(args, int);

				_putchar(c);
				format += 2; /* move past '%c' */
				count++;
			}
			else if (*(format + 1) == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
				{
					str = "(null)";
				}
				while (*str)
				{
					_putchar(*str);
					str++;
					count++;
				}
				format += 2; /* move past "%s" */
			}
			else if (*(format + 1) == 'd' || *(format + 1) == 'i')
			{
				/* handle %d or %i */
				int num = va_arg(args, int);
				count += print_digit(num);
				format += 2;
			}
			else if (*(format + 1) == '%')
			{
				_putchar('%');
				format += 2;
				count++;
			}
			else
			{
				/* invalid specifier or no specifier, print '%' */
				_putchar(*format);
				format++;
				count++;
			}
		else
		{
			/* regular character, print as is */
			_putchar(*format);
			format++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
 * Return: on success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
