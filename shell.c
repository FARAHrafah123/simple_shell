#include "shell.h"
/**
 * main - simple shell
 * @argc:number of arguments
 * @argv:content of arguments
 * Return: value
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *line_str = NULL;
	int exit_status = 0;
	size_t x = 0;
	int count_command = 0;

	while (1)
	{
		line_str = NULL;
		x = 0;
		count_command++;
		exit_status = handling_line(line_str, x, argv, count_command, &exit_status);
	}
	return (exit_status);
}
