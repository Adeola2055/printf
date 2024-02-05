#include "main.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/**
 * int_min_checker - check if num is INT_MIN
 * @num: points to num
 * @count: points to count
 *
 * Return: number of count
 */
void int_min_checker (int *num, int *count, int *last)
{
	if (*num == INT_MIN)
	{
		*last = abs(*num % 10);
		*num = (*num / 10) * -1;
		_putchar('-');
/*		*num = *num + 1; */
/*		*num = -(*num);*/
		(*count)++;
	}
}
/**
 * print_digit - print a digit
 * @num: digit to print
 *
 * Return: number of digit printed to stdout
 */
int print_digit(int num)
{
	char *ptr;
	int last;
	int count = 0, temp = num, i = 0, j, len = 0;

	int_min_checker(&num, &count, &last);
	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (temp > 0)
		{
			temp /= 10;
			len++;
		}
		ptr = (char *) malloc(sizeof(char) * len);
		if (ptr == NULL)
			return (-1);
		while (num > 0)
		{
			ptr[i] = num % 10 + '0';
			num /= 10;
			i++;
		}
		j = i - 1;
		while (j >= 0)
		{
			_putchar(ptr[j]);
			j--;
			count++;
		}
	}
	if (last != 0)
	{
		_putchar(last + '0');
		count++;
	}
	free(ptr);
	return (count);
}
