#include "shell.h"

/**
 * _strlen - Calculates the length of a null-terminated string.
 * @string :The input string.
 * Return: n or null
 *
 */

int _strlen(char *string)
{
	int n = 0;

	while (string[n])
	{
		n++;
	}

	return (n);
}

/**
 * _strdup - Duplicates a null-terminated string and returns
 *  a pointer to the new copy.
 * @string :The input string to be duplicated.
 * Return: memory allocation if is successful or Null
 */

char *_strdup(char *string)
{
	char *string2;
	int m, i;

	m = _strlen(string);

	string2 = malloc(sizeof(char) * (m + 1));

	if (string2 == NULL)
	{
		return (NULL);
	}

	for (i = 0; string[i]; i++)
	{
		string2[i] = string[i];
	}

	string2[i] = '\0';

	return (string2);
}
/**
 * _strcmp - Compares two strings lexicographically.
 * @str1 :The first string to be compared
 * @str2 :The second string to be compared
 * Return: An integer less than, equal to, or greater than zero
 *  if str1 is found, respectively,to be less than, to match,
 *   or to be greater than str2.
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);

}


/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;

		i++;
	}

	for (; s[i] != '\0'; ++i)
		res = res * 10 + s[i] - '0';

	return (sign * res);
}
