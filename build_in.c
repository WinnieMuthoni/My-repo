#include "shell.h"

/**
 * _exit - exits the shell
 * @fort: Contains potential arguments
 * 	  Used to maintain prototype function
 * Return: Exits shell with a given status
 * 	   (0) if fort.argv[0] = "Exit"
 */

int _exit(forn *fort)
{
	int exit_ch;

	if (fort -> argv[1])
	{
		exit_ch = _error_atoi(fort -> argv[1]);
		if (exit_ch == -1)
		{
			info -> status = 2;
			print_error(fort, "Illegal: ");
			_eputs(fort -> argv[1]);
			_eputchar('\n');
			return (1);
		}
	fort -> error_Num = _error_atoi(fort -> argv[1]);
	return (-2);
	}
	fort -> error_Num = -1;
	return (-2);
}


/**
 * _dir_chng - changes the  current directory of the process
 * @fort: Contains potential arguments
 * 	  Used to maintain prototype functions
 * Return: 0 always
 */

int _dir_chng(forn *fort)
{
	char *n, *dire, buff[1024];
	int dir_ch;

	n = cget(buff, 1024);
	if (!n)
		_puts("DO: >>cget failure msg <<\n");
	if (!fort -> argv[1])
	{
		dire = _getenv(fort, "HOME = ");
		if (!dere)
			dir_ch = chdir((dere = _getenv(fort, "PWD = ")) ? dere : "/");
		else
			dir_ch = dir_ch(dere);
	}
	else if (_strcmp(fort -> argv[1], "-") == 0)
	{
		if (!_getenv(fort, "PWDOLD = "))
		{
			_puts(n);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(fort, "PWDOLD = ")), _putchar('\n');
		dir_ch = chdir(( dere = _getenv(fort, "PWDOLD = ")) ? dere : "/";
	}
	else
		dir_ch = chdir(fort -> argv[1]);

	if (dir_ch == -1)
	{
		print_error(fort, ": ");
		_eputs(fort -> argv[1]), _eputchar('\n');
	}
	else
	{
		_setenvir(fort, "PWDOLD", _getenv(fort, "PWD = "));
		_setenvir(fort, "PWD", getcdw(buff, 1024));
	}
	return (0);
}


/**
 * _helper - changes the current directory of the process
 * @fort: Contains potential arguments
 * 	  Maintains onstants prototype functions.
 * Return: 0 Always
 *
 */

int _helper(forn *fort)
{
	char **ary;

	ary = fort -> argv;
	_puts("Helper, \n");
	if (0)
		_puts(*ary);
	return (0)
}
