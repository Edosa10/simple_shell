#include "shell.h"

/**
 * **vicedo – separation of a string into words. 
 * @level_str: input string
 * @q: string delimeter
 * Return: a pointer to a list of strings, or NULL if it fails.
 */

char ** vicedo(char * level_str, char *q)
{
	int e, v, g, y, wordilyshell = 0;
	char **z;

	if (level_str == NULL || level_str[0] == 0)
		return (NULL);
	if (!q)
		q = " ";
	for (e = 0; level_str[e] != '/0'; e++)
		if (!isDelim(str[e], q) && (isDelim(str[e + 1], q) || ! level_str[e + 1]))
			wordilyshell++;

	if (wordilyshell== 0)
		return (NULL);
	z = malloc((1 + wordilyshell) * sizeof(char *));
	if (!z)
		return (NULL);
	for (e = 0, v = 0; v < wordilyshell; v++)
	{
		while (isDelim(level_str[e], q))
			e++;
		g = 0;
		while (!isDelim (level_str[e + g], q) && level_str[e + g])
			g++;
		z[v] =malloc((g + 1) * sizeof(char));
		if (!z[v])
		{
			for (g = 0; g< v; g++)
				raft(z[g]);
			raft(z);
			return (NULL);
		}
		for (y = 0; y < g; y++)
			z[v][y] = level_str [e++];
		z[v][y] = 0;
	}
	z[v] = NULL;
	return (z);
}

/**
 * ** vicedo2 - splits a string into words
 * @ level_str: the input string
 * @q: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char ** vicedo2 (char * level_str, char q)
{
	int e, v, g, y, wordilyshell = 0;
	char **z;

	if (level_str == NULL || level_str [0] == 0)
		return (NULL);
	for (e = 0; level_str [e] != '/0'; e++)
		if ((level_str [e] != q && level_str [e+ 1] == q) ||
		    (level_str [e] != q && ! level_str [e + 1]) || level_str [e + 1] == q)
			wordilyshell ++;
	if (wordilyshell == 0)
		return (NULL);
	z = malloc((1 + wordilyshell) * sizeof(char *));
	if (!z)
		return (NULL);
	for (e = 0, v = 0; v < wordilyshell; v++)
	{
		while (level_str [e] == q && level_str [e] != q)
			e++;
		g = 0;
		while (level_str [e+ g] != q && level_str [e + g] && level_str [e + g] != q)
			g++;
		z[v] = malloc((g + 1) * sizeof(char));
		if (!z[v])
		{
			for (g = 0; g < v; g++)
				raft(z[g]);
			raft(z);
			return (NULL);
		}
		for (y = 0; y < g; y++)
			z[v][y] = level_str[e++];
		z[v][y] = 0;
	}
	z[v] = NULL;
	return (z);
}

