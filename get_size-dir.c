#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @j: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *j)
{
	int l = *j + 1;
	int size = 0;

	if (format[l] == 'l')
		size = SZ_LONG;
	else if (format[l] == 'h')
		size = SZ_SHORT;

	if (size == 0)
		*j = l - 1;
	else
		*j = l;

	return (size);
}

