#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of
walls with unit width 1
"""


def rain(walls):
    """ calculate how many square units of water will be retained
    after it rains"""
    if (len(walls) <= 2):
        return(0)

    squaresWater = 0

    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for k in range(i + 1, len(walls)):
            right = max(right, walls[k])

        squaresWater += min(left, right) - walls[i]

    return squaresWater
