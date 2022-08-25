#include "main.h"

/**
  * _isident - checks if char is valid
  * @c: char
  * Return: 0 || 1
  */

bool isident(int c)
{
	return (c == '_' || isalnum(c));
}

