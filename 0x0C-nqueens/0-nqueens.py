#!/usr/bin/python3
"""
Write a program that solves the N queens problem.
* Usage: nqueens N
- If the user called the program with the wrong number of arguments,
  print Usage: nqueens N, followed by a new line, and exit with the status 1
* Where N must be an integer greater or equal to 4
- If N is not an integer, print N must be a number, followed by a new line,
  and exit with the status 1
- If N is smaller than 4, print N must be at least 4, followed by a new line,
  and exit with the status 1
* The program should print every possible solution to the problem
- One solution per line
- Format: see example
- You don’t have to print the solutions in a specific order
* You are only allowed to import the sys module
"""

import sys


def queens(n):
    """a program that solves the N queens problem"""
    path = []
    games = set()

    for column in range(n):
        path.append([0, column])
        games.add(column)

    lane = []

    while path:
        [row, column] = path.pop(0)
        while lane and (row < lane[0][0]):
            lane.pop(0)

        if lane and (row == lane[0][0]):
            lane[0] = [row, column]

        else:
            lane.insert(0, [row, column])

        nextrows = row + 1
        death = set()

        for (i, j) in lane:
            death.add(j)
            distance = nextsrows - i

            if j - distance >= 0:
                death.add(j - distance)

            if j + distance < n:
                death.add(j + distance)

        safe = games.difference(death)

        if not safe:
            if nextrows == n:
                temp = lane.copy()
                temp.reverse()
                print(temp, flush=True)
            lane.pop(0)

        else:
            safe = list(safe)
            safe.reverse()
            for position in safe:
                path.insert(0, [nextrows, position])


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)

    try:
        n = int(sys.argv[1])
    except:
        print("N must be a number")
        exit(1)
    queens(n)
