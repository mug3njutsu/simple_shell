#include "main.h"

/**
 * remove_comments - remove comments from command
 * @cmd: *p -> cmd
 */

void remove_comments(cmdlist_t *cmd)
{
	char **tokens, **new, *tmp;

	for (tokens = cmd->tokens; *tokens; ++tokens)
	{
		if (**tokens == '#')
		{
			tmp = *tokens;
			*tokens = NULL;
			new = arrdup(cmd->tokens);
			*tokens = tmp;
			free_tokens(&(cmd->tokens));
			cmd->tokens = new;
			free_cmdlist(&(cmd->next));
			return;
		}
	}
}
