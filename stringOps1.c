#include "shell.h"

/**
 * _strCopy – for copying a string data
 * @end: the destination buffer
 * @src: the source buffer
 *
 * Return: ptr to end
 */
char *_strcopy(char *end, char *src)
{
	int j = 0;

	if (end == src || src == 0)
		return (end);
	while (src[j])
	{
		end[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (end);
}



/**
 * _stringDup - duplicates a string
 * @string: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_stringDup(const char *string)/* function declaration */
{
	int span = 0; /* declaration and initialization of int var to 0 */
	char *ref; /* declaration of pointer to char ‘ref’ */

	if (string == NULL) /* handling error: check if string is null */
		return (NULL); /* if null, indication that there’s nothing to duplicate */
	while (*string++) /* iterating loop through chars of input string */
		span++; /* incrementing int var ‘span’ until null terminator */
	ref = malloc(sizeof(char) * (span + 1)); /* dynamic memory allocation: for storing chars of inputs plus one more for null terminator */
	if (!ref) /* checks if memory allocation was successful */
		return (NULL); /* failure indication */
	for (span++; span--;) /* copies characters from end of allocated memory, iterating until it reaches the beginning */
		ref[span] = *--string; /* decrement string pointer before accessing value */
	return (ref);
}


/**
 *_puts – for printing an input string
 *@string: string to be printed
 *
 * Return: Nill
 */
void _puts(char *string)
{
	int j = 0;

	if (!string)
		return;
	while (string[j] != '\0')
	{
		_putchar(string[j]);
		j++;
	}
}



/**
 * _putChar - writes the character f to stdout
 * @f: The char to print to console
 *
 * Return: upon success, 1.
 * Upon error, -1 is returned, and errno is set appropriately.
 */
int _putChar(char f)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (f == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (f != BUF_FLUSH)
		buf[j++] = f;
	return (1);
}
