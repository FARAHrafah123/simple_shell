#include "shell.h"
/**
 * built_in_check: Check giv comand of built-in commands defined in array.
 * @argv: contains the arguments passed to the main program.
 * @command: Pointer string represents the command entered by the user.
 * @arr_tok: Pointer array of strings that contain tokenized comnd argumts.
 * @exit_status: Pointer  integer variable the exit status of the program.
 * @n_count: Integer representing tot number of commands executed.
 * Return: Value 1 if command is a built-in command has successfully,
 * 0 if command not built-in is not successfully
 */

int built_in_check(char **argv, char *command,
		char **arr_tok, int *exit_status, int n_count)
{
	int i = 0;
	builtin_t fun[] = {
		{"exit", exit_builtin},
		{"env", env_builtin},
		{NULL, NULL}
	};

	while (fun[i].s)
	{
		if (_strcmp(fun[i].s, arr_tok[0]) == 0)
		{
			fun[i].f(argv, command, arr_tok, exit_status, n_count);
			return (1);
		}
		i++;
	}
	return (0);
}
/**
 *exit_builtin:Handling the exit built-in command in a command-line
 *@argv:Contains the arguments passed to the main program
 *@command:Pointer string represents the command entered by the user.
 *@arr_tok:Pointer to an array of strings that contains tokenized command arg
 *@exit_status:Pointer to integer variable that holds the exit status program
 *@n:Integer representing total number of commands executed so far.
 */
void exit_builtin(char **argv, char *command,
		char **arr_tok, int *exit_status, int n)
{
	int num = 0, i = 0;

	if (arr_tok[1])
	{
		while (arr_tok[1][i])
		{
			if (_isalpha(arr_tok[1][i]))
			{
				print_error(argv[0]);
				print_error(": ");
				print_integer(n);
				print_error(": exit: Illegal number: ");
				print_error(arr_tok[1]);
				print_error("\n");
				free_comand_array(command, arr_tok);
				exit(2);
			}
			i++;
		}
		num = _atoi(arr_tok[1]);
		if (num < 0)
		{
			print_error(argv[0]);
			print_error(": ");
			print_integer(n);
			print_error(": exit: Illegal number: ");
			print_error(arr_tok[1]);
			print_error("\n");
			free_comand_array(command, arr_tok);
			exit(2);
		}
		free_comand_array(command, arr_tok);
		exit(num);
	}

	free_comand_array(command, arr_tok);
	exit(*exit_status);
}

/**
 * env_builtin: Handling the env built-in command in a command-line
 * @argv: Contains the arguments passed to the main program.
 * @command: Pointer string represents the command entered by the user.
 * @arr_tok: Pointer to array of strings that contains tokenized comnd argumen
 * @exit_status: Pointer to integer variable that holds the exit status
 * @n: Integer representing  total number of commands executed so far
 */

void env_builtin(char **argv, char *command,
		char **arr_tok, int *exit_status, int n)
{
	int i = 0;
	(void) command;
	(void) arr_tok;
	(void) exit_status;
	(void) argv;
	(void) n;

	while (environ[i])
	{
		print_string(environ[i]);
		print_char('\n');
		i++;
	}
}
