#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
    - Copy All.
    - Paste.
Given a number n, write a method that calculates the fewest
number of operations needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """
    method that calculates the fewest number of operations needed to result
    in exactly n H characters in the file.
    Returns an integer.
    If n is impossible to achieve, return 0.
    """

    current = 1
    numberOperations = 0
    buffer = 0

    if n < 2:
        return 0

    while current < n:
        rest = n - current

        if rest % current == 0:
            buffer = current
            current += buffer
            numberOperations += 2

        else:
            current += buffer
            numberOperations += 1

    return numberOperations
