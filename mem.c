#include "string.h"

/**
 * _memchr - get the index of the first matching value
 * @src: start of the memory area to search
 * @chr: val to find
 * @n: sizeof(search area)
 * Return: -1 || index of the first occurrence of char
 */

ssize_t _memchr(const void *src, unsigned char chr, size_t n)
{
	const unsigned char *mem = src;
	ssize_t i = 0;

	if (src)
	{
		while (n--)
		{
			if (mem[i] == chr)
				return (i);
			i += 1;
		}
	}
	return (-1);
}

/**
 * _memcpy - copy a memory area
 * @dest: *p -> start of the target area
 * @src: *p -> start of the src area
 * @n: n bytes to copy
 * Return: *p -> dest
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *w_pos = dest;
	const unsigned char *r_pos = src;

	if (dest && src)
	{
		while (n--)
			*w_pos++ = *r_pos++;
	}
	return (dest);
}

/**
 * _memdup - duplicate a memory area
 * @src: *p -> start of the src area
 * @n: n bytes to duplicate
 * Return: NULL || *p -> start of the duplicated memory
 */

void *_memdup(const void *src, size_t n)
{
	void *dup = malloc(n);
	unsigned char *w_pos = dup;
	const unsigned char *r_pos = src;

	if (dup)
	{
		while (n--)
			*w_pos++ = *r_pos++;
	}
	return (dup);
}

/**
 * _memset - fill a region of memory with a given val
 * @dest: *p -> beginning of the region
 * @chr: val to write to the region
 * @n: n bytes to write
 * Return: dest
 */

void *_memset(void *dest, unsigned char chr, size_t n)
{
	unsigned char *mem = dest;

	if (dest)
	{
		while (n--)
			*mem++ = chr;
	}
	return (dest);
}
