#include "shell.h"

/**
 * convertToInt - converts a string representation to an actual integer value
 * @s: string representation to be converted to int
 * Return: 0 if no numbers in string, converted number otherwise
 *		returns -1 indicating an error
 */
int convertToInt(char *s)
{
	int j = 0;
	unsigned long int output = 0;

	if (*s == '+')
		s++;
	for (j = 0;  s[j] != '\0'; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
		{
			output *= 10;
			output += (s[j] - '0');
			if (output > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (output);
}





/**
 * _printError – prints formatted error message
 * @info: the parameter & return info struct
 * @errstring: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void _printError(info_t *info, char *errstring)
{
	_writeString(info->fileName);
	_writeString(": ");
	printIntNum(info->lineCountNum, STDERR_FILENO);
	_writeString(": ");
	_writeString(info->argv[0]);
	_writeString(": ");
	_writeString(errstring);
}

/**
 * printIntNum - function prints a decimal (integer) number (base 10)
 * @input: an integer to be printed
 * @fd: an int representing the file descriptor which determines output stream
 *
 * Return: returns total numbers of characters printed
 */
int printIntNum(int code, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, sumUp = 0;
	unsigned int _total, process;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_total = -code;
		__putchar('-');
		sumUp++;
	}
	else
		_total = code;
	current = _total;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_total / i)
		{
			__putchar('0' + process / j);
			sumUp++;
		}
		process %= j;
	}
	__putchar('0' + process);
	sumUp++;

	return (sumUp);
}

/**
 * numConverter – the custom converter function
 * @numerals: i.e numbers
 * @base: base parameter
 * @flags: args flags parameter
 *
 * Return: string
 */
char *numConverter(long int numerals, int base, int flags)
{
	static char *lineUp;
	static char buffer[50];
	char sign = 0;
	char *spot;
	unsigned long v = numerals;

	if (!(flags & CONVERT_UNSIGNED) && numerals < 0)
	{
		v = -numerals;
		sign = '-';

	}
	lineUp = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	spot = &buffer[49];
	*spot = '\0';

	do	{
		*--spot = lineUp[n % base];
		v /= base;
	} while (v != 0);

	if (sign)
		*--spot = sign;
	return (spot);
}

/**
 * xtractComments - function replaces first instance of '*' with '\0'
 * @memoryBuf: temporary memory area of string to modify
 *
 * Return: Always 0;
 */
void xtractComments(char *memoryBuf)
{
	int j;

	for (j = 0; memoryBuf[j] != '\0'; j++)
		if (memoryBuf[j] == '#' && (!j || memoryBuf[j - 1] == ' '))
		{
			memoryBuf[j] = '\0';
			break;
		}
}


