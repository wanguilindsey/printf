#include "main.h"


/**
 * manage_write_char - Prints a string
 * @d: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int manage_write_char(char d, char buffer[],
	int flags, int width, int precision, int size)
{ 
	int j = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FS_ZERO)
		pad = '0';

	buffer[j++] = d;
	buffer[j] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[BUFF_SIZE - j - 2] = pad;

		if (flags & FS_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - j - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
}
	return (write(1, &buffer[0], 1));
/**
 * wrt_num - Prints a string
 * @is_ngtv: Lista of arguments
 * @indx: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int wrt_num(int is_ngtv, int indx, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - indx - 1;
	char pad = ' ', xtra_ch = 0;

	UNUSED(size);

	if ((flags & FS_ZERO) && !(flags & FS_MINUS))
		pad = '0';
	if (is_ngtv)
		xtra_ch = '-';
	else if (flags & FS_PLUS)
		xtra_ch = '+';
	else if (flags & FS_SPACE)
		xtra_ch = ' ';

	return (wrt_num(indx, buffer, flags, width, precision,
		length, pad, xtra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @indx: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @pad: Pading char
 * @xtra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int indx, char buffer[],
	int flags, int width, int prec,
	int length, char pad, char xtra_c)
{
	int j, pad_start = 1;

	if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0' && width == 0)
		return (0); 
	if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		buffer[indx] = pad = ' '; 
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
		buffer[--indx] = '0', length++;
	if (xtra_c != 0)
		length++;
	if (width > length)
	{
		for (j = 1; j < width - length + 1; j++)
			buffer[j] = pad;
		buffer[j] = '\0';
		if (flags & FS_MINUS && pad == ' ')
		{
			if (xtra_c)
				buffer[--indx] = xtra_c;
			return (wrt(1, &buffer[indx], length) + wrt(1, &buffer[1], j - 1));
		}
		else if (!(flags & FS_MINUS) && pad == ' ')
		{
			if (xtra_c)
				buffer[--indx] = xtra_c;
			return (wrt(1, &buffer[1], j - 1) + wrt(1, &buffer[indx], length));
		}
		else if (!(flags & FS_MINUS) && pad == '0')
		{
			if (xtra_c)
				buffer[--pad_start] = xtra_c;
			return (wrt(1, &buffer[pad_start], j - pad_start) +
				wrt(1, &buffer[indx], length - (1 - pad_start)));
		}
	}
	if (xtra_c)
		buffer[--indx] = xtra_c;
	return (wrt(1, &buffer[indx], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_ngtv: Number indicating if the num is negative
 * @indx: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_ngtv, int indx,
	char buffer[],
	int flags, int width, int precision, int size)
{
	
	int length = BUFF_SIZE - indx - 1, j = 0;
	char pad = ' ';

	UNUSED(is_ngtv);
	UNUSED(size);

	if (precision == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		return (0); 

	if (precision > 0 && precision < length)
		pad = ' ';

	while (precision > length)
	{
		buffer[--indx] = '0';
		length++;
	}

	if ((flags & FS_ZERO) && !(flags & FS_MINUS))
		pad = '0';

	if (width > length)
	{
		for (j = 0; j < width - length; j++)
			buffer[j] = pad;

		buffer[j] = '\0';

		if (flags & FS_MINUS)
		{
			return (wrt(1, &buffer[indx], length) + wrt(1, &buffer[0], j));
		}
		else 
		{
			return (wrt(1, &buffer[0], j) + wrt(1, &buffer[indx], length));
		}
	}

	return (wrt(1, &buffer[indx], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @indx: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @pad: Char representing the padding
 * @xtra_c: Char representing extra char
 * @pad_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int indx, int length,
	int width, int flags, char pad, char xtra_c, int pad_start)
{
	int j;

	if (width > length)
	{
		for (j = 3; j < width - length + 3; j++)
			buffer[j] = pad;
		buffer[j] = '\0';
		if (flags & FS_MINUS && pad == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (xtra_c)
				buffer[--indx] = xtra_c;
			return (wrt(1, &buffer[indx], length) + wrt(1, &buffer[3], j - 3));
		}
		else if (!(flags & FS_MINUS) && pad == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (xtra_c)
				buffer[--indx] = xtra_c;
			return (wrt(1, &buffer[3], j - 3) + wrt(1, &buffer[indx], length));
		}
		else if (!(flags & FS_MINUS) && pad == '0')
		{
			if (xtra_c)
				buffer[--pad_start] = xtra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (wrt(1, &buffer[pad_start], j - pad_start) +
				wrt(1, &buffer[indx], length - (1 - pad_start) - 2));
		}
	}
	buffer[--indx] = 'x';
	buffer[--indx] = '0';
	if (xtra_c)
		buffer[--indx] = xtra_c;
	return (wrt(1, &buffer[indx], BUFF_SIZE - indx - 1));
}
