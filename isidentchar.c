#include "main.h"

/**
  * isidentchar - checks if char is valid
  * @c: char
  * Return: 0 || 1
  */

bool isidentchar(int c)
{
	return (c == '_' || isalnumchar(c));
}
