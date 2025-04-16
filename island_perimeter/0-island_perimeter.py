#!/usr/bin/python3
"""
Module to calculate the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island defined in grid.

    grid is a list of lists of integers:
      0 represents water
      1 represents land
    Each cell has a side length of 1.
    Cells are connected horizontally/vertically.
    The grid is completely surrounded by water.
    There is at most one island, and the island doesn’t have "lakes".
    """
    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Chaque cellule d'atterrissage
                # contribue en principe 4 au périmètre
                perimeter += 4

                # Si la cellule du haut est aussi de la terre,
                # alors on partage un côté
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                # Si la cellule de gauche est de la terre,
                # on partage aussi un côté
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
