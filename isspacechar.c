#include "main.h"

/**
 * isspace - check if char is whitespace
 * @c: char
 * Return: 0 || 1
 */

bool isspace(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}
