#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 * Return: 0
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputschar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * *@c: the character to print
 * Return: on success 1.
 * on error, -1 is returned, and errorno is set appropriately
 */

int _eputchar(char c)
{

	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @fd: The character to pint
 * @fd: the filedescriptor to write to
 * Return: on success 1.
 * ON error, -1 is returnd, and errono is set approprately
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf(WRITE_BUF_SIZE);

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the number of char put
 * return: the number of chars put
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
