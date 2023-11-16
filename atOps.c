#include "shell.h"

/**
 * _interactive – if shell is in interactive mode, returns true
 * @info: the struct address parameter
 *
 * Return: if yes, return 1 otherwise 0
 */
int _interactive(info_t *getInfo)
{
	return (isatty(STDIN_FILENO) && getInfo->readfd <= 2);
}


/**
 * _isDelim – checks whether character is of type delimeter
 * @k: specified char to check
 * @delimStr: delimeter string
 * Return: 1 if true, 0 if false
 */
int _isDelim(char k, char *delimStr)
{
	while (*delimStr)
		if (*delimStr++ == k)
			return (1);
	return (0);
}

/**
 *_isAlpha - checks whether character is alphabetic type
 *@k: input char
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isAlpha(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}



/**
 *_myAtoi – string to integer converter
 *@str: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _myAtoi(char *str)
{
	int j, sign = 1, flag = 0, intOutput;
	unsigned int resultBuf = 0;

	for (j = 0;  str[j] != '\0' && flag != 2; j++)
	{
		if (str[j] == '-')
			sign *= -1;

		if (str[j] >= '0' && str[j] <= '9')
		{
			flag = 1;
			resultBuf *= 10;
			resultBuf += (str[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		intOutput = -resultBuf;
	else
		intOutput = resultBuf;

	return (intOutput);
}
