#include "ctype.h"

/**
 * _isspace - check if char is whitespace
 * @c: char to check
 * Return: 0 || 1
 */

bool _isspace(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}
