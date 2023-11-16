#include "shell.h"

/**
 *_printToConsole - prints an input string
 * @string: string to be printed to console
 *
 * Return: Nill
 */
void _printToConsole(char *string) /* function declaration, Taking a single argument */
{
	int j = 0; /* initializing declared local variable to 0 */

	if (!string) /* checks if input string in not a null pointer */
		return; /* return nothing: for handling case where input string is not valid */
	while (string[j] != '\0') /* loop iterating in input string until null char is encountered */
	{
		_eputChar(string[j]); /* passes current char ‘string’ to the newly called function ‘eputChar’ */
		j++; /* incrementing local variable by one to move to next char in string */
	}
}


/**
 * _printCharToConsole - writes the character f to stderr
 * @f: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printCharToConsole(char f)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (f == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (f != BUF_FLUSH)
		buf[j++] = f;
	return (1);
}



/**
 * writeToBufferAndFlush – write given char to a specified buffer and flush
 * @f: specified character to write
 * @fd: the buffer to write to ‘fd’
 *
 * Return: On success 1.
 * upon error, -1 is returned, and errno is set appropriately.
 */
int writeToBufferAndFlush(char f, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (f == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (f != BUF_FLUSH)
		buf[j++] = f;
	return (1);
}




/**
 * writeStringToFD – writes input string
 * @string: the input string to be written
 * @fd: the file descriptor to write to
 *
 * Return: number of chars written
 */
int writeStringToFD(char *string, int fd)
{
	int j = 0;

	if (!string)
		return(0);
	while (*string)
	{
		j += writeStringToFD(*string++, fd);
	}
	return (j);
}
