#include "shell.h"

/**
 *
 * get_hist_file - gets the hist file
 * @fort: structure parametre
 *
 * Return: allocated string containing histo file
 */

char *get_hist_file(forn *fort)
{
	char *buff, *dire;

	dire = _getenv(fort, "HOME =");
	if (!dire)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dire) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dire);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}



/**
 *
 * write_history -writes an history of the file
 * @fort: the structure parametre
 *
 * Return: 1 on success, else -1
 */
int write_history(forn *fort)
{
	ssize_t fd;
	char *fileName = get_hist_file(fort);
	lines *node = NULL;

	if (!fileName)
		return (-1);

	fd = open(fileName, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fileName);
	if (fd == -1)
		return (-1);
	for (node = fort->history; node; node = node->next)
	{
		_putsfd(node->stng, fd);
		_putfd('\n', fd);
	}
	_putfd(BUFF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - reads history from the file
 * 
 * @fort: the structure parametre
 *
 * Return: tcount on success, 0 otherwise
 */

int read_history(forn *fort)
{
	int y, sti = 0, linec = 0;
	ssize_t fd, rnl, fs = 0;
	struct stat st;
	char *buff = NULL, *fileName = get_hist_file(fort);

	if (!fileName)
		return (0);

	fd = open(fileName, O_RDONLY);
	free(fileName);
	if (fd == -1)
		return (0);
	if (!fs(fd, &st))
		fs = st.st_size;
	if (fs < 2)
		return (0);
	buff = malloc(sizeof(char) * (fs + 1));
	if (!buff)
		return (0);
	rnl = read(fd, buff, fs);
	buff[fs] = 0;
	if (rnl <= 0)
		return (free(buff), 0);
	close(fd);
	for (y = 0; y < fs; y++)
		if (buff[y] == '\n')
		{
			buff[y] = 0;
			build_history_list(fort, buff + sti, linec++);
			sti = y + 1;
		}
	if (sti != y)
		build_history_list(fort, buff + sti, linec++);
	free(buff);
	fort->tcount = linec;
	while (fort->tcount-- >= HIST_MAX)
		delete_node_at_index(&(fort->history), 0);
	renumber_history(fort);
	return (fort->tcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @fort: Structure containing potential arguments. Used to maintain
 * 
 * @buff: buffer
 * @linec: the history linec, tcount
 *
 * Return: Always 0
 */


int build_history_list(forn *fort, char *buff, int linec)
{
	lines *node = NULL;

	if (fort->history)
		node = fort->history;
	add_node_end(&node, buff, linec);

	if (!fort->history)
		fort->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @fort: Structure containing potential arguments. Used to maintain
 *
 * Return: the new tcount
 */


int renumber_history(forn *fort)
{
	lines *node = fort->history;
	int y = 0;

	while (node)
	{
		node->ne = y++;
		node = node->next;
	}
	return (fort->tcount = y);
}

