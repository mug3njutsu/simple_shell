#include "ctype.h"

/**
  * _isalnum - checks if the char is alphanumeric
  * @c: char to check
  * Return: 0 || 1
  */

bool _isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}
