#include "shell.h"

/**
 * _strLength - returns string length
 * @s: specified string to check
 *
 * Return: int value of string length
 */
int strLength(char *s) /* declaration of ‘_strLength’ a ptr to ‘char *’ */
{
	int j = 0; /* declare and initialize variable for storing str len */

	if (!j) /* check if ptr points to nothing */
		return (0); /* indicate str len is zero */

	while (*s++) /* check for null terminator */
		j++; /* incrementing ptr ‘j’ while counting char until null */
	return (j); /* returns int value of string length */
}

/**
 * _compareString – lexicographically compare two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _compareString(char *s1, char *s2) /* function declaration with two args of an int return type */
{
	while (*s1 && *s2) /* loop comparing char from ‘s1’ and ‘s2’ if not NULL */
	{
		if (*s1 != *s2) /* non-equality check of current characters */
			return (*s1 - *s2); /* returns ASCII value character of string 2 */
		s1++; /* increment s1 to move to next char in strings */
		s2++; /* increment s2 to move to next char in strings */
	}
	if (*s1 == *s2) /* checks if both strings are equal */
		return (0); /* indicating strings are equal */
	else
		return (*s1 < *s2 ? -1 : 1); /* compares ASCII value of final characters using ternary operator ( ‘? :’) */
}

/**
 * beginsWith - checks if alpha begins with bravo
 * @alpha: string ptr address to search
 * @bravo: next string to search
 *
 * Return: address of next char of alpha or NULL
 */
char *beginsWith(const char *alpha, const char *bravo)
{
	while (*bravo)
		if (*bravo++ != *alpha++)
			return (NULL);
	return ((char *)alpha);
}

/**
 * _strcat – a custom function that integrates two strings
 * @dest: the destination string buffer
 * @src: the source string buffer to be appended
 *
 * Return: modified destination string ptr to char
 */
char *_strcat(char *dest, char *src) /* function declaration taking two args, ptr to a char type */
{
	char *ret = dest; /* declaration of ptr ‘ret’ and initialization */

	while (*dest) /* loop for moving ‘dest’ to end of destination string */
		dest++; /* loop continues until end of string i.e NULL terminator */
	while (*src)  /* while loop operation for specific purpose */
		*dest++ = *src++; /* loop integrates anf copy characters of both strings */
	/* *dest = *src; */
	*dest = ‘\0’;
	return (ret);
}
