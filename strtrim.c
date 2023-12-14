#include "monty.h"

/**
 * *strtrim - remove all whitespace characters from a
 *           string(even internal whitespaces).
 * @str: the string to trim.
 * Return: the string without whitespaces.
*/
char *strtrim(const char *str)
{
	char *target_str = malloc(sizeof(char)), *new_str;
	int i = 0, new_len = 0;

	malloc_check(target_str);

	for (i = 0; i < (int)strlen(str); i++)
	{
		if (is_whitespace(str[i]))
			continue;

		target_str[new_len] = str[i];
		new_len++;
	}
	target_str[new_len] = '\0';

	new_str = malloc(sizeof(char) * new_len);
	if (new_str == NULL)
	{
		free(target_str);
		malloc_error();
	}

	strcpy(new_str, target_str);

	free(target_str);
	return (new_str);
}

/**
 * is_whitespace - checks if a character is a whitespace.
 * @ch: the character to test against.
 * Return: true if character is whitespace,
 *         Otherwise - false
*/
bool is_whitespace(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\n');
}
