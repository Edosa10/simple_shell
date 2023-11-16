#include "shell.h"

/**
 * getEnvironment – retrieves stored informations about our environment
 * @info: const char pointer containing possible arguments.
 * Return: Always 0
 */
char **getEnvironment(info_t *info) /* function declaration */
{
	if (!info->Environment || info->env_changed) /* checking environment field or ‘env_changed’ flag */
	{
		info->Environment = list_to_strings(info->env); /*if true, convert linked list ‘env’ and assign result to ‘Environment’ */
		info->env_changed = 0; /* reset flag to 0 */
	}

	return (info->Environment);
}

/**
 * _unsetenv – custom function set for removing an environment variable
 * @info: pointer of type info_t containing possible arguments
 *  Return: 1 on delete, 0 if no change was made
 * @var: string env data type
 */
int _unsetEnvironment_variable(info_t *info, char *var)
{
	list_t *node = info->env; /* initialize pointer to linked list head stored in ‘env’ field of struct ‘info’ */
	size_t j = 0; /* initialize current linked list index variable to 0 */
	char *p; /* temporary memory pointer declaration */

	if (!node || !var) /* check for either linked list nor var */
		return (0); /* indicating no changes was made */

	while (node) /* loop through env linked list */
	{
		p = right_prefix(node->str, var); /* check if linked list current var begins with the specified prefix */
		if (p && *p == '=') /* check for match and if *p is matched, indicating var match */
		{
			info->env_changed = delete_node_at_current_index(&(info->env), j);
			j = 0; /* reset index to 0 */
			node = info->env; /* reset node pointer to linked list head */
			continue; /* continue loop’s next iteration */
		}
		node = node->next; /* node pointer moved to linked list next node */
		j++;
	}
	return (1);
}

/**
 * _setUp_env – custom function for setting or updating env in a linked list
 * @info: pointer of type info_t containing possible arguments
 * @var: string env var data type
 * @value: value of the string env
 *  Return: Always 0
 */
int _setUp_env(info_t *info, char *var, char *value)
{
	char *buf = NULL; /* variable declaration of pointer set to NULL*/
	list_t *node; /* declaration of linked list node pointer of type list_t */
	char *p; /* temporary memory pointer declaration */

	if (!var || !value) /* checks for either var name or value */
		return (0); /* no changes made indicator */

	buf = malloc(_strlen(var) + _strlen(value) + 2); /* memory allocation for ‘buf’ based on length of var name and value plus memory provision for ‘=’ and NULL terminator */
	if (!buf) /* check for malloc success */
		/* perror(“malloc”); */ /* handling error */
		return (1); /* malloc failure */
	_strcpy(buf, var); /* copying var name to buf */
	_strcat(buf, "="); /* chain ‘=’ to buf */
	_strcat(buf, value); /* chain variable ‘value’ to buf */
	node = info->env; /* set node pointer to head of linked list stored in the env field of ‘info’ structure */
	while (node) /* begin loop that iterate through linked list of env */
	{
		p = right_prefix(node->str, var); /* check if linked list current var begins with the specified prefix */
		if (p && *p == '=') /* check for match and if *p is matched, indicating complete var match */
		{
			free(node->str); /* deallocate existing string stored in the linked list */
			node->str = buf; /* update linked list buf with the data of ‘var’, ‘=’, and ‘value’ */
			info->env_changed = 1; /* ‘env_changed set to 1 indicating successful change */
			return (0); /* success indication */
		}
		node = node->next; /* move node pointer to the next node in the linked list */
	}
	append_node(&(info->env), buf, 0); /* add new node ‘buf’ to end of linked list if var doesn’t exist */
	free(buf); /* free buf after memory deallocation to linked list */
	info->env_changed = 1; /* set flag to one, indicating an environment change */
	return (0); /* indicate a successful execution of this block */
}
