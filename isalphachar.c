#include "main.h"

/**
  * isalpha - checks if alphabetic
  * @c: char
  * Return: 0 || 1
  */

bool isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
