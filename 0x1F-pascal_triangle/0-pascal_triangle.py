#!/usr/bin/python3
"""
function that returns a list of lists of integers
representing the Pascals triangle of n
"""

def pascal_triangle(n):
    """
    returns a list of lists of integers representing
    the Pascal’s triangle of n
    """
    tri_pascal = []
    if n <= 0:
        return tri_pascal
    elif n == 1:
        tri_pascal.append([1])
        return tri_pascal
    else:
        tri_pascal = [[1], [1, 1]]
        for fila in range(2, n):
            i_list = [1]
            for i in range(1, fila):
                i_list.append(tri_pascal[fila - 1][i - 1] +
                              tri_pascal[fila - 1][i])
            i_list.append(1)
            tri_pascal.append(i_list)

    return tri_pascal
