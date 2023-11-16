#include "shell.h"

/**
 * input_buf - chained commands input
 * @info: state of program struct parameter
 * @buf: address of memory region
 * @len: address of command length variable
 *
 * Return: number of bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t bytesTaken = 0;
	size_t len_p = 0;

	if (!*len)
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, handleSigint);
#if USE_GETLINE
		bytesTaken = getline(buf, &len_p, stdin);
#else
		bytesTaken = _getline(info, buf, &len_p);
#endif
		if (bytesTaken > 0)
		{
			if ((*buf)[bytesTaken - 1] == '\n')
			{
				(*buf)[bytesTaken - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = bytesTaken;
				info->cmd_buf = buf;
			}
		}
	}
	return (bytesTaken);
}

/**
 * get_input – acquire line less newline
 * @info: state of program struct parameter
 *
 * Return: length of current command
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* storing command chain separated by ‘;’ */
	static size_t s, e, len; /* keep track of position and length in buffer */
	ssize_t r = 0; /* ‘r’ signed data type for storing return value */
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH); /* flushing buffer */
	r = input_buf(info, &buf, &len); /* reading buffer input */
	if (r == -1) /*No input in buffer, initiate EOF */
		return (-1);
	if (len)	/* command input in buffer */
	{
		e = s; /* initialize variable iterators through buf inputs */
		p = buf + s;

		check_chain(info, buf, &e, s, len);
		while (e < len) /* iterate till semicolon or EOF */
		{
			if (is_chain(info, buf, &e))
				break;
			e++;
		}

		s = e + 1; /* incrementing past ';' */
		if (s >= len) /* end of buffer length? */
		{
			s = len = 0; /* anew position and length at end of buf */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* correct pointer to point towards current command */
		return (_strlen(p)); /* return current command length stored in p variable */
	}

	*buf_p = buf;
	return (bytesTaken); /* return entire buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @info: state of program struct parameter
 * @buf: buffer
 * @s: size
 *
 * Return: bytes taken
 */
ssize_t read_buf(info_t *info, char *buf, size_t *s)
{
	ssize_t bytesTaken = 0;

	if (*s)
		return (0);
	bytesTaken = read(info->readfd, buf, READ_BUF_SIZE);
	if (bytesTaken >= 0)
		*s = bytesTaken;
	return (bytesTaken);
}

/**
 * _getline – read the next line of text from stdin
 * @info: state of program struct parameter
 * @ptr: pointer address to dynamic buffer, preset or NULL
 * @length: preset ptr buffer size if not NULL
 *
 * Return: l - current length of line
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len; /* static variables keeping track of current position and length in buffer */
	size_t k; /* variable ‘k’ of type ‘size_t’ declaration */
	ssize_t bytesTaken = 0, l = 0; /* variables declaration and initialization */
	char *p = NULL, *np = NULL, *t; /* pointers declared and set to NULL */

	p = ptr; /* set pointer value */
	if (p && length) /* conditional statement checking for ‘p’ and length */
		l = *length; /* set ‘l’ to the value of ‘*length’ */
	if (s == len) /* checking if current position is equal to ‘len’ */
		s = len = 0; /* reset position ‘s’ and ‘len’ to 0 */

	bytesTaken = read_buf(info, buf, &len); /* calling ‘read_buf” function */
	if (bytesTaken == -1 || (bytesTaken == 0 && len == 0)) /* checking for error or end of input */
		perror(“_getline”); /* Handling error */
		return (-1);

	t = _strchr(buf + s, '\n'); /* seeking first occurrence of new line character in buffer starting from ‘s’ */
	k = t ? 1 + (unsigned int)(t - buf) : len; /* if newline? calculating current position distance or set ‘size_t to length of buffer */
	np = _realloc(p, l, l ? l + k : k + 1);
	if (!np) /* Malloc failure */
		perror(“malloc”); /* handle malloc failure error */
		return (p ? free(p), -1 : -1); /* not NULL? Free memory before returning */

	if (l) /* check for input or content in the length of line */
		_strncat(np, buf + s, k - s); /* chain buffer substring */
	else
		_strncpy(np, buf + s, k - s + 1);

	l += k - s;
	s = k;
	p = np;

	if (length)
		*length = l;
	*ptr = p;
	return (l);
}

/**
 * handleSigint - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n"); /* print a new line */
	_puts("$ "); /* print a shell prompt ‘$’ */
	_putchar(BUF_FLUSH); /* flush buffer */
}
