#include "shell.h"

/**
 * _myhistory - diplays the history list, one command by line, preceded
 * with line numbers, starting at 0
 * @info: struct containing potaintal arguments. used to maintain
 * constant function protogype
 * Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets alias to string
 * @info: patameter struct
 * @str: the string alias
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _srtchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}
/**
 * set_alias - sets alias to string
 * @info: paramete struct
 * @str: the string alias
 * Return: the string alias
 * 0 = sucess, 1  =error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: 0 unless error == 1
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: structure containing potantial arguments used to maintain
 * const function prototypes
 * Return: 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchar(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}
	return (0);
}
