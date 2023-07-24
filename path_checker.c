#include "shell.h"

/**
 *path_chicker - responsible for locating the full path
 * @program : representing the name of the program
 *  or command that needs to be found in the PATH.
 *  Return: a dynamically allocated string
 *  containing the full path or NULL
 */

char *path_chicker(char *program)
{
	char *path_value, *path_name, *token, *path_with_slash;

	path_name  = _getenv("PATH");
	path_value = strtok(NULL, "=");
	if (is_file_exist(program) == 0)
		return (_strdup(program));
	token = strtok(path_value, ":");
	while (token)
	{
		path_with_slash = build_path_slash(token, program);
		if (is_file_exist(path_with_slash) == 0)
		{
			free(path_name);
			return (path_with_slash);
		}
		token = strtok(NULL, ":");
		free(path_with_slash);
	}
	free(path_name);
	return (NULL);
}

/**
 * _getenv - function searches for the value of a spc env
 * @name:character pointer representing the name
 * of the environment variable to be searched for.
 * Return: a dynamically allocated string containing
 * its value If the environment variable is found or null
 */

char *_getenv(char *name)
{
	int i = 0;
	char *env_name;
	char *token;

	while (environ[i])
	{
		env_name = _strdup(environ[i]);
		token = strtok(env_name, "=");
		if (_strcmp(token, name) == 0)
		{
			return (env_name);
		}
		free(env_name);
		i++;
	}
	return (NULL);
}
/**
 * is_file_exist - func is used to determine if a file exists
 *  at the specified path by checking for read permissions on the file
 *  @path: representing the path to the file whose
 *   existence needs to be checked.
 *   Return:0 If the file exists and can be accessed
 * with read permission -1 is not
 */
int is_file_exist(char *path)
{
	return (access(path, R_OK));
}

/**
 * build_path_slash  - constructs a new string by concatenating
 * two strings with a '/' character in between them.
 * @str1 :The first part of the new path.
 * @str2 :The second part of the new path.
 * @return A pointer to the new string if both str1 and str2
 * are not NULL and memory allocation succeeds.
 *         Otherwise, it returns NULL if either str1 or str2
 *          is NULL or memory allocation fails.
 *         The caller is responsible for freeing the memory
 *         of the returned string when done using it.
 */

char *build_path_slash(char *str1, char *str2)
{
	int i = 0, j = 0;
	char *path_string;

	if (!str1 || !str2)
		return (NULL);
	path_string = malloc(sizeof(char) + _strlen(str1) + _strlen(str2) + 2);

	while (str1[i])
	{
		path_string[i] = str1[i];
		i++;
	}
	path_string[i] = '/';
	i++;
	while (str2[j])
	{
		path_string[i + j] = str2[j];
		j++;
	}
	path_string[i + j] = '\0';
	return (path_string);
}
