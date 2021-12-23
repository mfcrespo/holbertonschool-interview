#include "substring.h"
/**
 * value_cmp - value comparator
 * @a: int
 * @b: int
 * Return: 
 **/

int value_cmp(const void *a, const void *b)
{
    int value1 = *(int *)a;
    int value2 = *(int *)b;

    return (value1 - value2);
}

/**
 * check - function check word in string
 * @s: char
 * @words: array of char
 * @nb_words: int
 * Return: int
 **/

int *check(char const *s, char const **words, int nb_words)
{
    int *arr, i, j = 0, len;
    char *aux;

    arr = malloc((sizeof(int) * nb_words));
    if (!arr)
        return (NULL);
    for (i = 0; i < nb_words; i++)
    {
        aux = strstr(s, words[i]);
        if (!aux)
        {
            free(arr);
            return (NULL);
        }
        len = (int)strlen(aux);
        while (j < i)
        {
            if (len == arr[j])
            {
                aux = strstr(s + (int)strlen(s) - len + 1, words[i]);
                if (!aux)
                {
                    free(arr);
                    return (NULL);
                }
                len = (int)strlen(aux);
                arr[i] = len;
            }
            j++;
        }
        arr[i] = len;
    }
    return (arr);
}

/**
 * find_substring - function that finds all the possible substrings
 * containing a list of words, within a given string.
 * @s: it's the string to scan
 * @words: it's the array of words all substrings must be a concatenation
 * arrangement of
 * @nb_words: it's the number of elements in the array words
 * @n: hold the address at which to store the number of elements in the
 * returned array.
 * Return:  an allocated array, storing each index in s, at which a substring
 * was found. If no solution is found, NULL can be returned
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int *indx, *arr, len, diff, s_len, idx, tmp;
    int i, j;

    *n = 0;
    len = (int)strlen(words[0]);
    s_len = (int)strlen(s);
    for (j = 0; j < s_len; j++)
    {
        arr = check(s, words, nb_words);
        if (!arr)
            break;
        qsort(arr, nb_words, sizeof(int), value_cmp);
        for (i = 0; i < nb_words - 1; i++)
        {
            if (arr[i + 1] - arr[i] != len)
            {
                idx = 0;
                break;
            }
            else
                idx = 1;
        }
        tmp = arr[nb_words - 1];
        free(arr);
        if (idx == 1)
        {
            diff = s_len - tmp;
            if (*n == 0 || diff != indx[*n - 1])
            {
                if (*n == 0)
                {
                    indx = malloc((sizeof(int)));
                    if (!indx)
                        return (NULL);
                }
                else
                    indx = realloc(indx, sizeof(int) * (*n + 1));
                indx[*n] = diff;
                *n += 1;
            }
        }
        s++;
    }
    if (*n == 0)
        return (NULL);
    return (indx);
}
