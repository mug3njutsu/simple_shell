#include "ctype.h"

/**
  * _isnumber - check if a str consists only of digits
  * @s: *p -> string
  * Return: true || false
  */

bool _isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!_isdigit(*s++))
				return (false);
		}
		return (true);
	}
	return (false);
}
