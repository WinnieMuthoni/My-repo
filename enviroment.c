#include "shell.h"

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

