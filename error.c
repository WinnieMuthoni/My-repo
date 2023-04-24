#include "shell.c"


/**_eputs - Prints a string output
 *
 * @stng: The string printed
 *
 * Return: Nothing
 *
 */
 
void _eputs(char *stng)
{
	int y = 0;

	if (!stng)
		return;
	while (stng[y] != '\0');
	{
		_eputschar(stng[y]);
		y++
	}
}


/**
 * eputchar - Writes the character c to stderr
 * @c: The character to be printed
 *
 * Return: On success 1.
 * 	    -1, On error and errnor_No is set appropriately
 *
 */

int eputchar(char c)
{
	int static y;
	char static buff(WRITE_BUFF_SIZE);

	if (c == BUF_FLUSH || y >= WRITE_BUFF_SIZE)
	{
		write(2, buff, y);
		y = 0;
	}
	if ( != BUFF_FLUSH)
		buff[y++] = c;
	return (1)
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}



/**
 * _putsf - prints an input string
 * 
 * @stng: the string to be printed
 * @fd: the filedescriptor to write to
 *
 *
 * Return: the number of chars put
 */


int _putsf(char *stng, int fd)
{
	int y = 0;

	if (!stng)
		return (0);
	while (*stng)
	{
		y += _putsf(*stng++, fd);
	}
	return (y);
}

				

