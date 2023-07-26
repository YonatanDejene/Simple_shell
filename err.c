#include "shell.h"

/**
 * error - Display error massage.
 * @name: File name.
 * @cmd_name: Command.
 *
 * Return: Void.
 */
void error(char *name, char *cmd_name)
{
	char *error = ": not found\n";
	int k;

	for (k = 0; name[k] != '\0'; k++)
		_putchar(name[k]);
	_putchar(':');
	_putchar(' ');
	_putchar('1');

	_putchar(':');
	_putchar(' ');
	rmv_string(cmd_name);
	for (k = 0; cmd_name[k] != '\0'; k++)
		_putchar(cmd_name[k]);
	for (k = 0; error[k] != '\0'; k++)
		_putchar(error[k]);
}

/**
 * stw - Checks substring’s index in the string.
 * @strng: String.
 * @sub: String.
 * @index: Index.
 *
 * Return: 0 or 1
 */
int stw(const char *strng, const char *sub, int index)
{
	int length = _strlen(sub);
	int k;

	for (k = 0; k < length; k++)
	{
		if (str[k + index] != sub[k])
		{
			return (0);
		}
	}
	return (1);
}

/**
 * rmv_string - Rmv bin.
 * @str: String to be edited.
 *
 * Return: Void
 */
void rmv_string(char *str)
{
	char *sub = "/bin/";
	int length = _strlen(str);
	int sub_length = _strlen(sub);
	int k, l;

	for (k = 0, l = 0; k < length; k++)
	{
		if (stw(str, sub, k))
		{
			k += sub_length - 1;
		}
		else
		{
			str[l++] = str[k];
		}
	}
	str[l] = '\0';
}
