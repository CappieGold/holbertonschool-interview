#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_hole - determines if a position is a hole in the Menger sponge
 * @row: row index
 * @col: column index
 *
 * Return: 1 if the position is a hole, 0 otherwise
 */
static int is_hole(int row, int col)
{
	while (row > 0 && col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (1);
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: the level of the sponge to draw
 */
void menger(int level)
{
	int size, row, col;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (is_hole(row, col))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
