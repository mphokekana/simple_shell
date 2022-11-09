#include "shell.h"

/**
 * _myenv =- prints the current environment
 * @info: struct containing potential argumentsused to maintain
 * constant function prototype
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - gets the value of an environ variable
 * @info: struct containing potential arguments
 * @name: environment variable name
 * Return: the value
 */
char _getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->str, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - Initialize a new environment variable,
 * or odify a existing one
 * @info: struct containing potential srguments used to maintain
 * Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - Remove a envirinment variable
 * @info: struct contains potential arguments used to maintain
 * constant function prototype
 * Return: 0
 */
int _myunsetenv(info_t *info)
{
	int a;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (a = 1; a <= info->argc; a++)
		_unsetenv(info, info->argv[a]);
	return (0);
}
/**
 * populate_env_list - populates env linked list
 * @info: struct containing potential arguments. used to mentain
 * constant function prototype
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[a], 0);
	info->env = node;
	return (0);
}
