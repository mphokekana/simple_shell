#ifndef __SHELL__H__
#define __SHELL__H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <error.h>

/* for read/erite buggers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	I
#define CONVERT_UNSIGNED	2

/* 1 if using system getlinr() */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* 1 if using sysstem getline */
#define HIST_FILE	"simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: pointers to the next mode
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-argumrnts to pass inro a function
 *allwing unoform prototypes for function pointer struct
 *@arg: a string generated from getline containing arguments
 *@argv: an array of strings generated from argi
 *@argc: argument count
 *@path: a string path for the current comman
 *@line_count: the err counr
 *@err_num: the err code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list locak copy of environ
 *@environ: custom modified copy of evviron from LL env
 *@history: the history nofe
 *@alias: the alias node
 *@env_changed: on if enviren was changed
 *@status: the return ststus of the last exec'd command
 *@cmd_buf: address of pointer to the cmd_buf, on if chaining
 *@cmd_buf_type: CMP_type, ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL}

#define INFO_INIT \
	{NULL, NULL, NULL, 0, 0, 0, 0, \
		NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \ 0, 0, 0}
/**
 * struct builtin - containds a builtin string and related function
 * @type: the bui;t command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_shloop.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* towm_string1.c */
char *_strncpy(char *, char *);
char *_strcdup(const char *);
void _puts(char *);
int _putchar(char);

/*toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
void *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/*toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_memory.c atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_getline.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysentenv(info *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t *);
void free_list(list_t **);

/* toem_lists1.c */
size_t list_len(cost list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif




