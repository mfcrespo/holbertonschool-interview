#!/usr/bin/python3
""" Given an n x n 2D matrix, rotate it 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """
        Method: Rotate a 2D matrix 90 degrees clockwise
        Parameters:
            @matrix: 2D matrix that must be rotate 90 degrees clockwise
        Return: Do not return anything. The matrix must be edited in-place
    """
    nRows = len(matrix)  # number of rows

    tmpMatrix = matrix.copy()
    matrix.clear()

    i = 0
    while(i < nRows):
        editeRow = []
        j = nRows - 1
        while(j >= 0):
            editeRow.append(tmpMatrix[j][i])
            j -= 1
        matrix.append(editeRow)
        i += 1
