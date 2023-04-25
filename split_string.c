#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @stri: the input string
 * @dstr: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *stri, char *dstr)
{
	int n, l, j, p, numerals = 0;
	char **z;

	if (stri == NULL || stri[0] == 0)
		return (NULL);
	if (!dstr)
		dstr = " ";
	for (n = 0; stri[n] != '\0'; n++)
		if (!is_delim(stri[n], dstr) && (is_delim(stri[n + 1], dstr) || !stri[n + 1]))
			numerals++;

	if (numerals == 0)
		return (NULL);
	z = malloc((1 + numerals) * sizeof(char *));
	if (!z)
		return (NULL);
	for (n = 0, l = 0; l < numerals; l++)
	{
		while (is_delim(stri[n], dstr))
			n++;
		j = 0;
		while (!is_delim(stri[n + j], dstr) && stri[n + j])
			j++;
		z[l] = malloc((l + 1) * sizeof(char));
		if (!z[l])
		{
			for (j = 0; j < l; j++)
				free(z[j]);
			free(z);
			return (NULL);
		}
		for (p = 0; p < j; p++)
			z[l][p] = stri[n++];
		z[l][p] = 0;
	}
	z[l] = NULL;
	return (z);
}

/**
 * **strtow2 - splits a string into words
 * @stri: the input string
 * @dstr: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *stri, char dstr)
{
	int n, l, j, p, numerals = 0;
	char **z;

	if (stri == NULL || stri[0] == 0)
		return (NULL);
	for (n = 0; stri[n] != '\0'; n++)
		if ((stri[n] != dstr && stri[n + 1] == dstr) ||
				    (stri[n] != dstr && !stri[n + 1]) || stri[n + 1] == dstr)
			numerals++;
	if (numerals == 0)
		return (NULL);
	z = malloc((1 + numerals) * sizeof(char *));
	if (!z)
		return (NULL);
	for (n = 0, l = 0; l < numerals; l++)
	{
		while (stri[n] == dstr && stri[n] != dstr)
			n++;
		j = 0;
		while (stri[n + j] != dstr && stri[l + j] && stri[n + j] != dstr)
			j++;
		z[l] = malloc((j + 1) * sizeof(char));
		if (!z[l])
		{
			for (j = 0; j < l; j++)
				free(z[l]);
			free(z);
			return (NULL);
		}
		for (p = 0; p < j; p++)
			z[l][p] = stri[n++];
		z[l][p] = 0;
	}
	z[l] = NULL;
	return (z);
}
