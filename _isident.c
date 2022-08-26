#include "ctype.h"

/**
  * _isident - checks if the char is a valid identifier char
  * @c: char to check
  * Return: 0 || 1
  */

bool _isident(int c)
{
	return (c == '_' || _isalnum(c));
}
