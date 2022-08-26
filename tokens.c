#include "tokens.h"

/**
 * tokenize - split a str into words (tokens) and dequote
 * @str: the str to tokenize
 * Return: NULL
 */

char **tokenize(const char *str)
{
	char **tokens;
	const char *tok;
	size_t count;
	quote_state_t state;

	if (!str)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens(str) + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		tok = str;

		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}

		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[count][str - tok] = '\0';
	}
	tokens[count] = NULL;

	return (tokens);
}

/**
 * count_tokens - compute the len(str) after dequoting
 * @str: the str to eval
 * Return: len(str) after dequoting
 */

size_t count_tokens(const char *str)
{
	size_t count;
	quote_state_t state;

	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}
	}
	return (count);
}

/**
 * tokenize_noquote - split a str into words (tokens)
 * @str: the str to tokenize
 * Return: NULL
 */

char **tokenize_noquote(const char *str)
{
	char **tokens;
	const char *tok;
	size_t count;

	if (!str)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens_noquote(str) + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *str; ++count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;

		tok = str;
		do {
			++str;
		} while (*str && !_isspace(*str));

		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[count][str - tok] = '\0';
	}
	tokens[count] = NULL;

	return (tokens);
}


/**
 * count_tokens_noquote - count the words in a str
 * @str: str to evaluate
 * Return: -1 || n words in str
 */

size_t count_tokens_noquote(const char *str)
{
	size_t tok_count;

	for (tok_count = 0; *str; ++tok_count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (*str && !_isspace(*str));
	}
	return (tok_count);
}

/**
 * free_tokens - free & nullify an array of strs
 * @tokens: *p -> [] of tokens
 */

void free_tokens(char ***tokens)
{
	char **tok;

	if (!tokens)
		return;

	tok = *tokens;
	if (!tok)
		return;

	while (*tok)
		free(*tok++);
	free(*tokens);

	*tokens = NULL;
}
