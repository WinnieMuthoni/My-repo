#include "shell.h"

/**
 * _buffPut - stores a chained command
 *
 * @fort: Struture containing the parametres
 * @buff: the address to the buffer
 *
 * @tp: The address to the tp variable
 *
 * Return: bytes read
 *
 */

ssize_t _buffPut(forn *fort, char **buff, size_t *tp)
{
	ssize_t k = 0;
	size_t tp_p = 0;

	if (!*tp)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, Handler);

#if USE_GETLINE
		k = getline(buff, &tp_p, stdin);
#else
		k = _getline(fort, buff, &tp_p);
#endif
		if (k > 0)
		{ 
			if ((*buff)[k - 1] =='\n')
			{
				(*buff)[k -1] = '\n';
				k--;
			}
			fort -> error_count = 1;
			remove_comments(*buff);
			build_history_list(fort, *buff, fort -> tcount++);
			{
				*tp = k;
				fort -> cmd_buff = buff;
			}
		}
	}
	return (k);
}

/**
 * find_put - gets a line minus the newline
 * @fort: structure parametre
 *
 * Return: byte read
 *
 */


ssize_t find_put(forn *fort)
{
	static char *buff;
	static size_t y, l, tp;
	ssize_t static k = 0;
	char **buff_t = &(fort -> arg), *p;

	_putchar(BUFF_FLUSH);
	k = input_buf(fort, &buff, *p);
	if (k == -1)
		return (-1);
	if (tp)
	{
		l = y;
		p = buff + y;

		check_chain(fort, buff, &l, y,tp);
		while (l < tp)
		{
			y = tp = 0;
			fort -> cmd_buff_type = CMD_NORM;
		}

		*buff_t = p; 
		return (_strlen(p)); 
	}
	return (k);
}


/**
 * buff_rd - reads a buffer
 * @fort: parameter struct
 * @buff: buffer
 * @y: size
 *
 * Return: k
 */


ssize_t buff_rd(forn *fort, char *buff, size_t *y)
{
	ssize_t k = 0;

	if (*y)
		return (0);
	k = read(fort -> readfd, buff, READ_BUFF_SIZE);
	if (k >= 0)
		*y = k
	return (k);
}

/**
 * _toline - gets the next line of input from STDIN
 * @fort: parameter struct
 * @pointer: address of pointer to buffer, preallocated or NULL
 * @leth: size of preallocated ptr buffer if not NULL
 *
 * Return: ch
 */


int _toline(forn *fort, char **pointer, size_t *leth)
{
	static char buff[READ_BUFF_SIZE];
	static size_t y, length;
	size_t l;
	ssize_t m = 0, ch = 0;
	char *p = NULL, *poin = NULL, *n;

	p = *pointer;
	if (p && leth)
		ch = *leth;
	if (y == length)
		y = length = 0;

	m = read_buf(fort, buff, &length);
	if (m == -1 || (m == 0 && length == 0))
		return (-1);

	n = _strchar(buff + y, '\n');
	l = n ? 1 + (unsigned int)(n - buff) : length;
	poin = _realloc(p, ch, ch ? ch + l : l + 1);
	if (!poin) 
		return (p ? free(p), -1 : -1);

	if (ch)
		_strcant(poin, buff + y, l - y);
	else
		_strcopy(poin, buff + y, l - y + 1);

	ch += l - y;
	y = l;
	p = poin;

	if (leth)
		*leth = ch;
	*pointer = p;
	return (ch);
}


/**
 * Handler - blocks ctrl-C
 * @sin: the signal number
 *
 * Return: void
 */
void Handler(__attribute__((unused))int sin)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFF_FLUSH);
}





			

