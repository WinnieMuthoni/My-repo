#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	forn info[] = { FORN_INIT };
	int num = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (num)
			: "r" (num));

	if (ac == 2)
	{
		num = open(av[1], O_RDONLY);
		if (num == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Cannot open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readnum = num;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
