#include "shell.h"
/**
 *  handling_line -parsing command
 *  @argv:content of arguments
 *  @line_str:command line
 *  @x:length
 */
int  handling_line(char **argv,char *line_str, size_t x,int count_command,int *exit_status)
{
	ssize_t count;
	char **arr_tok;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	count = getline(&line_str, &x, stdin);

	if (count == -1)
	{
		free(line_str);
		exit(*exit_status);
	}
	else
	{
		arr_tok = arr_token(line_str);
		if (arr_tok){
			if (built_in_check(argv, line_str, arr_tok, exit_status, count_command) == 0)
			{
				*exit_status = execute_program(arr_tok, argv, count_command);
			}
		}
		free_comand_array(line_str, arr_tok);
	}
	return (*exit_status);
}
int count_tokens(char *line_str)
{
	char *line_str2;
	char *token;
	char *del = " \n";
	int i;

	line_str2 = _strdup(line_str);
	if (line_str2 == NULL)
		return (-1);
	token = strtok(line_str2, del);
	for (i = 0; token != NULL; i++)
		token = strtok(NULL, del);
	free(line_str2);
	return (i);
}

char **arr_token(char *line_str)
{
	char *del = " \n", *token, *line_str_copy;
	char **arr_tok;
	int i, j = 0;


	line_str_copy = _strdup(line_str);

	i = count_tokens(line_str);

	if (!i)
	{
		free(line_str_copy);
		return (NULL);
	}

	arr_tok = malloc(sizeof(char *) * (i + 1));

	if (!arr_tok)
	{
		free(line_str_copy);
		return (NULL);
	}

	token = strtok(line_str_copy, del);

	while (token)
	{
		arr_tok[j] = _strdup(token);
		token = strtok(NULL, del);
		j++;
	}
	arr_tok[j] = NULL;
	free(line_str_copy);

	return (arr_tok);
}

int execute_program(char **arr_tok, char **argv, int count_command)
{
	pid_t child_pid;
	char *path_built;
	int status = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		path_built = path_finder(arr_tok[0]);
		if (path_built)
		{
			if (execve(path_built, arr_tok, environ) == -1)
			{
				print_error_line_str(argv[0], arr_tok[0], count_command);
				exit(127);
			}
			free(path_built);
		}
		else
		{
			print_error_line_str(argv[0], arr_tok[0], count_command);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	return (WEXITSTATUS(status));
}
