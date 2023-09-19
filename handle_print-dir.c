#include "main.h"
/**
 * manage_print - Prints an argument based on its type
 * @frmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @indx: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int manage_print(const char *frmt, int *indx, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int j, unknown_len = 0, prints_chars = -1;
	frmt_m frmt_types[] = {
		{'c', prt_char}, {'s', prt_string}, {'%', prt_percent},
		{'i', prt_int}, {'d', prt_int}, {'b', prt_binary},
		{'u', prt_unsigned}, {'o', prt_octal}, {'x', prt_hexadecimal},
		{'X', prt_hexa_upper}, {'p', prt_pointer}, {'S', prt_non_printable},
		{'r', prt_reverse}, {'R', prt_rot13string}, {'\0', NULL}
	};
	for (j = 0; frmt_types[j].frmt != '\0'; j++)
		if (frmt[*indx] == frmt_types[j].frmt)
			return (frmt_types[j].fnc(list, buffer, flags, width, precision, size));

	if (frmt_types[j].frmt == '\0')
	{
		if (frmt[*indx] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (frmt[*indx - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*indx);
			while (frmt[*indx] != ' ' && frmt[*indx] != '%')
				--(*indx);
			if (frmt[*indx] == ' ')
				--(*indx);
			return (1);
		}
		unknown_len += write(1, &frmt[*indx], 1);
		return (unknown_len);
	}
	return (prints_chars);
}

