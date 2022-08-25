#include "main.h"

/**
 * _isspecial_double - check if special char in double quotes
 * @c: char to check
 * Return: 0 || 1
 */

int isspecial_double(char c)
{
	return (c == '"' || c == '$' || c == '\\');
}
