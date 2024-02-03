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
			else if (*(format + 1) == '%')
			{
				_putchar('%');
				format += 2;
				count++;
			}
		/**	else if (*(format + 1) == 'd' || *(format + 1) == 'i') 
			{
				* Handle %d or %i *
				int num = va_arg(args, int);
				* Assuming a simple implementation for integer printing *
				char buffer[12];  * Sufficient for 32-bit integers *
				int len = snprintf(buffer, sizeof(buffer), "%d", num);
				int i;
				for (i = 0; i < len; i++)
				{
					_putchar(buffer[i]);
					count++;
				}
				format += 2; */
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
