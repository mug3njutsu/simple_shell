#include "main.h"

/**
 * _strcmpdir - compares strings
 * @s1: str
 * @s2: str
 * Return: 0 if match
 **/

int _strcmpdir(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 3)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * charput - writes the char
 * @c: char to print
 * Return: On success 1.
 */

int charput(char c)
{
	return (write(1, &c, 1));
}

/**
 * place - kinda like puts
 * @str: *p -> we want to set to 402
 * Return: int
 */

void place(char *str)
{
	while (*str != '\0')
	{
		charput(*str);
		str++;
	}
}

/**
 * _strlen - len(str)
 * @str: str
 * Return: len
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * str_concat - concatinate strs
 * @s1: str
 * @s2: second str
 * Return: strs
 */

char *str_concat(char *s1, char *s2)
{
	char *a;
	int lens1, lens2, j, i, e;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	lens1 = _strlen(s1);

	lens2 = _strlen(s2);

	a = malloc(((lens1) + (lens2) + 1) * sizeof(char));

	if (a == NULL)
		return (NULL);

	for (j = 0; j < lens1; j++)
	{
		a[j] = s1[j];
	}

	for (i = lens1, e = 0; e <= lens2; i++, e++)
	{
		a[i] = s2[e];
	}
	return (a);
}
