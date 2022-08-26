#include "string.h"

/**
  * _strnchr - get the index of the first matching char
  * @str: str passed
  * @chr: char passed
  * @n: max number of chars to check
  * Return: Index of the first occurence, or -1 chr is not found
  */

ssize_t _strnchr(const char *str, char chr, size_t n)
{
	ssize_t index;

	if (!str)
		return (-1);

	for (index = 0; n && str[index]; --n, ++index)
	{
		if (str[index] == chr)
			return (index);
	}

	return (-1);
}

/**
 * _strndup - duplicate the given str
 * @str: str to duplicate
 * @n: n bytes to copy
 * Return: NULL || * p -> dynamically-allocated duplicate.
 */

char *_strndup(const char *str, size_t n)
{
	char *dup;
	size_t len = 0;

	if (!str)
		return (NULL);

	while (n && str[len])
		--n, ++len;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	dup[len] = '\0';

	while (len--)
		dup[len] = str[len];

	return (dup);
}

/**
 * _strnlen - calculate the len(str)
 * @str: str to measure
 * @n: max number of chars to check
 * Return: < n & the len(str)
 */

ssize_t _strnlen(const char *str, size_t n)
{
	const char *pos = str;

	if (!str)
		return (-1);

	while (n && *pos)
		--n, ++pos;

	return (pos - str);
}

/**
 * _strncmp - compare two strs
 * @s1: a str to compare
 * @s2: other str to compare
 * @n: max number of bytes to compare
 * Return: << 0 >>
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}

	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}

	return (0);
}

/**
 * _strncpy - copy str
 * @dest: dest
 * @src: src
 * @n: max number of bytes to copy
 * Return: *p -> dest
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	char *pos = dest;

	for ( ; n && *src; --n)
		*pos++ = *src++;
	if (n)
		*pos = '\0';

	return (dest);
}
