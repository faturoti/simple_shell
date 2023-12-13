#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: pointer to the char array string
 *
 * Return: length of str
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);

	for (length = 0; s[length]; length++)
	{

	}

	return (length);
}

/**
 * _strcpy - To cpy str from one dest tp another
 * @dest: Pointer to the destination
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';
	return (dest);
}
