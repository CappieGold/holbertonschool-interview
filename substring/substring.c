#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * is_concatenation - checks whether the window starting at @sub is a valid
 *                    concatenation of every word in @words exactly once
 * @sub: pointer to the start of the window in the scanned string
 * @words: array of words to match
 * @nb_words: number of elements in @words
 * @wlen: length of every word (all words share the same length)
 * @used: scratch array used to flag which words were already matched
 *
 * Return: 1 if @sub is a valid concatenation, 0 otherwise
 */
static int is_concatenation(char const *sub, char const **words,
			    int nb_words, int wlen, int *used)
{
	int i, j, matched;

	for (i = 0; i < nb_words; i++)
		used[i] = 0;

	for (i = 0; i < nb_words; i++)
	{
		matched = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
			    strncmp(sub + i * wlen, words[j], wlen) == 0)
			{
				used[j] = 1;
				matched = 1;
				break;
			}
		}
		if (!matched)
			return (0);
	}
	return (1);
}

/**
 * find_substring - finds all indices in @s at which a substring that is a
 *                  concatenation of every word in @words begins
 * @s: the string to scan
 * @words: array of words the substrings must be made of
 * @nb_words: number of elements in the array @words
 * @n: address at which to store the number of elements in the returned array
 *
 * Return: an allocated array of indices, or NULL if no solution is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices, *used, count = 0;
	int wlen, total, slen, i;

	*n = 0;
	if (!s || !words || nb_words <= 0)
		return (NULL);

	wlen = strlen(words[0]);
	total = wlen * nb_words;
	slen = strlen(s);
	if (wlen == 0 || total > slen)
		return (NULL);

	indices = malloc(sizeof(int) * (slen - total + 1));
	used = malloc(sizeof(int) * nb_words);
	if (!indices || !used)
	{
		free(indices);
		free(used);
		return (NULL);
	}

	for (i = 0; i <= slen - total; i++)
	{
		if (is_concatenation(s + i, words, nb_words, wlen, used))
			indices[count++] = i;
	}

	free(used);
	if (count == 0)
	{
		free(indices);
		return (NULL);
	}
	*n = count;
	return (indices);
}
