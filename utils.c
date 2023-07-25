#include "main.h"

/**
 * is_printable - evaluates if a char is printable
 *
 * @c: char to be evaluated
 *
 * Return: Always 0.
*/

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - append ascii in hexa code
 *
 * @buffer: an array of char
 * @i: index
 * @ascii_code: ASCII CODE
 *
 * Return: Always 0.
*/

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verifies if the char is a dig
 *
 * @c: char to be verified
 *
 * Return: Always 0.
*/

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - cast a num to the specified size
 *
 * @num: number to be casted
 * @size: number's size
 *
 * Return: Always 0.
*/

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - cast a num to the specified size
 *
 * @num: number to be casted
 * @size: number's size
 *
 * Return: Always 0.
*/

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
