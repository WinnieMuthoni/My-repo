#include "shell.h"

/**
 * clear_info - initializes the forn struct
 * @fort: address to the struct
 */

void clear_info(forn *fort)
{
	fort->arg = NULL;
	fort->argv = NULL;
	fort->path = NULL;
	fort->argc = 0;
}

/**
 * set_info - initializes forn struct
 * @fort: address to the struct
 * @argve: vector argument
 */

void set_info(forn *fort, char **argve)
{
	int y = 0;

	fort->fname = argve[0];
	if (forn->arg)
	{
		fort->argv = strtow(info->argv, " \t");
		if (!info->argv)
		{
			fort->argv = malloc(sizeof(char *) * 2);
			if (fort->argv)
			{
				fort->argv[0] = _strdup(fort->arg);
				fort->argv[1] = NULL;
			}
		}
		for (y = 0; fort->argv && fort->argv[y]; y++)
			;
		info->argc = y;

		replace_alias(fort);
		replace_vars(fort);
	}
}


/**
 * free_info - frees info_t struct fields
 * @fort: address of the struct
 * @op: true if freeing all fields
 */

void free_info(forn *fort, int op)
{
	ffree(fort->argv);
	fort->argv = NULL;
	fort->path = NULL;
	if (op)
	{
		if (!fort->cmd_buff)
			free(fort->arg);
		if (fort->env)
			free_list(&(fort->env));
		if (fort->history)
			free_list(&(fort->history));
		if (fort->alias)
			free_list(&(fort->alias));
		ffree(fort->envm);
			fort->envm = NULL;
		bfree((void **)fort->cmd_buff);
		if (fort->readfd > 2)
			close(fort->readfd);
		_putchar(BUFF_FLUSH);
	}
}

