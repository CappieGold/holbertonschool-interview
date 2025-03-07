#include "sandpiles.h"
#include <stdio.h>

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

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int stable = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    while (!stable)
    {
        int temp[3][3];
        int found = 0;

        stable = 1;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                temp[i][j] = grid1[i][j];
            }
        }

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (temp[i][j] > 3)
                {
                    found = 1;
                    stable = 0;
                }
            }
        }

        if (found == 1)
        {
            printf("=\n");
            print_grid(grid1);

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (temp[i][j] > 3)
                    {
                        grid1[i][j] -= 4;
                        if (i - 1 >= 0)
                            grid1[i - 1][j] += 1;
                        if (i + 1 < 3)
                            grid1[i + 1][j] += 1;
                        if (j - 1 >= 0)
                            grid1[i][j - 1] += 1;
                        if (j + 1 < 3)
                            grid1[i][j + 1] += 1;
                    }
                }
            }
        }
    }
}
