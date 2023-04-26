#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @details: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(forn *details, char *path)
{
	struct stat z;

	(void)details;
	if (!path || stat(path, &z))
		return (0);

	if (z.z_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @runstr: the PATH string
 * @initializer: starting index
 * @end: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *runstr, int initializer, int end)
{
	static char buf[1024];
	int j = 0, f = 0;

	for (f = 0, j = intializer; j < end; j++)
		if (runstr[j] != ':')
			buf[f++] = runstr[j];
	buf[f] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @details: the info struct
 * @runstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(forn *details, char *runstr, char *cmd)
{
	int k = 0, curry_pos = 0;
	char *path;

	if (!runstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(details, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!runstr[k] || runstr[k] == ':')
		{
			path = dup_chars(runstr, curry_pos, k);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(details, path))
				return (path);
			if (!runstr[i])
				break;
			curry_pos = k;
		}
		k++;
	}
	return (NULL);
}
