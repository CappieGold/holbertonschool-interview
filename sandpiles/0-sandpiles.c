#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Prints a 3x3 grid
 * @grid: The 3x3 grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * copy_grid - Copies src grid into dest grid
 * @dest: Destination 3x3 grid
 * @src: Source 3x3 grid
 */
static void copy_grid(int dest[3][3], int src[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			dest[i][j] = src[i][j];
	}
}

/**
 * check_unstable - Checks if a 3x3 grid has any cell > 3
 * @grid: The 3x3 grid to check
 *
 * Return: 1 if unstable (cell > 3 found), 0 otherwise
 */
static int check_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * topple_cells - Topple all cells > 3 in temp and update grid
 * @grid: The main 3x3 grid (modified in place)
 * @temp: A copy of the grid used to find cells to topple
 */
static void topple_cells(int grid[3][3], int temp[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (temp[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i - 1 >= 0)
					grid[i - 1][j] += 1;
				if (i + 1 < 3)
					grid[i + 1][j] += 1;
				if (j - 1 >= 0)
					grid[i][j - 1] += 1;
				if (j + 1 < 3)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: First 3x3 grid (result stored here)
 * @grid2: Second 3x3 grid
 *
 * Description:
 *   1) Add grid2 to grid1.
 *   2) While grid1 has any cell > 3, print grid1 then topple.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stable = 0;
	int temp[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (!stable)
	{
		stable = 1;

		copy_grid(temp, grid1);

		if (check_unstable(temp))
		{
			stable = 0;
			printf("=\n");
			print_grid(grid1);

			topple_cells(grid1, temp);
		}
	}
}
