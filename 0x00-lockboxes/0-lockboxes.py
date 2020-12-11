#!/usr/bin/python3
"""
Write a method that determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""

    keys = [0]

    if len(boxes) == 0:
        return True

    for key in keys:
        for key in boxes[key]:
            if key not in keys and key < len(boxes):
                keys.append(key)

    if len(keys) == len(boxes):
        return True
    else:
        return False
