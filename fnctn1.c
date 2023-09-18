#include "main.hi"

/**
 * prt_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculate width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int prt_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = cnvrt_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (wrt_unsignd(0, i, buffer, flags, width, precision, size));
}

/**
 * prt_octal - Prints an unsigned number in octal
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculate  width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = cnvrt_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FS_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (wrt_unsignd(0, i, buffer, flags, width, precision, size));
}

/**
 * prt_hexadecimal - Prints an unsigned number in hexadecimal
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculate width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (prt_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * prt_hexa_upper - Prints an unsigned number in upper hexadecimal
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: calculate width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (prt_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * prt_hexa - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_hi: Calculates active flags
 * @width: calculates width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int prt_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_hi, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = cnvrt_size_unsignd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & FS_HASH && init_num != 0)
	{
		buffer[i--] = flag_hi;
		buffer[i--] = '0';
	}

	i++;

	return (wrt_unsignd(0, i, buffer, flags, width, precision, size));
}
