#include "main.h"

/**
 * get_builtins - get __builtins__
 * Return: *p -> NULL-terminated statically-allocated [__builtins__]
 */

const builtin_t *get_builtins(void)
{
	static builtin_t builtins[] = {
		{"alias", __alias, ALIAS_HELP, ALIAS_DESC},
		{"cd", __cd, CD_HELP, CD_DESC},
		{"env", __env, ENV_HELP, ENV_DESC},
		{"exec", __exec, EXEC_HELP, EXEC_DESC},
		{"exit", __exit, EXIT_HELP, EXIT_DESC},
		{"help", __help, HELP_HELP, HELP_DESC},
		{"setenv", __setenv, SETENV_HELP, SETENV_DESC},
		{"unsetenv", __unsetenv, UNSETENV_HELP, UNSETENV_DESC},
		{0}
	};

	return (builtins);
}

/**
 * get_builtin - get a builtin by name
 * @name: the name of the builtin to retrieve
 * Return: NULL if no match is found, otherwise a pointer to the builtin
 */
const builtin_t *get_builtin(const char *name)
{
	const builtin_t *builtin = NULL;

	for (builtin = get_builtins(); builtin->name; builtin += 1)
	{
		if (_strcmp(name, builtin->name) == 0)
			return (builtin);
	}
	return (NULL);
}
