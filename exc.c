#include "shell.h"

/**
 * execute – Exc func.
 * @argc: Input int.
 * @argument: Command.
 * @av: Arg Vector.
 *
 * Return: 0 on success.
 * 1 if pid is different from 0.
 */

int execute(int argc, char **argument, char **av)
{
	int status;
	pid_t pid;
	char *cm = argument[0];

	if (argc > 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(cm, argument, environ) == -1)
			{
				free(argument);
				error(av[0], cm);
				exit(127);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
			{
				exit(127);
			}
			free(argument);
			return (1);
		}
	}
	return (0);
}
