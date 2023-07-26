#include "main.h"

/**
 *_strncpy - a fucntion that append two strings to one
 *@dest: the string that will be copied to
 *@src: the string that will be copied from
 *@n:buffer
 *Return: always a string of chars
 */


char *_strncpy(char *dest, const char *src, size_t n)
{
	char *dest_start = dest;

	while (*src && n > 0)
	{
		*dest++ = *src++;
		n--;
	}

	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}

	return (dest_start);
}

/**
 *_isdigit - checks if a char is a num
 *@c: the char
 *Return: not NULL for success
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 *isNumber - checks if the string is a number
 *@str: string to be examened
 *Return: 0 for success
*/

int isNumber(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	for (; str[i] != '\0'; i++)
	{
		if (!_isdigit(str[i]))
			return (0);
	}
	return (1);
}


/**
 *_strtok - tokenize a string
 *@str: pointer to the string to be tokenized
 *@del: delimeters
 *Return: a pointer to the token
 */

char *_strtok(char *str, char *del)
{
	static char *next_token /*= NULL*/;
	char *token;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	token = next_token;
	next_token = _strpbrk(next_token, del);
	if (next_token != NULL)
	{
		*next_token = '\0';
		next_token++;
	}

	return (token);
}


/**
 *_strpbrk - a function that gets the length of a prefix substring.
 *@s: string s
 *@accept: another string
 *Return: returns smtg
 */

char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
			{
				return (s);
			}
			a++;
		}
		s++;
	}
	return ('\0');
}
