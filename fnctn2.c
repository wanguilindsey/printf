#include "main.h"

/**
 * prt_pointer - Prints value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculates width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int prt_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char xtra_d = 0, pad = ' ';
	int indx = BUFF_SIZE - 2, length = 2, pad_start = 1;
	unsigned long num_addr;
	char map_to[] = "0123456789abcdef";
	void *addr = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addr = (unsigned long)addr;

	while (num_addr > 0)
	{
		buffer[indx--] = map_to[num_addr % 16];
		num_addr /= 16;
		length++;
	}

	if ((flags & FS_ZERO) && !(flags & FS_MINUS))
		pad = '0';
	if (flags & FS_PLUS)
		xtra_d = '+', length++;
	else if (flags & FS_SPACE)
		xtra_d = ' ', length++;
	indx++;

	return (wrt_pointer(buffer, ind, length,
		width, flags, pad, xtra_d, pad_start));
}

/**
 * prt_non_printable - Prints ASCII codes in hexa of non printable chars
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculates width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_prtbl(str[j]))
			buffer[j + offset] = str[j];
		else
			offset += appnd_hex_code(str[j], buffer, j + offset);

		j++;
	}

	buffer[j + offset] = '\0';

	return (write(1, buffer, j + offset));
}

/**
 * prt_reverse - Prints reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculates width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int prt_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int j, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (j = 0; str[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char s = str[j];

		write(1, &s, 1);
		count++;
	}
	return (count);
}

/**
 * prt_rot13string - Print a string in rot13.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculates width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int prt_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int k, l;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHHHH)";
	for (k = 0; str[k]; k++)
	{
		for (l = 0; in[l]; l++)
{
			if (in[l] == str[k])
			{
				y = out[l];
				write(1, &y, 1);
				count++;
				break;
			}
		}
		if (!in[l])
		{
			y = str[k];
			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
