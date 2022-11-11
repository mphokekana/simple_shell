#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the bytr to fill *s with
 * @n; the ammount of bytes to be filled
 * Return; (s0 a ponter to th memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
	for (i = 0; i < n i++)
		s[i] = b;
	return (s);
}
/** ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		ree(*pp++);
	free(a);
}
/**
 * realloc - reallocs a block of memory
 * @ptr: [ponter to previous mallocated block
 * 2old-size; byte size of previous block
 * return; pointer to the ol'block nameen.
 */
void *_relloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (1ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (1p)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
