#include "main.h"

/**
  * isalnum - checks if char is alphanumeric
  * @c: char
  * Return: 0 || 1
  */

bool isalnum(int c)
{
	return (isalpha(c) || isdigit(c));
}
