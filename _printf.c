#include "main.h"
<<<<<<< HEAD
#include <stdio.h>

/**
 * _printf - takes a string and args of each '%'
 * and prints them
 * @format: initial string containing % +
 * char denoting type and number of args
 * @...: variable list of arguments
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
int i, j;
int count = 0;
va_list lst;
interface ids[] = {
{'c', _print_char},
{'s', _print_string},
{'i', _print_int},
{'d', _print_int},
{'%', _print_mod},
{'\0', NULL}
};
va_start(lst, format);
for (i = 0; format[i]; i++)
if (format[i] == '%')
{
i++;
for (; format[i] != '\0'; i++)
{
for (j = 0; ids[j].id != '\0'; j++)
if (format[i] == ids[j].id)
{
count += ids[j].fn(lst);
break;
}
if (ids[j].id)
break;
}
if (format[i] == '\0')
return (-1);
}
else
{
write(1, &format[i], 1);
count += 1;
}
va_end(lst);
return (count);
=======

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
>>>>>>> 1ff405433defa4f740394402286b80226e97f3db
}
