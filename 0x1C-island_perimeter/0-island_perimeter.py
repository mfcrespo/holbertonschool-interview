#!/usr/bin/python3
"""
function that returns the perimeter
of the island described in grid
"""


def island_perimeter(grid):
    """
    grid is a list of list of integers
        * 0 represents water,
        * 1 represents land
        * Each cell is square, with a side length of 1
        * Cells are connected horizontally/vertically (not diagonally).
        * grid is rectangular, with its width and height not exceeding 100
    """
    rows = len(grid)
    cols = len(grid[0])
    perim = 0
    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                if row == 0 or grid[row-1][col] == 0:
                    perim += 1
                if row == rows-1 or grid[row+1][col] == 0:
                    perim += 1
                if col == 0 or grid[row][col-1] == 0:
                    perim += 1
                if col == cols-1 or grid[row][col+1] == 0:
                    perim += 1
    return perim
