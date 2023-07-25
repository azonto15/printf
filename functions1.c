#include "main.h"

/**
 * print_unsigned - prints an unsigned int
 *
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calculated active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: Always 0.
*/

int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - prints an unsigned num in octal
 *
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calculate active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: Always 0.
*/

int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints an unsigned num in hexadecimal
 *
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calculate active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: Always 0.
*/

int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x' width, precision, size));
}

/**
 * print_hexa_upper - prints an unsigned num in upper hexadecimal
 *
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calculate active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: Always 0.
*/

int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X' width, precision, size));
}

/**
 * print_hexa - prints an unsigned num in upper or lower hexadecimal
 *
 * @types: list of arguments
 * @map_to: array of values to map the num to
 * @buffer: buffer array
 * @flags: calculate active flags
 * @flag_ch: calculate active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specificer
 * @size: size specification
 *
 * Return: Always 0.
*/

int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}