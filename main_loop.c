#include "shell.h"

/**
 * hsh - main shell loop
 * @details: the parameter & return info struct
 * @vector: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(forn *details, char **vector)
{
	ssize_t z = 0;
	int buildin_ret = 0;

	while (z != -1 && buildin_ret != -2)
	{
		clear_details(details);
		if (interactive(details))
			_puts("$ ");
		_eputchar(BUFF_FLUSH);
		z = get_input(details);
		if (z != -1)
		{
			set_details(details, vector);
			buildin_ret = find_buildin(details);
			if (buildin_ret == -1)
			  find_cmd(details);
		}
		else if (interactive(details))
			_putchar('\n');
		free_details(details, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (details->err_num == -1)
			exit(details->status);
		exit(details->err_num);
	}
	return (buildin_ret);
}

/**
 * find_builtin - finds a builtin command
 * @details: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 * 	0 if builtin executed successfully,
 * 	1 if builtin found but not successful,
 * 	2 if builtin signals exit()
 */
int find_builtin(forn *details)
{
	int i, build_in_ret = -1;
	buildin_table buildintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			details->line_count++;
			build_in_ret = buildintbl[i].func(details);
			break;
		}
	return (build_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @details: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(forn *details)
{
	char *p = NULL;
	int k, j;

	details->p = details->argv[0];
	if (details->linecount_flag == 1)
	{
		details->line_count++;
	        details->linecount_flag = 0;
	}
	for (k = 0, j = 0; details->arg[k]; k++)
		if (!is_delim(details->arg[i], " \t\n"))
			j++;
	if (!j)
		return;

	p = find_path(details, _getenv(details, "PATH="), details->argv[0]);
	if (p)
	{
		details->path = path;
		fork_cmd(details);
	}
	else
	{
		if ((interactive(details) || _getenv(details, "PATH=")
					|| details->argv[0][0] == '/') && is_cmd(details, details->argv[0]))
			fork_cmd(details);
		else if (*(details->arg) != '\n')
		{
			details->status = 127;
			print_error(details, "not available\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @details: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(forn *details)
{
	pid_t children_pid;

	children_pid = fork();
	if (children_pid == -1)
	{
		
		perror("Error:");
		return;
	}
	if (children_pid == 0)
	{
	  if (execve(details->path, details->argv, get_environ(details)) == -1)
		{
			free_details(details, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		
	}
	else
	{
		wait(&(details->status));
		if (WIFEXITED(details->status))
		{
			details->status = WEXITSTATUS(details->status);
			if (details->status == 126)
				print_error(info, "Access denied\n");
		}
	}
}
