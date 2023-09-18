#include "main.h"

void prt_buffer(char buffer[], int *buff_indx);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, prints = 0, prints_chars = 0;
	int flags, width, precision, size, buff_indx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (i = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_indx++] = format[j];
			if (buff_indx == BUFF_SIZE)
				print_buffer(buffer, &buff_indx);
			prints_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_indx);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list);
			precision = get_precision(format, &j, list);
			size = get_size(format, &j);
			++j;
			prints = manage_print(format, &j, list,
			buffer, flags, width, precision, size);
			if (prints == -1)
				return (-1);
			prints_chars += prints;
		}
	}
	print_buffer(buffer, &buff_indx);

	va_end(list);

	return (prints_chars);
}

/**
 * prt_buffer - Prints the contents of the buffer
 * @buffer: Array of chars
 * @buff_indx: Index at which to add next char and  represents the length.
 */
void prt_buffer(char buffer[], int *buff_indx)
{
	if (*buff_indx > 0)
		write(1, &buffer[0], *buff_indx);

	*buff_indx = 0;
}
