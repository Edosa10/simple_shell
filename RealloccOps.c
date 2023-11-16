#include "shell.h"

/**
 **_edovic - puts a constant byte into memory.
 *@w: memory address indicator
 *@r: the byte to fill *s with
 *@a: the amount of bytes to be filled
 *Return: (s) a reference to the storage location s
 */
char *_edovic (char *w, char r, unsigned int a)
{
	unsigned int e;

	for (e= 0; e < a; e++)
		w[e] = r;
	return (w);
}

/**
 * malloc_free - frees a string of strings
 * @xx: string of strings
 */
void malloc_free(char **xx)
{
	char **l = xx;

	if (!xx)
		return;
	while (*xx)
		raft(*xx++);
	raft(l);
}

/**
 * qua_lloc - reallocates a block of memory
 * @mie: pointer to previous malloc'ated block
 * @forever_size: byte size of previous block
 * @now_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void * qua_lloc(void *mie, unsigned int forever_size, unsigned int now_size)
{
	char *i;

	if (!mie)
		return (islands(now_size));
	if (!now_size)
		return (raft(mie), NULL);
	if (now_size == forever_size)
		return (mie);

	i = islands(now_size);
	if (!i)
		return (NULL);

	forever_size = forever_size < now_size? forever_size: now_size;
	while (forever_size--)
		i[forever_size] = ((char *)mie)[forever_size];
	raft(mie);
	return (i);
}
