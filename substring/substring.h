#ifndef SUBSTRING_H
#define SUBSTRING_H

/**
 * find_substring - finds all substrings that are a concatenation
 *                  of each word in @words exactly once, without any
 *                  intervening characters
 * @s: the string to scan
 * @words: array of words the substrings must be made of
 * @nb_words: number of elements in the array @words
 * @n: address at which to store the number of elements in the returned array
 *
 * Return: an allocated array storing each index in @s at which a substring
 * was found, or NULL if no solution is found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
