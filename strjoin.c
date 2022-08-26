#include "string.h"

/**
 * strjoin - joins two strs with another str
 * @n: address at which to store the sizeof(new string)
 * @sep: joining str
 * @pre: prefix str
 * @suf: suffix str
 * Return: *p -> new string
 */

char *strjoin(size_t *n, const char *sep, const char *pre, const char *suf)
{
	char *dest = NULL;
	size_t sep_len = _strlen(sep ? sep : "");
	size_t pre_len = _strlen(pre ? pre : "");
	size_t suf_len = _strlen(suf ? suf : "");

	dest = malloc(sizeof(char) * (pre_len + sep_len + suf_len + 1));
	if (dest)
	{
		_strcpy(dest, pre ? pre : "");
		_strcpy(dest + pre_len, sep ? sep : "");
		_strcpy(dest + pre_len + sep_len, suf ? suf : "");
		if (n)
			*n = pre_len + sep_len + suf_len + 1;
	}
	return (dest);
}

/**
 * strjoina - join strs from a NULL-terminated []
 * @n: address at which to store the length of the new str
 * @sep: joining str
 * @array: array of strs
 * Return: *p -> new string
 */

char *strjoina(size_t *n, const char *sep, const char **array)
{
	char *dest = NULL;
	size_t len = 0, idx = 0, sep_len = _strlen(sep ? sep : "");

	while (array[idx])
		len += _strlen(array[idx++]);

	if (idx--)
	{
		dest = malloc(sizeof(char) * (len + idx * sep_len + 1));
		if (dest)
		{
			len = 0;
			while (*array)
			{
				_strcpy(dest + len, *array);
				len += _strlen(*array);
				if (sep_len && idx--)
				{
					_strcpy(dest + len, sep);
					len += sep_len;
				}
			}
			if (n)
				*n = len + 1;
		}
	}
	return (dest);
}

/**
 * strjoinl - joins a NULL terminated list of strs with a char
 * @n: address at which to store the len(new str)
 * @sep: joining str
 * @...: strs
 * Return: *p -> new string
 */

char *strjoinl(size_t *n, const char *sep, ...)
{
	char *dest = NULL;
	const char *temp = NULL;
	size_t idx = 0, len = 0, sep_len = _strlen(sep ? sep : "");
	va_list ap;

	for (va_start(ap, sep); (temp = va_arg(ap, char *)); idx += 1)
		len += _strlen(temp);
	va_end(ap);

	if (idx--)
	{
		dest = malloc(sizeof(char) * (len + idx * sep_len + 1));
		if (dest)
		{
			len = 0;
			va_start(ap, sep);
			while ((temp = va_arg(ap, char *)))
			{
				_strcpy(dest + len, temp);
				len += _strlen(temp);
				if (sep_len && idx--)
				{
					_strcpy(dest + len, sep);
					len += sep_len;
				}
			}
			va_end(ap);
			if (n)
				*n = len + 1;
		}

	}
	return (dest);
}
