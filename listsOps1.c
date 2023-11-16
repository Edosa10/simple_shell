#include "shell.h"

/**
 * calcLen - determines length of linked list
 * @t: pointer to top node
 *
 * Return: length size of list
 */
size_t calcLen(const list_t *t)
{
	size_t j = 0;

	while (t)
	{
		t = t->next;
		j++;
	}
	return (j);
}

/**
 * stringsToArray - returns an array of strings of the list->strBuf
 * @first: pointer to head node
 *
 * Return: converted array of strings
 */
char **stringToArray(list_t *first)
{
	list_t *intersection = first;
	size_t g = stringToArray(first), k;
	char **strsBuf;
	char *strBuf;

	if (!first || !g)
		return (NULL);
	strsBuf = malloc(sizeof(char *) * (g + 1));
	if (!strsBuf)
		return (NULL);
	for (g = 0; intersection;
       intersection = intersection->next, g++)
	{
		strBuf = malloc(_strlen(intersection->strBuf) + 1);
		if (!str)
		{
			for (k = 0; k < g; k++)
				free(strsBuf[k]);
			free(strsBuf);
			return (NULL);
		}

		strBuf = _strcpy(strBuf, intersection->strBuf);
		strsBuf[g] = strBuf;
	}
	strsBuf[g] = NULL;
	return (strsBuf);
}

/**
 * _printList - prints all elements of a list_t linked list
 * @t: pointer to top node
 *
 * Return: size of list_t linked list
 */
size_t _printList(const list_t *t)
{
	size_t j = 0;

	while (t)
	{
		_puts(convertNum(t->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(t->string ? t->string : "(nil)");
		_puts("\n");
		t = t->next;
		j++;
	}
	return (j);
}

/**
 * checkNodePrefix - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @n: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *checkNodePrefix(list_t *node, char *prefix, char n)
{
	char *p = NULL;

	while (node)
	{
		p = checkNodePrefix(node->string, prefix);
		if (p && ((n == -1) || (*p == n)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * _getNodeIndex - gets the index of a node
 * @top: pointer to list head
 * @nodePtr: pointer to node
 *
 * Return: index of node or -1
 */
ssize_t _getNodeIndex(list_t *top, list_t *nodePtr)
{
	size_t j = 0;

	while (top)
	{
		if (top == nodePtr)
			return (j);
		top = top->next;
		j++;
	}
	return (-1);
}
