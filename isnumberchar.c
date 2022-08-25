#include "main.h"

/**
  * isnumberchar - check if str consists of digits
  * @s: *p -> str
  * Return: true || false
  */

bool isnumberchar(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!isdigitchar(*s++))
				return (false);
		}
		return (true);
	}
	return (false);
}
