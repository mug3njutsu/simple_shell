#include "main.h"

/**
  * isnumber - check if str consists of digits
  * @s: *p -> str
  * Return: true || false
  */

bool isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!isdigit(*s++))
				return (false);
		}
		return (true);
	}
	return (false);
}
