#include "shell.h"



/**
 * _help - changes the current directory of the process
 * @fort: Contains potential arguments. Maintains constants prototype functions
 * Return: 0 Always
 *
 */

int _help(forn *fort)
{
	char **ary;

	ary = fort->argv;
	puts("Helper, \n");
	if (0)
		_puts(*ary);
	return (0);
}


/**
 * _mexit - exits the shell
 * @fort: Contains potential arguments. Used to maintain prototype function
 * Return: Exits shell with a given status
 * 	(0) if fort.argv[0] = "Exit"
 */

int _mexit(forn *fort)
{
	int exit_ch;

	if (fort->argv[1])
	{
		exit_ch = _erratoi(fort->argv[1]);
		if (exit_ch == -1)
		{
			fort->status = 2;
			print_error(fort, "Illegal: ");
			_eputs(fort->argv[1]);
			_eputchar('\n');
			return (1);
		}
	fort->error_Num = _erratoi(fort->argv[1]);
	return (-2);
	}
	fort->error_Num = -1;
	return (-2);
}


/**
 * _cd - changes the  current directory of the process
 * @fort: Contains potential arguments. Used to maintain prototype functions
 * Return: 0 always
 */

int _cd(forn *fort)
{
	char *n, *dire, buff[1024];
	int dir_ch;

	n = getcwd(buff, 1024);
	if (!n)
		_puts("Failure: \n");
	if (!fort->argv[1])
	{
		dire = _getenv(fort, "HOME is = ");
		if (!dire)
			dir_ch = chdir((dire = _getenv(fort, "PWD = ")) ? dire : "/");
		else
			dir_ch = chdir(dire);
	}
	else if (_strcmp(fort->argv[1], "-") == 0)
	{
		if (!_getenv(fort, "PWDOLD = "))
		{
			_puts(n);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(fort, "PWDOLD = ")), _putchar('\n');
		dir_ch = chdir((dire = _getenv(fort, "PWDOLD = ")) ? dire : "/");
	}
	else
		dir_ch = chdir(fort->argv[1]);

	if (dir_ch == -1)
	{
		print_error(fort, ": ");
		_eputs(fort->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(fort, "PWDOLD", _getenv(fort, "PWD = "));
		_setenv(fort, "PWD", getcwd(buff, 1024));
	}
	return (0);
}

