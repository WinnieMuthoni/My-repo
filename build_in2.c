#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceeded
 *              with line numbers, starting at 0.
 * @fort: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(forn *fort)
{
        print_list(fort->history);
        return (0);
}

/**
 * unset_alias - sets alias to string
 * @fort: parameter struct
 * @stng: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(forn *fort, char *stng)
{
        char *p, z;
        int tme;

        p = _strchr(str, '=');
        if (!p)
                return (1);
        z = *p;
        *p = 0;
        tme = delete_node_at_index(&(fort->alias),
                get_node_index(fort->alias, node_starts_with(fort->alias, stng, -1)));
        *p = z;
        return (tme);
}



/**
 * set_alias - sets alias to string
 * @fort: parameter struct
 * @stng: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */


int set_alias(forn *fort, char *stng)
{
        char *p;

        p = _strchr(stng, '=');
        if (!p)
                return (1);
        if (!*++p)
                return (unset_alias(fort, stng));

        unset_alias(fort, stng);
        return (add_node_end(&(fort->alias), stng, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */


int print_alias(list_t *node)
{
        char *p = NULL, *t = NULL;

        if (node)
        {
                p = _strchr(node->str, '=');
                for (t = node->stng; t <= p; t++)
                _putchar(*t);
                _putchar('\'');
                _puts(p + 1);
                _puts("'\n");
                return (0);
        }
        return (1);
}



/**
 * _myalias - mimics the alias builtin (man alias)
 * @fort: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */


int _myalias(forn *fort)
{
        int y = 0;
        char *p = NULL;
        lines *node = NULL;

        if (fort->argc == 1)
        {
                node = fort->alias;
                while (node)
			  {
                node = fort->alias;
                while (node)
                {
                        print_alias(node);
                        node = node->next;
                }
                return (0);
        }
        for (y = 1; fort->argv[y]; y++)
        {
                p = _strchr(fort->argv[y], '=');
                if (p)
                        set_alias(fort, fort->argv[y]);
                else
                        print_alias(node_starts_with(fort->alias, fort->argv[y], '='));
        }

        return (0);
}
