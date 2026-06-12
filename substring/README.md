# Substring with concatenated words

Find all the possible substrings containing a list of words, within a given
string.

## Description

`find_substring` scans a string `s` and returns every index at which a
**concatenation** of all the words in `words` (each used exactly once, in any
order, with no intervening characters) begins.

All words share the same length.

## Prototype

```c
int *find_substring(char const *s, char const **words, int nb_words, int *n);
```

| Parameter  | Description                                                      |
| ---------- | ---------------------------------------------------------------- |
| `s`        | The string to scan                                               |
| `words`    | Array of words every substring must be a concatenation of        |
| `nb_words` | Number of elements in the array `words`                          |
| `n`        | Address at which to store the number of elements in the result   |

**Return:** an allocated array storing each index in `s` at which a substring
was found, or `NULL` if no solution is found.

## Algorithm

The total length of a valid window is `nb_words * word_length`. Every starting
position `i` in `s` such that `i + total_length <= len(s)` is tested. For a
window to be valid, each consecutive block of `word_length` characters must
match a distinct, still-unused word from `words`.

- Time complexity: `O(len(s) * nb_words^2 * word_length)`
- Space complexity: `O(len(s) + nb_words)`

## Files

| File          | Description                          |
| ------------- | ------------------------------------ |
| `substring.c` | Implementation of `find_substring`   |
| `substring.h` | Function prototype                   |
| `main.c`      | Example test program                 |

## Compilation

```sh
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c substring.c -o substring
```

## Usage

```sh
$ ./substring barfoothefoobarman foo bar
Indices -> [0, 9]
$ ./substring wordgoodgoodgoodbestword word good best word
Indices -> []
$ ./substring wordgoodgoodgoodbestword word good best good
Indices -> [8]
```
