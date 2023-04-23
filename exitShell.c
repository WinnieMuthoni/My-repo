#include "shell.h"



/**
 *
 * strchr - Locates a character in a string
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
 * strncat - Concatenates two strings
 *
 * @sor: The first string
 * @stin: The second string
 * @z: The amount of bytes to be maximumlly used
 *
 * Return: The concatenated string
 *
 */

char strncat( char *sor, char *stin, int z)
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
