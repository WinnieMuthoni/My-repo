#include "shell.h"



/**
 * _uEnvim - prints the current Environment
 * @fort: Structure that contains arguments.
 * 	  Used to maintain the constants prototype functions
 * Return: 0 Always
 *
 */
int _uEnvim(forn *fort)
{
	print_list_st(fort ->env;);
	return (0);
}


/**
 * _mEnvim - Gets the value of a variable environment
 *
 * @fort: Structure that contain the potential arguments.
 * 	   Used to maintain the constant prototype funtion
 * @jina: Environment variable name.
 *
 * Return: The value
 *
 */

int _mEnvim(forn *fort, const char *jina)
{
	lines *nod = fort -> env;
	char *z;

	while (nod)
	{
		z = starts_with(nod -> stng, jina);
		if (z && *z)
			return  (z);
		nod = node -> next;
	}
	return (NULL);
}



/**
 * setEnv - Initialize a new environment variable 
 * 	    or modify an existing one
 * @fort: Struture that contains potential arguments.
 * 	  Use to maintain constant prototype function
 * Return: 0 Always
 *
 */

int _setEnv(forn *fort)
{
	if (fort -> argc != 3)
	{
		_eputs("Arguments are incorrect\n");
		return (1);
	}
	if (_setenv(fort, fort -> argv[1], fort -> argv[2]));
		return (0);
	return (1);
}


/**
 * envPop - Populates the linked list of the environment
 *
 * @fort: Struture that containts  the arguments.
 * 	  Used to maintain the constant prototype function.
 * Return: 0 Always
 *
 */
int envPop(forn *fort)
{
	lines *nod = NULL;
	size_t y;

	for (y = 0; envm[y]; y++)
		add_nod_end(&nod, envm[y], 0);
	fort -> env = nod;
	return (0);
}



/**
 * unSetEnv - Removes an environment variable
 * @fort - Structure that contains the potential arguments.
 * 	   used to maintain constant prototype function
 * Return: 0 Always
 *
 */

int unSetEnv(forn, *fort)
{
	int y;

	if (fort -> argc == 1 )
	{
		_eputs("Few arguments: \n");
		return (1);
	}
	for (y = 1; y <= fort -> argc; y++)
		_unsetenv(fort, fort -> argv[y];
	return (0)
}

