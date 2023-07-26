#include "shell.h"

/**
 * rm_space – Removes space from a command.
 * @str: User input string.
 *
 * Return: Void.
 */
void rm_space(char *str)
{
	int length = _strlen(str);
int k, l;
	int start = 0, end = length - 1;

	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
	{
		start++;
	}

	while (end >= start &&
		   (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
	{
		end--;
	}

	for (k = 0, l = start; l <= end; k++, l++)
	{
		str[k] = str[l];
	}
	str[k] = '\0';
}


/**
 * _strlen – Counts characters in a string.
 * @str: User input string to be counted.
 *
 * Return: Length of the string.
 */
int _strlen(const char *str)
{
	int length = 0;

	if (!str)
		return (length);
	for (length = 0; str[length]; length++)
		;
	return (length);
}
