#include "main.h"

/**
 * _num_to_str - converts num to str
 * @buf: str
 * @n: num passed
 */

static void _num_to_str(char **buf, size_t n)
{
	if (n > 9)
		_num_to_str(buf, n / 10);
	**buf = '0' + n % 10;
	*buf += 1;
	**buf = '\0';
}

/**
 * num_to_str - converts num to str
 * @n: num passed
 * Return: *p -> string
 */

char *num_to_str(size_t n)
{
	size_t tmp = n, len = 1;
	char *buf;

	while (tmp /= 10)
		len++;
	buf = malloc(len + 1);
	if (!buf)
		return (NULL);
	_num_to_str(&buf, n);
	return (buf - len);
}
