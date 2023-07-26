#include "shell.h"

/**
 * main - Simple shell.
 * @av: Arg Vector.
 * @ac: Arg Count.
 *
 * Return: Zero when success.
 */

int main(int ac, char *av[])
{
	int st = 0;
	char *command = NULL;
	size_t n = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		if (getline(&command, &n, stdin) == -1)
		{
			free(command), exit(st);
		}
		rm_space(command);
		if (_strlen(command) == 0)
			continue;

		if (bltin(command) == 1)
			continue;

		else if (bltin(command) == 0)
			free(command), exit(st);
		if (ac > 0 && _strncmp(command, "/bin/", 5) == 0)
		{
			st = path_ls2bin(command, av);
			if (st > 0)
			{
				if (_strncmp(cmd, "/bin/ls", 7) == 0)
					st = 2;
				else st = 127;
			}
		}
		else if (ac > 0 && _strncmp(command, "/bin/", 5) != 0)
		{
			st = path2ls(command, av);
			if (st > 0)
				st = 127;
		}
	}
	return (0);
}
