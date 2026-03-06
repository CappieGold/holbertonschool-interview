# Merge Sort

## Description

Implementation of the **top-down Merge Sort** algorithm in C. The function sorts an array of integers in ascending order by recursively dividing it into two halves (left size <= right size), sorting each half, then merging them back together.

## Prototype

```c
void merge_sort(int *array, size_t size);
```

## Rules

- Top-down merge sort approach.
- Left sub-array size is always `<=` right sub-array size.
- Left array is sorted before the right array.
- Only **one** `malloc` and **one** `free` call allowed.
- Merging steps are printed to stdout.

## Time Complexity (Big O)

| Case | Complexity |
|------|-----------|
| Best | O(nlog(n)) |
| Average | O(nlog(n)) |
| Worst | O(nlog(n)) |

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
```

## Example

```
$ ./merge
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
...
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Files

| File | Description |
|------|-------------|
| `sort.h` | Header file with function prototypes |
| `0-merge_sort.c` | Merge sort implementation |
| `0-O` | Big O time complexities |
| `print_array.c` | Helper to print arrays |
