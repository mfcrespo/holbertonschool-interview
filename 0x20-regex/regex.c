#include "regex.h"

/**
 * regex_match -compare two strings if one has slight regex
 * @str: string to scan. Can be empty, and can contain any ASCII character
 * in the exception of . and *
 * @pattern: is the regular expression.  can be empty, and can contain any
 * ASCII character, including . and *
 * Return: return 1 if the pattern matches the string, or 0 if it doesn’t
*/
int regex_match(char const *str, char const *pattern)
{
	int temp = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);
	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));

	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			temp = regex_match(str + 1, pattern);
		return (regex_match(str, pattern + 2) || temp);
	}
	return (0);

}
