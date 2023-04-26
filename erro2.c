#include "shell.h"



/**
 * _erratoi - converts a string to an integer
 * @stri: the string to be converted
 * 
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */

int _erratoi(char *stri)
{
	int y = 0;
	unsigned long int res = 0;

	if (*stri == '+')
		stri++;  
	for (y = 0;  stri[y] != '\0'; y++)
	{
		if (stri[y] >= '0' && stri[y] <= '9')
		{
			res *= 10;
			res += (stri[y] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}



/**
 * print_error - prints an error message
 *
 *  @fort: the parameter & return info struct
 * 
 * @errstr: string containing specified error type
 * 
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */


void print_error(forn *fort, char *errstr)
{
	_eputs(fort->fname);
	_eputs(": ");
	print_d(fort->error_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(fort->argv[0]);
	_eputs(": ");
	_eputs(errstr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @in_put: the input
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int in_put, int fd)
{
	int (*__putchar)(char) = _putchar;
	int y, count = 0;
	unsigned int _abs_, curnt;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (in_put < 0)
	{
		_abs_ = -in_put;
		__putchar('-');
		count++;
	}
	else
		_abs_ = in_put;
	curnt = _abs_;
	for (y = 1000000000; y > 1; y /= 10)
	{
		if (_abs_ / y)
		{
			__putchar('0' + curnt / y);
			count++;
		}
		curnt %= y;
	}
	__putchar('0' + curnt);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @ne: number
 * @base: base
 * @flaggy: argument flags
 *
 * Return: string
 */
char *convert_number(long int ne, int base, int flaggy)
{
	static char *ary;
	static char buffer[50];
	char si = 0;
	char *ptr;
	unsigned long m = ne;

	if (!(flaggy & CONVERT_UNSIGNED) && ne < 0)
	{
		m = -ne;
		si = '-';

	}
	ary = flaggy & CONVERT_LOWERCASE ? "0123456789abcdefghijklmn" : "0123456789ABCDEFGHIJKLMN";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = ary[n % base];
		m /= base;
	} while (m != 0);

	if (si)
		*--ptr = si;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buff: address of the string to modify
 *
 * Return: Always 0;
 */


void remove_comments(char *buff)
{
	int y;

	for (y = 0; buff[y] != '\0'; y++)
		if (buff[y] == '#' && (!y || buff[y - 1] == ' '))
		{
			buff[y] = '\0';
			break;
		}
}

