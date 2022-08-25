#include "main.h"

/**
  * isalnumchar - checks if char is alphanumeric
  * @c: char
  * Return: 0 || 1
  */

bool isalnumchar(int c)
{
	return (isalphachar(c) || isdigitchar(c));
}
