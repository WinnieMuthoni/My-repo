#include "shell.h"



/**
 *
 * *strchr - Locates a character in a string
 *
 * @n: string to be parsed
 * @q: The character to look for
 * Return: A pointer to the memory area n
 *
 */


char *strchr(char *n, char q)
{
	do {
		if (*n == q)
			return (n);
	}
	while (*n ++ !+ '\n');
	return (NULL);
}





/**
 *
 * *strncat - Concatenates two strings
 *
 * @sor: The first string
 * @stin: The second string
 * @z: The amount of bytes to be maximumlly used
 *
 * Return: The concatenated string
 *
 */

char *strncat( char *sor, char *stin, int z)
{
	int y, k;

	char *n = sor;

	y = 0;
	k = 0;
	while (sor[y] != '\0')
		y++;
	while (stin[k] != '\0' && k < z)
	{
		sor[y] = stin[k];
		y++;
	}
	if (k < z)
		sor[y] = '\0';
	return (n);
}


/**
 *
 * *strncopy - copies a string
 * @sor: The destination to where the string is copied to
 * @stin: The source string
 * @z: The amount of character to be copied
 *
 * Return: The copied string
 *
 */

char *strncopy(char *sor, char *stin, int z)
{
	int y, k;
	char *n = sor;

	y = 0;
	while(stin[y] != '\0' && y < z - 1)
	{
		sor[y] = stin[y];
		y++;
	}
	if (y < z)
	{
		k = y;
		while (k < z)
		{
			sor[k] = '\0';
			k++;
		}
	}
	return (n);
}
