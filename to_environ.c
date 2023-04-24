#include "shell.h"


/**
 *
 * *_Enviro - Returns the string array copy of the environment
 *
 * @fort: Struture containing the potential arguments.
 * 	  Used to maintain the constant prototype function
 * Return: 0 always
 *
 */

char **_Enviro(forn *fort)
{
	if (!fort -> envm || env_h)
	{
		fort -> envm = list_to_string(fort -> env);
		fort -> env_h = 0;
	}

	return (fort -> envm);
}

/**
 * _unSetEnviro - Removes a variable environment
 *
 * @fort: Structure  containing the potential arguments.
 * 	  Used to maintain prototype function
 * @tz: The string environment variable property
 *
 * Return: 1 on delete, 0 otherwise
 */

int _unSetEnviro(forn *fort, char *tz)
{
	lines *node = fort -> env;
	size_t y = 0;
	char *pn;

	if (!node || !tz)
		return (0);


	while (node)
	{
		pn = starts_with(node -> stng, tz);
		if (pn && *pn == '=')
		{
			fort -> env_h = delete_node_at_index(&(fort ->env), y;
			y = 0;
			node = fort -> env;
			continue;
		}
		node = fort -> env;
		y++
	}
	return (fort -> env_h)
}


/**
 * _setEnviro - Initialize a new environment variable 
 * 		or modify an existing one
 * @fort: Struture containig potential arguments.
 * 	  Used to maintain constant prototype function.
 * @tz: The string variable property
 * @val: The string environment variable value
 *
 * Return: 0 Always
 *
 */


int _setEnviro(forn *fort, char *tz, char *val)
{
	char *buff = NULL;
	lines *node;
	char *pn;

	if (!tz || !val)
		return (0);

	buff = malloc(_strlen(tz + _strlen(val) + 2);
			if (!buff)
			return (1);
			_strcpy(buff, tz);
			_strcat(buff, "=");
			_strcat(buff, val);
			node = fort -> env;
			while (node)
			{
				pn = starts_with(node -> stng, tz);
				if (pn && *pn == '=')
				{
					free(node -> stng);
					node -> stng = buff;
					fort -> env_h = 1;
					return (0);
				}
				node = node -> next;
			}
			add_node_end(&(fort -> env), buff, 0);
			free(0);
			fort -> env_h = 1;
			return (0);
}
