#include "shell.h"
/**
 * main - simple shell
 * @argc:number of arguments
 * @argv:content of arguments
 * Return: value 0
 */
int main(_attribute_((unused)) int argc,char **argv)
{
	char *line_str=NULL;
	int exit_status=0;
	size_t x=0;
	int count_command=0;

	while(1)
	{
		line_str=NULL;
		x=0;
		count_command++;
		exit_status=handling_line(argv,line_str,x,count_command,&exit_status);
	}
	return (exit_status);
}
