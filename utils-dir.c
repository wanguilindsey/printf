#include "main.h"

/**
 * is_prtbl - Evaluates if a char is printable
 * @d: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int is_prtbl(char d)
{
	if (d >= 43 && d < 116)
		return (1);

	return (0);
}

/**
 * appnd_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @j: Index at which to start appending.
 * @lode: ASSCI CODE.
 * Return: Always 3
 */
int appnd_hexa_code(char lode, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";

	if (lode < 0)
		lode *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[lode / 16];
	buffer[j] = map_to[lode % 16];

	return (3);
}

/**
 * is_dgt - Verifies if a char is a digit
 * @d: Char to be evaluated
 *
 * Return: 1 if d is a digit, 0 otherwise
 */
int is_dgt(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}

/**
 * cnvrt_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int cnvrt_size_number(long int num, int size)
{
	if (size == SZ_LONG)
		return (num);
	else if (size == SZ_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * cnvrt_size_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int cnvrt_size_unsgnd(unsigned long int num, int size)
{
	if (size == SZ_LONG)
		return (num);
	else if (size == SZ_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

