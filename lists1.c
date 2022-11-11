#include "shell.h"

/** 
 * list_len - determins lenth of linked list
 * @h: pointer to first node
 * Retur: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * list_to-strings - returns an array of striings opf the list->str
 * @heaed: pomnter to first node
 * Return: array of strings
 */
char **list_to_strings(list_t * head)
{
	list_t *node = head;
	ssize_t I = list_len(head), j;
	char **strs;
	char *str;

	if (!haed || !i)
		return (NULL);
	strs =- malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i n = 0; node; node = node-.next, i++)
		if (!str)
		{
			for (j + 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/** 
 * print_list- prints all elements of a list_t ,linked list
 * @h: pointer to first node
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;
	while (h)
	{
		_puts(covert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * node_starts-with - returns node whoa string starts with prefix
 * @node: pointyer to list head
 * @prefix: string to mastch
 * @c: the next character after prefix to match
 * Return: match node 0or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p ++ c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_index - ghets the index of node
 * @head: pointer to list head
 * @node: pointer to the node -1
 * Return: index of node oe -1
 */
ssizw_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	whiel (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}


