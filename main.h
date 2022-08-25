#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>

typedef dict_t alias_t;
typedef int (*builtin_fp)(info_t *);

/**
 * struct builtin - builtins
 * @name: command
 * @f: func
 * @help: command usage
 * @desc: command description
 */

struct builtin
{
    const char *name;
    builtin_fp f;
    const char *help;
    const char *desc;
};

const struct builtin *get_builtin(const char *name);
const struct builtin *get_builtins(void);

int addaliases(info_t *info);
int changedir(info_t *info);
int env(info_t *info);
int exec(info_t *info);
int cleanexit(info_t *info);
int help(info_t *info);
int history(info_t *info);
int setenv(info_t *info);
int unsetenv(info_t *info);

/**
 * enum cmdlist_sep_n - numeric values for commmand list separators
 * @SEMICOLON: ;
 * @AMPERSAND: &
 * @AND: &&
 * @OR: ||
 */

typedef enum cmdlist_sep_n
{
    SEMICOLON = 1,
    AMPERSAND = 2,
    AND       = 4,
    OR        = 8
} cmdlist_sep_n_t;

/**
 * struct cmdlist_sep - command list separator structure
 * @sep: the command separator
 * @n: the corresponding numeric value
 */

typedef struct cmdlist_sep
{
    const char *sep;
    enum cmdlist_sep_n n;
} cmdlist_sep_t;

/**
 * struct cmdlist - linked list of commands
 * @next: the next command
 * @tree: a binary tree of commands
 * @tokens: the tokens for each command in the tree
 */

struct cmdlist
{
    struct cmdlist *next;
    struct cmdtree *tree;
    char **tokens;
};

/**
 * struct cmdtree - binary tree of commands
 * @success: the command to execute upon failure
 * @failure: the command to execute upon success
 * @tokens: a simple command with no separators
 * @sep: the preceding list separator
 */

struct cmdtree
{
    struct cmdtree *success;
    struct cmdtree *failure;
    const char * const *tokens;
    struct cmdlist_sep sep;
};

cmdlist_t *cmd_to_list(const char *cmd);
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count);

size_t split_cmd(char *cmd);

cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd);
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t index);
char **pop_cmd(cmdlist_t **headptr);
void free_cmdlist(cmdlist_t **headptr);

cmdtree_t *cmd_to_tree(const char * const *tokens);
void free_cmdtree(cmdtree_t **rootptr);

bool isalnumchar(int c);
bool isalphachar(int c);
bool isdigitchar(int c);
bool isidentchar(int c);
bool isspacechar(int c);
bool isquotechar(int c);
bool isnumberchar(const char *s);

/**
  * struct dict - singly linked list of key-value pairs
  * @key: var name
  * @val: val of var
  * @next: *p -> next node
  */

struct dict
{
    char *key;
    char *val;
    struct dict *next;
};

char *get_dict_val(dict_t *head, const char *key);
dict_t *get_dict_node(dict_t *head, const char *key);
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val);
dict_t *del_dict_node(dict_t **headptr, const char *key);
void free_dict(dict_t **headptr);

typedef dict_t env_t;

env_t *env_to_dict(char **env);
env_t *_env_to_dict(env_t **tailptr, char **env);
char **dict_to_env(env_t *head);

void perrorl(const char *msg, ...);
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...);

#define GETLINE_BUFFER_SIZE 4096

/**
 * struct buf_s - input buf
 * @buffer: buf
 * @next: *p -> next value
 * @remaining: n values remaining
 */

typedef struct buf_s
{
    char buffer[GETLINE_BUFFER_SIZE];
    char *next;
    size_t remaining;
} buf_t;

#define GETLINE_TABLE_SIZE 127

/**
 * struct buf_table_node_s - input buf hash table
 * @fd: file descriptor
 * @buf: associated buf
 * @next: next buf in chain
 */

typedef struct buf_table_node_s
{
    int fd;
    struct buf_s buf;
    struct buf_table_node_s *next;
} buf_table_node_t;

typedef buf_table_node_t *buf_table_t[GETLINE_TABLE_SIZE];

char *_getline(const int fd);

/**
  * struct history - command history
  * @head: *p -> head of the history list
  * @filename: name of the history to file
  * @n: n entries in the history list
  */

struct history
{
    struct list *head;
    char *filename;
    size_t n;
};

extern char **environ;

bool read_input(info_t *info);
quote_state_t _read_input(char **lineptr, int fd);

int parse(info_t *info);

int execute(info_t *info);
int _execute(info_t *info);

void expand_aliases(alias_t *aliases, char ***tokptr);
char *expand_alias(alias_t *aliases, char ***tokptr);

void expand_vars(info_t *info, char ***tokptr);
char **_expand_vars(info_t *info, char ***tokptr);

void remove_comments(cmdlist_t *cmd);

void open_script(info_t *info);

void sigint(int signal);

extern char **environ;

/**
  * struct info - shell state
  * @interactive: args passed
  * @argc: args
  * @argv: args
  * @file: args
  * @fileno: args
  * @status: args
  * @line: args
  * @lineno: args
  * @tokens: args
  * @pid: args
  * @cwd: args
  * @exe: args
  * @env: args
  * @path: args
  * @aliases: args
  * @history: args
  * @commands: args
  */

struct info
{
    int interactive;
    int argc;
    char **argv;
    char *file;
    int fileno;
    int status;
    char *line;
    size_t lineno;
    char **tokens;
    pid_t pid;
    char *cwd;
    char *exe;
    env_t *env;
    list_t *path;
    alias_t *aliases;
    history_t *history;
    cmdlist_t *commands;
};

info_t *init_info(int argc, char **argv);
int free_info(info_t *info);

/**
 * struct list - singly linked list
 * @str: dynamically-allocated str
 * @next: *p -> next node
 */

struct list
{
    char *str;
    struct list *next;
};

list_t *str_to_list(const char *str, char delim);
list_t *_str_to_list(list_t **tailptr, const char *str, char delim);
list_t *add_node(list_t **headptr, const char *str);
list_t *add_node_end(list_t **headptr, const char *str);
void free_list(list_t **headptr);

char *search_path(info_t *info, list_t *path);

/**
 * enum quote_state - a quote state mnemonic
 * @QUOTE_NONE: In an unquoted sequence of blanks
 * @QUOTE_WORD: In an unquoted sequence of non-blanks
 * @QUOTE_DOUBLE: In ""
 * @QUOTE_SINGLE: In ''
 * @QUOTE_ESCAPE: Following a backslash
 */

typedef enum quote_state
{
    QUOTE_NONE   = 0x0,
    QUOTE_WORD   = 0x1,
    QUOTE_DOUBLE = 0x2,
    QUOTE_SINGLE = 0x4,
    QUOTE_ESCAPE = 0x8
} quote_state_t;

typedef size_t (*quote_state_fp)(const char *, quote_state_t *);

quote_state_t quote_state(char c);

quote_state_fp quote_state_f(quote_state_t s);

size_t quote_state_len(const char *str, quote_state_t state);
size_t _quote_state_none(const char *str, quote_state_t *state);
size_t _quote_state_word(const char *str, quote_state_t *state);
size_t _quote_state_double(const char *str, quote_state_t *state);
size_t _quote_state_single(const char *str, quote_state_t *state);
size_t _quote_state_escape(const char *str, quote_state_t *state);

int isspecial_double(char c);

char *dequote(const char *str);
size_t dequote_len(const char *str);

ssize_t _memchr(const void *src, unsigned char chr, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
void *_memdup(const void *src, size_t n);
void *_memset(void *dest, unsigned char chr, size_t n);

ssize_t _strchr(const char *str, char chr);
ssize_t _strnchr(const char *str, char chr, size_t n);

int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, size_t n);

char *_strdup(const char *str);
char *_strndup(const char *str, size_t n);

ssize_t _strlen(const char *str);
ssize_t _strnlen(const char *str, size_t n);

char *strjoin(size_t *n, const char *sep, const char *pre, const char *suf);
char *strjoina(size_t *n, const char *sep, const char **array);
char *strjoinl(size_t *n, const char *sep, ...);

unsigned int atou(char *s);
char *num_to_str(size_t n);

char **tokenize(const char *str);
char **tokenize_noquote(const char *str);

size_t count_tokens(const char *str);
size_t count_tokens_noquote(const char *str);

void free_tokens(char ***tokens);

char **arrdup(char **arr);

char **arrjoin(char **arr1, char **arr2);

typedef struct builtin builtin_t;
typedef struct cmdlist cmdlist_t;
typedef struct cmdtree cmdtree_t;
typedef struct dict dict_t;
typedef struct history history_t;
typedef struct info info_t;
typedef struct list list_t;