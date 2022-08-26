#include "quote.h"

/**
 * _isspecial_double - check if char is special inside double quotes
 * @c: char to check
 * Return: 0 || 1
 */

int _isspecial_double(char c)
{
	return (c == '"' || c == '$' || c == '\\');
}
