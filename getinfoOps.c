#include "shell.h"

/**
 * clear_data - initializes info_t struct
 * @info: program struct address
 */
void clear_data(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->argc = 0
	info->path = NULL;
}

/**
 * setup_info - initializes program info_t struct
 * @info: program address struct
 * @av: argument vector
 */
void setup_info(info_t *info, char **av) /* function declaration */
{
	int j = 0; /* declaration and initialization of integer variable */

	info->fname = av[0]; /* assigning value */
	if (info->arg) /* checking for arguments */
	{
		info->argv = strtow(info->arg, " \t"); /* start tokenizing if arguments is not null */
		if (!info->argv) /* check tokenization failure */
		{

			info->argv = malloc(sizeof(char *) * 2); /* memory allocation for an array of two pointers */
			if (info->argv) /* check malloc success */
			{
				info->argv[0] = _strdup(info->arg); /* duplicates elements of first contents */
				info->argv[1] = NULL; /* set second element to NULL */
			}
		}
		for (j = 0; info->argv && info->argv[j]; j++) /* set loop until null */
			;
		info->argc = j; /* assigning count value to argument count */

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * freeInfo - deallocate program info_t struct fields memory
 * @info: program struct address
 * @all: int parameter for freeing all resources
 */
void freeInfo(info_t *info, int all) /* program function prototype */
{
	ffree(info->argv); /* ‘info->argv’ memory deallocation */
	info->argv = NULL; /* deallocated memory set to NULL */
	info->path = NULL; /* deallocated memory path set to NULL */
	if (all) /* checking all parameters for additional memory deallocation */
	{
		if (!info->cmd_buf) /* check if ‘cmd_buf’ pointer of type ‘info’ is null */
			free(info->arg); /* if yes? Deallocate string using free */
		if (info->env) /* check to free environment variables or not */
			freeList(&(info->env)); /* deallocate env linked list memory with a custom function */
		if (info->history) /* check if ‘info->history’ is a NULL pointer */
			freeList(&(info->history)); /* if not NULL, deallocate linked list memory with a custom function */
		if (info->alias) /* check to free alias list if not a NULL pointer */
			freeList(&(info->alias)); /* deallocating alias linked list with a custom function ‘freeList */
		ffree(info->environ); /* free ‘info->environ’ memory using custom ‘ffree’ function */
			info->environ = NULL; /* set deallocated memory pointer to NULL */
		bfree((void **)info->cmd_buf); /* set ‘info->cmd_buf’ to void and deallocate memory using custom function ‘bfree’ */
		if (info->readfd > 2) /* check if pointer to a file descriptor is greater than 2 */
			close(info->readfd); /* if yes? Closes file descriptor */
		_putchar(BUF_FLUSH);
	}
}
