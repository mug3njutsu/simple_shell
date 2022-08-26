#include "command.h"

/**
 * cmd_to_tree - construct a binary tree of commands
 * @tokens: command to parse
 * Return: NULL || &root of the new tree
 */

cmdtree_t *cmd_to_tree(const char * const *tokens __attribute__((unused)))
{
	return (NULL);
}

/**
 * free_cmdtree - free a binary tree and set root to NULL
 * @rootptr: *p
 * Return: NULL
 */

void free_cmdtree(cmdtree_t **rootptr)
{
	if (rootptr && *rootptr)
	{
		free_cmdtree(&((*rootptr)->success));
		free_cmdtree(&((*rootptr)->failure));
		(*rootptr)->tokens = NULL;
		(*rootptr) = NULL;
	}
}
