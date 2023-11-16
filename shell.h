#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@lineCountNum: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fileName: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int lineCountNum;
	int err_num;
	int linecount_flag;
	char *fileName;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
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

/* toem_parser.c */
/* int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *); */

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _printToConsole(char *);
int _printCharToConsole(char);
int writeToBufferAndFlush(char f, int fd);
int writeStringToFD(char *string, int fd);

/* toem_string.c */
int _strLength(char *);
int _compareString(char *, char *);
char *beginsWith(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strCopy(char *, char *);
char *_stringDup(const char *);
void _puts(char *);
int _putChar(char);

/* toem_exits.c */
/* char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char); */

/* toem_tokenizer.c */
char **vicedo(char *, char *);
char **vicedo2(char *, char);

/* toem_realloc.c */
char *_edovic(char *, char, unsigned int);
void malloc_free(char **);
void *qua_lloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
/* int bfree(void **); */

/* toem_atoi.c */
int _interactive(info_t *);
int isDelim(char, char *);
int _isAlpha(int);
int _myAtoi(char *);

/* toem_errors1.c */
int convertToInt(char *);
void _printError(info_t *, char *);
int printIntNum(int, int);
char *numConverter(long int, int, int);
void xtractComments(char *);

/* toem_builtin.c */
/* int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *); */

/* toem_builtin1.c */
/* int _myhistory(info_t *);
int _myalias(info_t *); */

/*toem_simpleShell_inputRead.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void handleSigint (int);

/* toem_fileData_processing.c */
void clear_data(info_t *);
void setup_info(info_t *, char **);
void freeInfo(info_t *, int);

/* toem_environ.c */
char *_get_env_value(info_t *, const char *);
int _myenv(info_t *);
int _setenvValue(info_t *);
int _unsetenvValue(info_t *);
int overrun_env(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetEnvironment_variable(info_t *, char *);
int _setUp_env(info_t *, char *, char *);

/* toem_history.c */
/* char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info); */

/* toem_lists.c */
list_t *insertNode_atStart(list_t **, const char *, int);
list_t *insertNode_atEnd(list_t **, const char *, int);
size_t outputStrings_inList(const list_t *);
int extractNode_atIndex(list_t **, unsigned int);
void looseList(list_t **);

/* toem_lists1.c */
size_t calcLen(const list_t *);
char **stringsToArray(list_t *);
size_t _printList(const list_t *);
list_t *checkNodePrefix(list_t *, char *, char);
ssize_t _getNodeIndex(list_t *, list_t *);

/* toem_vars.c */
int vic_edo(lump_t *, char *, size_t *);
void high_pain(lump_t *, char *, size_t *, size_t, size_t);
int substitute_alias(lump_t *);
int substitute_vars(lump_t *);
int substitute_shellstring(char **, char *);

#endif


