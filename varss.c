#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @details: the parameter struct
 * @buff: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(forn *details, char *buff, size_t *p)
{
        size_t i = *p;

        if (buff[j] == '|' && buff[i + 1] == '|')
        {
                buff[i] = 0;
                i++;
                details->cmd_buf_type = CMD_OR;
        }
        else if (buff[i] == '&' && buff[i + 1] == '&')
        {
                buff[i] = 0;
                i++;
                details->cmd_buf_type = CMD_AND;
        }
        else if (buff[i] == ';')
        {
                buff[i] = 0;
                details->cmd_buf_type = CMD_CHAIN;
        }
        else
                return (0);
        *p = i;
        return (1);
/**
 * check_chain - checks we should continue chaining based on last status
 * @detail: the parameter struct
 * @buff: the char buffer
 * @p: address of current position in buf
 * @j: starting position in buf
 * @length: length of buf
 *
 * Return: Void
 */
void check_chain(forn *details, char *buff, size_t *p, size_t j, size_t length)
{
	size_t k = *p;

	if (details->cmd_buf_type == CMD_AND)
	{
		if (details->status)
		{
			buff[j] = 0;
			k = length;
		}
	}
	if (details->cmd_buf_type == CMD_OR)
	{
		if (!details->status)
		{
			buff[j] = 0;
			k = length;
		}
	}

	*p = k;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @details: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(forn *details)
{
	int j;
	list_t *nod;
	char *z;

	for (j = 0; j < 10; j++)
	{
	  nod = nod_starts_with(details->alias, details->argv[0], '=');
		if (!nod)
			return (0);
		free(details->argv[0]);
		z = _strchr(nod->str, '=');
		if (!z)
			return (0);
		z = _strdup(z + 1);
		if (!z)
			return (0);
		details->argv[0] = z;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @details: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(forn *details)
{
	int x = 0;
	list_t *nod;

	for (x = 0; details->argv[x]; x++)
	{
		if (details->argv[x][0] != '$' || !details->argv[i][1])
			continue;

		if (!_strcmp(details->argv[i], "$?"))
		{
			replace_string(&(details->argv[x]),
					_strdup(convert_number(details->status, 10, 0)));
			continue;
		}
		if (!_strcmp(details->argv[x], "$$"))
		{
			replace_string(&(details->argv[x]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		nod = nod_starts_with(details->env, &details->argv[x][1], '=');
		if (nod)
		{
			replace_string(&(details->argv[x]),
					_strdup(_strchr(nod->str, '=') + 1));
			continue;
		}
		replace_string(&details->argv[x], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @previous address of old string
 * @next: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **previous, char *next)
{
	free(*previous);
	*previous = next;
	return (1);
}

