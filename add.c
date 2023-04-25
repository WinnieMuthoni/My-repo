#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
lines *add_node(lines **head, const char *str, int num)
{
	lines *first_head;

	if (!head)
		return (NULL);
	first_head = malloc(sizeof(lines));
	if (!first_head)
		return (NULL);
	_memset((void *)first_head, 0, sizeof(lines));
	first_head->num = num;
	if (str)
	{
		first_head->str = _strdup(str);
		if (!first_head->str)
		{
			free(first_head);
			return (NULL);
		}
	}
	first_head->next = *head;
	*head = first_head;
	return (first_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
lines *add_node_end(lines **head, const char *str, int num)
{
	lines *first_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	first_node = malloc(sizeof(lines));
	if (!first_node)
		return (NULL);
	_memset((void *)first_node, 0, sizeof(lines));
	first_node->num = num;
	if (str)
	{
		first_node->str = _strdup(str);
		if (!first_node->str)
		{
			free(first_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = first_node;
	}
	else
		*head = first_node;
	return (first_node);
}

/**
 * print_list_str - prints only the str element of a lines linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const lines *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(lines **head, unsigned int index)
{
	lines *node, *previous_node;
	unsigned int j = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (j == index)
		{
			previous_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		j++;
		previous_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(lines **head_ptr)
{
	lines *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
