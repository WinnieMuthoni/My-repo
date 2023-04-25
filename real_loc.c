#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @x: the pointer to the memory area
 * @a: the byte to fill *s with
 * @m: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *x, char a, unsigned int m)
{
        unsigned int j;

	for (j = 0; j < m; j++)
		x[j] = a;
	return (x);
}

/**
 * ffree - frees a string of strings
 * @sr: string of strings
 */
void ffree(char **sr)
{
	char **p = sr;

	if (!sr)
		return;
	while (*sr)
		free(*sr++);
	free(p);
}

/**
 * _realloc - reallocates a block of memory
 * @str: pointer to previous malloc'ated block
 * @previous_size: byte size of previous block
 * @next_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *str, unsigned int previous_size, unsigned int next_size)
{
	char *a;

	if (!str)
		return (malloc(next_size));
	if (!next_size)
		return (free(str), NULL);
	if (next_size == previous_size)
		return (str);

	a = malloc(next_size);
	if (!a)
		return (NULL);

	previous_size = previous_size < next_size ? previous_size : next_size;
	while (previous_size--)
		a[previous_size] = ((char *)str)[previous_size];
	free(str);
	return (a);
}
