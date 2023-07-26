#include "shell.h"

/**
 * print_error_string -This function is used to print an error
 *  message indicating that a particular command was not found.
 *  @name:name of error
 *  @command:command not found or caused the error.
 *  @count_command:the line number where the error occurred
 */

void print_error_string(char *name, char *command, int count_command)
{
	print_error(name);
	print_error(": ");
	print_integer(count_command);
	print_error(": ");
	print_error(command);
	print_error(": ");
	print_error("not found\n");

}

/**
 * print_error - This function is responsible for printing an error message
 * @str:containing the error message to be printed
 */

void print_error(char *str)
{
	if (!str)
		write(STDERR_FILENO, "(null)", 6);
	write(STDERR_FILENO, str, _strlen(str));
}


/**
 * free_comand_array - This fun  used to deallocate memory for an array of str
 * @string:represents a dynamically allocated string
 * @arr_tok: pointer to a pointer of characters
 */

void free_comand_array(char *string, char **arr_tok)
{
	int j = 0;

	while (arr_tok[j])
	{
		free(arr_tok[j]);
		j++;
	}
	free(arr_tok);
	free(string);
}
