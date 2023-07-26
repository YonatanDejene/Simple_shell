#include "shell.h"

/**
 * path2ls - Breaks and excute strings.
 * @cmd: User command.
 * @av: Arg vector.
 *
 * Return: 0 on success,
 * 1 Otherwise.
 */

int path2ls(char *cmd, char **av)
{
	int st = 0;
	int argc = 0;
	char *cmnd = NULL;
	char *tkn = NULL;
	char **argv2 = NULL;

	cmnd = malloc(sizeof(char *) * SIZE);

	cmnd = _strcpy(cmnd, "/bin/");
	cmnd = _strcat(cmnd, cmd);

	argv2 = malloc(sizeof(char *) * SIZE);

	tkn = strtok(cmnd, LINE_DELIM);
	argv2[0] = tkn;
	while (tkn)
	{
		argc++;
		tkn = strtok(NULL, LINE_DELIM);
		argv2[argc] = tkn;
	}
	argv2[argc] = NULL;

	st = execute(argc, argv2, av);
	free(cmnd);
	free(argv2);
	return (st);
}

/**
 * path_ls2bin - Exec str.
 * @cmd: User command.
 * @av: Arg vector.
 *
 * Return: 0 on success
 * 1 if not.
 */

int path_ls2bin(char *cmd, char **av)
{
	int argc = 0;
	int st = 0;

	char *tkn = NULL;
	char **argv = NULL;

	argv = malloc(sizeof(char *) * SIZE);

	tkn = strtok(cmd, LINE_DELIM);
	argv[0] = tkn;
	while (tkn)
	{
		argc++;
		tkn = strtok(NULL, LINE_DELIM);
		argv[argc] = tkn;
	}
	argv[argc] = NULL;
	st = execute(argc, argv, av);
	free(argv);
	return (st);
}
