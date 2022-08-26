#include "ctype.h"

/**
  * _isalpha - checks if the char is alphabetic
  * @c: char to check
  * Return: 0 || 1
  */

bool _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
