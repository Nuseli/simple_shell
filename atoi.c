#include "shell.h"

/**
 * interactive - checks if shell is in interactive mode
 * @info: struct containing information about shell
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	if (isatty(STDIN_FILENO) && info->readfd <= 2)
		return (1);
	return (0);
}

/**
 * is_delim - checks if character is a delimiter
 * @c: character to check
 * @delim: delimiter string
 *
 * Return: 1 if character is a delimiter, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _isalpha - checks if a character is alphabetic
 * @c: character to check
 *
 * Return: 1 if character is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value of string, or 0 if no numbers found
 */
int _atoi(char *s)
{
	int sign = 1, flag = 0, output = 0;
	unsigned int result = 0;

	for (int i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	output = sign * result;

	return (output);
}
