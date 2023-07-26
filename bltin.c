#include "shell.h"

/**
 * bltin – Distinguish bn exit and env commands.
 * @command: User command.
 *
 * Return: Error number if exit,
 * 1 If print env,
 * 2 On success.
 */

int bltin(char *command)
{
	if (_strncmp(command, "env", 3) == 0)
	{
		p_env();
		return (1);
	}

	if (_strncmp(command, "exit", 4) == 0)
	{
		return (0);
	}

	return (2);
}

/**
 * p_env - Prints env.
 *
 * Return: Void.
 */

void p_env(void)
{
	int k = 0;
	int l = 0;

	while (environ[k] != NULL)
	{
		l = 0;
		while (environ[k][l] != '\0')
		{
			_putchar(environ[k][l]);
			l++;
		}
		_putchar('\n');
		l++;
	}
}
