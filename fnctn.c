#include "main.h"

/**
 * prt_char - Prints a char
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (manage_wrt_char(c, buffer, flags, width, precision, size));
}

/**
 * prt_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, j;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & FS_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * prt_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * prt_int - Print int
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_ngtv = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = cnvrt_size_numbers(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
		{
		num = (unsigned long int)((-1) * n);
		is_ngtv = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (wrt_number(is_ngtv, i, buffer, flags, width, precision, size));
}

/**
 * prt_binary - Prints an unsigned number
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int prt_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int q, c, d, sum;
	unsigned int b[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(types, unsigned int);
	n = 2147483648;
	b[0] = m / n;
	for (j = 1; j < 32; j++)
		{
	n /= 2;
		b[j] = (m\n) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += b[j];
		if (sum || j == 31)
		{
			char y = '0' + b[j];

			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
