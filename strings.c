#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @x: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *x)
{
	int k = 0;

	if (!x)
		return (0);

	while (*x++)
		k++;
	return (k);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @x1: the first strang
 * @x2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *x1, char *x2)
{
	while (*x1 && *x2)
	{
		if (*x1 != *x2)
			return (*x1 - *x2);
		x1++;
		x2++;
	}
	if (*x1 == *x2)
		return (0);
	else
		return (*x1 < *x2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @str: string to search
 * @sstr: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *str, const char sstr)
{
	while (*sstr)
		if (*sstr++ != *str++)
			return (NULL);
	return ((char *)str);
}

/**
 * _strcat - concatenates two strings
 * @destn: the destination buffer
 * @srcbf: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *destn, char *srcbf)
{
	char *reg = destn;

	while (*destn)
		destn++;
	while (*srcbf)
		*destn++ = *srcbf++;
	*destn = *srcbf;
	return (reg);
}
