#include "main.h"

/**
 * isquotechar - check if char is a quote
 * @c: char
 * Return: 0 || 1
 */

bool isquotechar(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}
