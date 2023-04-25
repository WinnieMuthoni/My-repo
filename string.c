#include "shell.h"

/**
 * _strcpy - copies a string
 * @destn: the destination
 * @srcbf: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *destn, char *srcbf)
{
	int k = 0;

	if (destn == srcbf || srcbf == 0)
		return (destn);
	while (srcbf[k])
	{
		destn[i] = srcbf[k];
		k++;
	}
	destn[k] = 0;
	return (destn);
}

/**
 * _strdup - duplicates a string
 * @strn: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *strn)
{
	int j = 0;
	char *reg;

	if (strn == NULL)
		return (NULL);
	while (*strn++)
		j++;
	reg = malloc(sizeof(char) * (j + 1));
	if (!reg)
		return (NULL);
	for (j++;j--;)
		reg[j] = *--strn;
	return (reg);
}

/**
 * _puts - prints an input string
 * @strp: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *strp)
{
	int k = 0;

	if (!strp)
		return;
	while (strp[k] != '\0')
	{
		_putchar(strp[i]);
		k++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @a: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char a)
{
	static int j;
	static char buff[WRITE_BUFF_SIZE];

	if (a == BUFF_FLUSH || i >= WRITE_BUFF_SIZE)
	{
		write(1, buff, j);
		j = 0;
	}
	if (a != BUFF_FLUSH)
		buff[j++] = a;
	return (1);
}
