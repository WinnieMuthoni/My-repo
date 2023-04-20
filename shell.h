#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <syst/stat.h>
#include <limits.h>
#include <sys/wait>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_AND 
#define CMD_OR 
#define CMD_NORM 
#define CMD_CHAIN 

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define USE_GETLINE 0
#define USE_STRTOK
#define HISTO_MAX 4096
#define HISTO_FILE ".simple_shell_history"

extern char **environ;

/**
 * struct listst - singly linked list
 * @numbe; the number field
 * @st: a string
 * @z: points to the next node
 *
 */

typedef struct listst
{
	int numbe;
	char *st;
	struct listst *next;
}listt

/**
 *
 * struct pas - contains pseudocode-arguments to pass into a funtion
 * @arg: a string generated from the getline containing arguments
 * * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @_count: the error count
 * @er_n: the error code for exit()s
 * @count_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @envm: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_h: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @tcount: the history line number count
 */
typedef struct pas
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int count ;
	int er_n;
	int count_flag;
	char *fname;
	listt *env;
	listt *history;
	listt *alias;
	char **envm;
	int env_h;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int tcount;
}forn

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(forn *);
} in_ta

int hsh(forn *, char **);
int d_build(forn *);
void find_cmd(forn *);
void fork_cmd(forn *);



int is_cmd(forn *, char *);
char *dup_chars(char *, int, int);
char *find_path(forn*, char *, char *);
int loophsh(char **);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);
int interactive(forn *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int _erratoi(char *);
void print_error(forn *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _myexit(forn *);
int _mycd(forn *);
int _myhelp(forn *);
int _myhistory(forn *);
int _myalias(forn *);
ssize_t get_input(forn *);
int _getline(forn *, char **, size_t *);
void sigintHandler(int);
void clear_info(forn *);
void set_info(forn *, char **);
void free_info(info_t *, int);



char *_getenv(forn *, const char *);
int _myenv(forn *);
int _mysetenv(forn *);
int _myunsetenv(forn*);
int populate_env_list(forn *);



char **get_environ(forn *);
int _unsetenv(forn *, char *);
int _setenv(forn *, char *, char *);
char *get_history_file(forn *info);
int write_history(forn *info);
int read_history(forn *info);
int build_history_list(forn *info, char *buf, int linecount);
int renumber_history(forn *info);
listt *add_node(listt **, const char *, int);
listt *add_node_end(listt **, const char *, int);
size_t print_list_str(const listt *);
int delete_node_at_index(listt **, unsigned int);
void free_list(listt **);



size_t list_len(const listt *);
char **list_to_strings(listt *);
size_t print_list(const listt *);
list_t *node_starts_with(listt *, char *, char);
ssize_t get_node_index(listt *, listt *);



int is_chain(forn *, char *, size_t *);
void check_chain(forn *, char *, size_t *, size_t, size_t);
int replace_alias(forn *);
int replace_vars(forn *);
int replace_string(char **, char *);

#endif

