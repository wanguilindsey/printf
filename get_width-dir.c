#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @j: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *j, va_list list)
{
	int l;
	int width = 0;

	for (l = *j + 1; format[l] != '\0'; l++)
	{
		if (is_dgt(format[l]))
		{
			width *= 10;
			width += format[l] - '0';
		}
		else if (format[l] == '*')
		{
			l++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = l - 1;

	return (width);
}

