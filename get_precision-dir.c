#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @j: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *j, va_list list)
{
	int l = *j + 1;
	int precision = -1;

	if (format[l] != '.')
		return (precision);

	precision = 0;

	for (l += 1; format[l] != '\0'; l++)
	{
		if (is_dgt(format[l]))
		{
			precision *= 10;
			precision += format[l] - '0';
		}
		else if (format[l] == '*')
		{
			l++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = l - 1;

	return (precision);
}

