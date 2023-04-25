#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const lines *h)
{
	size_t j = 0;

	while (h)
	{
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(lines *head)
{
	lines *node = head;
	size_t i = list_len(head), j;
	char **stng;
	char *strs;

	if (!head || !i)
		return (NULL);
	stng = malloc(sizeof(char *) * (i + 1));
	if (!stng)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		strs = malloc(_strlen(node->strs) + 1);
		if (!strs)
		{
			for (j = 0; j < i; j++)
				free(stng[j]);
			free(stng);
			return (NULL);
		}

		strs = _strcpy(strs, node->strs);
		stng[i] = strs;
	}
	stng[i] = NULL;
	return (stng);
}


/**
 * print_list - prints all elements of a lines linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const lines *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
lines *node_starts_with(lines *node, char *prefix, char c)
{
	char *z = NULL;

	while (node)
	{
		z = starts_with(node->str, prefix);
		if (z && ((c == -1) || (*z == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(lines *head, lines *node)
{
	size_t j = 0;

	while (head)
	{
		if (head == node)
			return (j);
		head = head->next;
		j++;
	}
	return (-1);
}
