#include "shell.h"

/**
 * _myenv – for printing current environment variables
 * @info: a parameter structure that takes arguments
 * Return: Always 0
 */
int _myenv(info_t *info) /* declaration of function */
{
	printString_list(info->env); /* pass ‘env’ of ‘info’ structure as argument to the function ‘printString_list’ */
	return (0);
}

/**
 * get_env_value - assess and gets value of an env variable
 * @info: a parameter structure which holds possible arguments
 * @prospect: an env variable type
 *
 * Return: returns value of env
 */
char *_get_env_value(info_t *info, const char *prospect) /* declaration of function named ‘get_env_value’ that takes two arguments */
{
	list_t *interchange = info->env; /* declares and initializes a ptr to a struct of type list_t named ‘prospect’ with the env member of ‘info’ structure */
	char *t; declares a ptr to a character named ‘t’ */

	while (interchange) /* begins while loop
	{
		t = starts_with(interchange->str, prospect); /* calling function with args and assigns  the result to ‘t’ */
		if (t && *t) /* checks if current variable and next char are both not null terminators */
			return (t); /* if true, returns ptr */
		interchange = interchange->next; /* move to next interchange in linked list */
	}
	return (NULL); /* returns ‘null’ to indicate no specific env ‘prospect’ was found */
}

/**
 * _setenvValue – starts up a new environment variable,
 *             or adjust an existing one
 * @info: a Structure containing arguments for a
 *        constant function prototype.
 *  Return: Always 0
 */
int _setenvValue(info_t *info) /* function declaration of custom system call that takes a pointer to a structure of type ‘info_t */
{
	if (info->argc != 3) /* checks if number of command line args are not equal to three */
	{
		_writeError("Incorrect number of arguements\n"); /* if true, output error to console */
		return (1); /* indicate successful error handling */
	}
	if (_setenvValue(info, info->argv[1], info->argv[2])) /* calling ‘_setenvValue to set environment variables */
		return (0);
	return (1); /* if recursive call does not return a balanced value, it indicates an error */
}

/**
 * _unsetenvValue - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _unsetenvValue(info_t *info)
{
	int s;

	if (info->argc == 1)
	{
		_writeError(".\n");
		return (1);
	}
	for (s = 1; s <= info->argc; s++)
		_unsetenvValue(info, info->argv[s]);

	return (0);
}

/**
 * overrun_env - populates env linked list
 * @info: Structure containing arguments for maintaining
 *          constant function prototype.
 * Return: Always 0
 */
int overrun_env(info_t *info) /* function declaration */
{
	list_t *node = NULL; /* declaration and initialization of pointer */
	size_t s; /* variable declaration, used for sizes and indices */

	for (s = 0; environ[s]; s++) /* initiates loop that iterate over environ unti null */
		add_node_end(&node, environ[s], 0); /* adds new intersections to the end pf the list */
	info->env = node; /* assign link list to the info structure */
	return (0); /* successful execution */
}
