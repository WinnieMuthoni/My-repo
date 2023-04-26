#include "shell.h"



/**
 * interactive - returns true if shell is interactive mode
 * @fort: struct address
 *
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(forn *fort)

{
	return (isatty(STDIN_FILENO) && fort->readfd <= 2);
}


/**
 * is_delim - checks if character is a delimeter
 *
 * @z: the char to check
 *
 * @delimeta: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char z, char *delimeta)
{
	while (*delimeta)
		if (*delimeta++ == z)
			return (1);
	return (0);
}



/**
 * _isalpha - checks for alphabetic character
 *
 * @z: The character to input
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */


int _isalpha(int z)
{
	if ((z >= 'a' && z <= 'z') || (z >= 'A' && z <= 'Z'))
		return (1);
	else
		return (0);
}



/**
 * _atoi - converts a string to an integer
 *
 * @k: the string to be converted
 *
 * Return: 0 if no numbers in string, otherwise converted number
 */




int _atoi(char *k)
{
	int y, al = 1, flaggy = 0, out_put;
	unsigned int res = 0;

	for (y = 0; k[y] != '\0' && flaggy != 2; y++)
	{
		if (k[y] == '-')
			al *= -1;

		if (k[y] >= '0' && k[y] <= '9')
		{
			flaggy = 1;
			res *= 10;
			res += (k[y] - '0');
		}
		else if (flaggy == 1)
			flaggy = 2;
	}

	if (al == -1)
		out_put = -res;
	else
		out_put = res;

	return (out_put);
}

