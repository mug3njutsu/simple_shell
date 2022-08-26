#include "builtins.h"

/**
 * get_builtins - get builtins
 * Return: *p -> NULL-terminated statically-allocated [] of builtins
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
 * get_builtin - get builtin by name
 * @name: name of the builtin to retrieve
 * Return: NULL || otherwise *p -> builtin
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
