#include "main.h"

/**
 * isspacechar - check if char is whitespace
 * @c: char
 * Return: 0 || 1
 */

bool isspacechar(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}
