#include "main.h"

/**
 *_strcat -  append
 *@src: source
 *@dest: destination
 *Return: returns
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
		ptr++;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 *_strcmp - a function that compare chars from strings
 *@s1: the first string
 *@s2: the second string
 *Return: always the result of the diffrence of the two char in s1 and s2 or 0
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 *_memcpy - a function that copies memory area.
 *@dest: destination
 *@src: source
 *@n: bytes from memory
 *Return: returns dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		{
		*(dest + i) = *(src + i);
		}
	return (dest);
}

/**
 *_strchr - a function that locates a character in a string.
 *@s: main string
 *@c: character to be exaamened
 *Return: returns
 */

char *_strchr(char *s, char c)
{
	char *ps = s;

	while (*ps)
	{
		if (*ps == c)
		{
			return (ps);
		}
		ps++;
	}
	if (!c)
	{
		return (ps);
	}
	return (0);
}

/**
 *_strncmp - a string comparison function
 *@str1: first string
 *@str2: second string
 *@num: how many chars to be compared
 *Return: returns
 */

int _strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;

	for (i = 0; i < num && str1[i] != '\0' && str2[i] != '\0'; ++i)
	{
		if (str1[i] != str2[i])
			return ((str1[i] - str2[i]));
	}

	if (i == num)
		return (0);

	if (str1[i] != '\0')
		return (1);

	if (str2[i] != '\0')
		return (-1);

	return (0);
}
