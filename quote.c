#include "main.h"

/**
 * quote_state_none - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t quote_state_none(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (isspace(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * quote_state_word - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t quote_state_word(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && !isspace(*str) && !isquote(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * quote_state_double - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t quote_state_double(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '"')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}

/**
 * _quote_state_single - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t quote_state_single(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '\'')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}

/**
 * _quote_state_escape - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t quote_state_escape(const char *str, quote_state_t *state)
{
	if (*str)
	{
		if (state && *(++str))
			*state = quote_state(*str);
		return (1);
	}
	return (0);
}