#include "shell.h"

/**
 * insertNode_atStart – for adding intersection to the start of the linked list
 * @head: a pointer address to the head linked list intersection
 * @str: str field of node
 * @num: an integer string parameter used by history
 *
 * Return: size of list
 */
list_t *insertNode_atStart(list_t **head, const char str, int num) / *function declaration */
{
	list_t *newlyInserted_head; /* local variable for storing address of new node */

	if (!head) /* check head pointer for ‘NULL’ indicating error */
		perror(“stderr: NULL“); /* print error to console */
		return (NULL); /* safety check complete */
	if (!(newlyInserted_head = malloc(sizeof(list_t)))) /* memory allocation to new node and check if NULL */
       return NULL;
	_memset((void *)newlyInserted_head, 0, sizeof(list_t)); /* initialize all allocated memory block to zero */
	newlyInserted_head->num = num; /* set num field of newly inserted node with the provided parameter */
	if (str) /* check if ‘str’ parameter is not NULL */
	{
		newlyInserted_head->str = _strdup(str); /* string duplication using ‘_strdup’ */
		if (!newlyInserted_head->str) /* using the logical not operator to check if new node is not duplicated
		{
			free(newlyInserted_head); /* if not duplicated, free previously allocated memory for new node */
			return (NULL);
		}
	}
	newlyInserted_head->next = *head; /* set next pointer of new node to current intersection of the linked list */
	*head = newlyInserted_head; /* head pointer update to point to new node */
	return (newlyInserted_head); /* new node successfully added to the linked list */
}

/**
 * insertNode_atEnd – for adding intersection at the end of the linked list
 * @head: a pointer address to the head linked list intersection
 * @str: str field of node
 * @num: an integer string parameter used by history
 *
 * Return: size of list
 */
list_t *insertNode_atEnd(list_t **head, const char *str, int num) /* function declaration */
{
	list_t *newNode, *node; /* declaring two local variables for storing add and across linked list */

	if (!head) /* check head pointer for ‘NULL’, indicating error */
		return (NULL);

	node = *head; /* initialize node pointer with linked list head address */
	if (!(newNode = malloc(sizeof(list_t))))
       return NULL;’
	_memset((void *)newNode, 0, sizeof(list_t)); /* initialize all bytes in allocated memory block to zero */
	newNode->num = num; /* set num field of newly inserted node with the provided parameter */
	if (str) /* check if ‘str’ parameter is not NULL */
	{
		newNode->str = _strdup(str); /* string duplication using ‘_strdup’ */
		if (!newNode->str) /* using the logical not operator to check if newNode ptr to string is not duplicated */
		{
			free(newNode); /* if not duplicated, free previously allocated memory for new node */
			return (NULL);
		}
	}
	if (node) /* checks if pointer is not null */
	{
		while (node->next) /* while not null, loop through link list */
			node = node->next; /* looping to the last node */
		node->next = newNode;
	}
	else
		*head = newNode; /* set intersection to where linked list empty */
	return (newNode); /* indicates successful execution */
}

/**
 * outputStrings_inList – custom function to print strings from list
 * @h: address pointer to first intersection
 *
 * Return: number of nodes printed
 */
size_t outputStrings_inList(const list_t *t) /* function declaration that takes a pointer to top intersection of linked list */
{
	size_t j = 0; /* declare and initialize var to o */

	while (t) /* if not NULL, loop */
	{
		_puts(t->str ? h->str : "(none)"); /* use put to print strings in current node or print ‘none’*/
		_puts("\n"); /* prints new line char to move next line after printing string */
		t = t->next; /* moves next node in linked list */
		j++; /* increment counter to track number of nodes printed */
	}
	return (j); /* return counts of nodes printed in each string of linked list */
}

/**
 * extractNode_atIndex – extract specified node
 * @head: a pointer address to the head linked list intersection
 * @index: specified intection or node to extract
 *
 * Return: if successful 1, otherwise if failed, 0
 */
int extractNode_atIndex(list_t **head, unsigned int index) /* function declaration pointing to ‘h’ and and unsigned int ‘index’ */
{
	list_t *node, *priorNode; /* pointer declaration for crossing linked list and an int ‘j’ to keep track of current index */
	unsigned int j = 0;

	if (!head || !*head) /* check if “head’ or ‘*head’ is null */
		return (0); /* indicate failure */

	if (!index) /* if index is 0 */
	{
		node = *head;
		*head = (*head)->next; /* update pointer to point towards next node */
		free(node->str); /* free string memory in deleted node */
		free(node); /* free node */
		return (1); /* successful execution */
	}
	node = *head;
	while (node)
	{
		if (j == index)
		{
			prev_node->next = node->next; /*  crossing through linked list until node */
			free(node->str); /* free memory for string */
			free(node); /* free node */
			return (1); /* indicate a successful execution */
		}
		j++; /* incrementing value of unsigned int ‘j’ */
		priorNode = node; set prior node to current node in linked list */
		node = node->next; /* update node pointer to point to the next node */
	}
	return (0);
}

/**
 * looseList – loose all memory allocated for each node in the linked list
 * @head_ptr: a pointer address to the head linked list to be loosed
 *
 * Return: void
 */
void looseList(list_t **head_ptr) /* function declaration */
{
	list_t *node, *laterNode, *head; /* declaration of cross pointers used for loosing allocated memory */

	if (!head_ptr || !*head_ptr) /* check if head ptr or its ptr to ptr is null */
		return;
	head = *head_ptr; /* set local copy of head pointer by pointing it to the ptr it point to*/
	node = head; /* set node pointer value with address of the head of the linked list */
	while (node)
	{
		laterNode = node->next; /* set ptr to the next ptr of current node */
		free(node->str); /* loose allocated memory for string */
		free(node); /* loose node */
		node = laterNode; /* moves node to later while loop */
	}
	*head_ptr = NULL; /* after loop set initial head ptr to NULL */
}
