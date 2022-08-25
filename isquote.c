#include "main.h"

/**
 * isquote - check if char is a quote
 * @c: char
 * Return: 0 || 1
 */

bool isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}
