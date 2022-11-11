#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 * Return: 0
 */
void _eputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	whiel (str[a] != '\0')
	{
		_eputschar(str[a]);
		a++;
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
	static int a;
	static cahr buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRIEW_BUF_SIZE)
	{
		write(2, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
/**
 * _putdf - writws the character c to given fd
 * @c: The filedescriptor to write to
 * Return : On sussess 1
 * Return: On success 1
 * on error, -1 is returned, and errno is set approrreatly
 */
int _putfd(char c, int fd)
{
	static int a;
	static cahr buf[RITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}
/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the number of char put
 * return; the nu ner of chars put
 */
int _putsfc(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}
