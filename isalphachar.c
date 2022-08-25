#include "main.h"

/**
  * isalphachar - checks if alphabetic
  * @c: char
  * Return: 0 || 1
  */

bool isalphachar(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
