#include "slide_line.h"
#include <unistd.h>

static void compress_left(int *line, size_t size);
static void compress_right(int *line, size_t size);

/**
 * slide_line - Slides and merges an array of integers the way 2048 game does
 *              but on a single row, either left or right.
 *
 * @line: Pointer to the array of integers.
 * @size: Number of elements in @line.
 * @direction: SLIDE_LEFT or SLIDE_RIGHT.
 *
 * Return: 1 on success, 0 on failure (if direction is invalid).
 *
 * Description:
 *  1. Check if direction is valid (SLIDE_LEFT or SLIDE_RIGHT).
 *  Otherwise, return 0.
 *  2. Compress non-zero values toward the direction.
 *  3. Merge equal adjacent values exactly once per move.
 *  4. Compress again if merges created new zeros.
 *  5. Return 1.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		compress_left(line, size);

		for (i = 0; i < size - 1; i++)
		{
			if (line[i] != 0 && line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}

		compress_left(line, size);
	}
	else
	{
		compress_right(line, size);

		for (i = size - 1; i > 0; i--)
		{
			if (line[i] != 0 && line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
		}
		compress_right(line, size);
	}

	return (1);
}

/**
 * compress_left - Move all non-zero values of `line` to the left side,
 *                 keeping their relative order.
 * @line: Array of integers.
 * @size: Number of elements in @line.
 */
void compress_left(int *line, size_t size)
{
	size_t read = 0, write = 0;

	while (read < size)
	{
		if (line[read] != 0)
		{
			line[write] = line[read];
			if (write != read)
				line[read] = 0;
			write++;
		}
		read++;
	}
}

/**
 * compress_right - Move all non-zero values of `line` to the right side,
 *                  keeping their relative order.
 * @line: Array of integers.
 * @size: Number of elements in @line.
 */
void compress_right(int *line, size_t size)
{
	ssize_t read = (ssize_t)size - 1, write = (ssize_t)size - 1;

	while (read >= 0)
	{
		if (line[read] != 0)
		{
			line[write] = line[read];
			if (write != read)
				line[read] = 0;
			write--;
		}
		read--;
	}
}
