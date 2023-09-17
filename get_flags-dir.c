#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string to print the arguments
 * @j: take a parameter
 * Return: Flags
 */
int get_flags(const char *format, int *j)
{
	int k, m;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FS_MINUS, FS_PLUS, FS_ZERO, FS_HASH, FS_SPACE, 0};

	for (m = *j + 1; format[m] != '\0'; m++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
			if (format[m] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*j = m - 1;

	return (flags);
}

