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
    pascal_tri = []
    if n <= 0:
        return pascal_tri
    elif n == 1:
        pascal_tri.append([1])
        return pascal_tri
    else:
        pascal_tri = [[1], [1, 1]]
        for fila in range(2, n):
            i_list = [1]
            for i in range(1, fila):
                i_list.append(pascal_tri[fila - 1][i - 1] +
                              pascal_tri[fila - 1][i])
            i_list.append(1)
            pascal_tri.append(i_list)

    return pascal_tri
