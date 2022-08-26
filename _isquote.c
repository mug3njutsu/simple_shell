#include "ctype.h"

/**
 * _isquote - check if char is a quote
 * @c: char to check
 * Return: 0 || 1
 */

bool _isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}
