#include "shell.h"

/**
 * _strncmp - Compares Strings.
 * @str1: 1st string to be compared.
 * @str2: 2nd string to be compared.
 * @n: Max number of chars to be compared.
 *
 * Return: positive if str1 > str2
 * Negative if str1 < str2
 * 0 if both are equal
 */
int _strncmp(char *str1, char *str2, int n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
			return ((*str1) - (*str2));

		else if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

/**
 * _putchar - Writes the character C.
 * @c: Character to be written.
 *
 * Return: 1 if success.
 * On error, -1.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * prompt - prompts '$'
 *
 * Return: none.
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}


/**
 * _strcat - Concatenates src to dest.
 * @src: Source string.
 * @dest: Destination string.
 *
 * Return: The pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int count = 0, count2 = 0;

	while (dest[count] != '\0')
		count++;

	while (count2 >= 0)
	{
		dest[count] = src[count2];
		if (src[count2] == '\0')
			break;
		count++;
		count2++;
	}
	return (dest);
}
/**
 * _strcpy - Copies string from SRC to Dest.
 * @src: String to be copied.
 * @dest: Place to be pasted.
 *
 * Return: The pointer to Dest
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		dest[count] = src[count];
		if (src[count] == '\0')
			break;
		count++;
	}
	return (dest);
}
