#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

typedef struct built_in
{
	char *s;
	void (*f)(char **argv, char *command, char **arr_tok, int *exit_status, int n);
} builtin_t;

/**handling_line**/
int handling_line(char **argv,char *line_str, size_t x,int count_command,int *exit_status);
int count_tokens(char *line_str);
char **arr_token(char *line_str);
int execute_program(char **arr_tok, char **argv, int count_command);

/**lib_helper**/
int _strlen(char *string);
char *_strdup(char *string);
int _strcmp(char *str1, char *str2);
int _atoi(char *s);

/**lib_helperr**/
void print_string(char *str);
void print_char(char c);
void print_integer(int n);
void free_comand_array(char *string, char **arr_tok);

/**lib_helperrr**/
int _isalpha(int c);



/**path_checker**/
char *path_checker(char *program);
char *_getenv(char *name);
int is_file_exist(char *path);
char *build_path_slash(char *str1, char *str2);

/**help**/
void print_error_string(char *name, char *command, int count_command);
void print_error(char *str);

/**builtcodin**/
int built_in_check(char **argv, char *command, char **arr_tok, int *exit_status, int n_count);
void exit_builtin(char **argv, char *command, char **arr_tok, int *exit_status, int n);
void env_builtin(char **argv, char *command, char **arr_tok, int *exit_status, int n);


#endif
