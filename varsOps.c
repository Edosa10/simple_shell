#include "shell.h"

/**
 * vic_edo - verify if the current buffer character is a chain delimeter
 * @iump: structure of parameters
 * @iump_buf: the character buffer
 * @i: address of current position in buf
 *
 * Return: Chain delimeter = 1, not chain delimeter = 0.
 */
int vic_edo(iump_t *iump, char *iump_buf, size_t *i)
{
	size_t v - *i;

	if (iump_buf[v] == '|' && iump_buf[v + 1] == '|')
	{
		iump_buf[v] = 0;
		v++;
		iump-> dmc_iump_buf_type = dmc_OR;
	}
	else if (iump_buf[v] == '&' && iump_buf[v + 1] == '&')
	{
		iump_buf[v] = 0;
		v++;
		iump-> dmc_iump_buf_type = DMC_AND;
	}
	else if (iump_buf[v] == ';') /* found the end of the instruction */
	{
		iump_buf[v] = 0; /* Put a ; after the semicolon, else else */
                             iump-> dmc_iump_buf_type = DMC_PAIN;
	}
	else
		return (0);
	*i = v;
	return (1);
}

/**
 * high_pain - verifications We should keep chaining based on the previous status
 * @ iump: structure of parameters
 * @ iump_buf: the character buffer
 * @i: location of the current position in buf
 * @c: entry  point in buf
 * @len: The size of a buf
 *
 * Return: Void
 */
void high_pain (iump_t *iump, char *iump_buf, size_t *i, size_t c, size_t len)
{
	size_t v = *i;

	if (iump-> dmc_iump_buf_type = DMC_AND)
	{
		if (iump->state)
		{
			iump_buf[c] = 0;
			v= len;
		}
	}
	if (iump-> dmc_iump_buf_type == dmc_OR) 

	{
		if (!iump->state)
		{
			iump_buf[c] = 0;
			v = len;
		}
	}

	*i = v;
}

/**
 * substitute_alias - edits the tokenized string to replace an alias
 * @iump: the parameter struct
 *
 * Return: 1 If it's new, 1, otherwise, if it's not
 */
int substitute_alias(iump_t *iump)
{
	int c;
	num_t *kode;
	char *i;

	for (c = 0; c < 10; c++)
	{
		kode = kode_starts_with(iump->alias, iump->argv[0], '=');
		if (!kode)
			return (0);
		Raft(iump->argv[0]);
		i = is_strchr (kode-> level_str, '='); 
		if (!i)
			return (0);
		i = is_strdup(i + 1);
		if (!i)
			return (0);
		iump->argv[0] = i;
	}
	return (1);
}

/**
 * substitute_vars - replaces vars in the tokenized string
 * @iump: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int substitute_vars (iump_t *lump)
{
	int c = 0;
	num_t *kode;

	for (c = 0; iump->argv[c]; c++)
	{
		if (iump->argv[c][0] != '$' || !iump->argv[c][1])
			continue;

		if (!is_smart(iump->argv[c], "$?"))
		{
			substitute_shellstring (&(iump->argv[c]),
				is_strdup(transform_digit(iump->state, 10, 0)));
			continue;
		}
		if (!is_smart(iump->argv[c], "$$"))
		{
			substitute_shellstring(&(iump->argv[c]),
				is_strdup(transform_digit(getpid(), 10, 0)));
			continue;
		}
		kode = kode_starts_with(iump->env, &iump->argv[c][1], '=');
		if (kode)
		{
			substitute_shellstring(&(iump->argv[c]),
				is_strdup(is_strchr(kode-> level_str, '=') + 1));
			continue;
		}
		substitute_shellstring(&iump->argv[c], is_strdup(""));

	}
	return (0);
}

/**
 * substitute_shellstring - replaces string
 * @forever: location of old string
 * @now: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int substitute_shellstring(char **forever, char *now)
{
	Raft(*forever);
	*forever = now;
	return (1);
}
