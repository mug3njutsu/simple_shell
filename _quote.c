#include "main.h"

/**
 * __quote_state_none - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t __quote_state_none(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (isspacechar(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * __quote_state_word - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t __quote_state_word(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && !isspacechar(*str) && !isquotechar(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * __quote_state_double - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t __quote_state_double(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '"')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}

/**
 * __quote_state_single - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t __quote_state_single(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '\'')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}

/**
 * ___quote_state_escape - get state length and next state
 * @str: str
 * @state: state
 * Return: len(state)
 */

size_t ___quote_state_escape(const char *str, quote_state_t *state)
{
	if (*str)
	{
		if (state && *(++str))
			*state = quote_state(*str);
		return (1);
	}
	return (0);
}
