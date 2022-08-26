#include "string.h"

/**
  * _strchr - get the index of the first matching char
  * @str: str passed
  * @chr: char passed
  * Return: index
  */

ssize_t _strchr(const char *str, char chr)
{
	ssize_t index;

	if (!str)
		return (-1);

	for (index = 0; str[index]; ++index)
	{
		if (str[index] == chr)
			return (index);
	}

	return (-1);
}

/**
 * _strdup - create a new []] containing a copy of the given str
 * @str: *p -> str to copy
 * Return: NULL || *p -> new copy
 */

char *_strdup(const char *str)
{
	char *dup;
	size_t size = 0;

	if (!str)
		return (NULL);

	while (str[size++])
		;

	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);

	while (size--)
		dup[size] = str[size];

	return (dup);
}

/**
 * _strlen - calculate the length of a str
 * @str: str to calculate the length
 * Return: len(str)
 */

ssize_t _strlen(const char *str)
{
	const char *pos = str;

	if (!str)
		return (-1);

	while (*pos)
		++pos;

	return (pos - str);
}

/**
 * _strcmp - compare two strings
 * @s1: a str to compare
 * @s2: the other str to compare
 * Return: << 0 >>
 */

int _strcmp(const char *s1, const char *s2)
{
	for (; *s1 && *s2; ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}

	if (*s1)
		return (1);
	if (*s2)
		return (-1);

	return (0);
}

/**
 * _strcpy - copy str
 * @dest: dest
 * @src: src
 * Return: *p -> dest
 */

char *_strcpy(char *dest, const char *src)
{
	char *pos = dest;

	while (*src)
		*pos++ = *src++;
	*pos = '\0';

	return (dest);
}
