#!/usr/bin/python3
'''Module of script that reads stdin line by line and computes metrics'''
import sys


def printOccurrence():
    """
    prints the statistics after every 10 lines and/or a keyboard interruption
    """
    print("File size: {}".format(fileSize))
    for key, value in sorted(possibleCodes.items()):
        if (value != 0):
            print("{}: {}".format(key, value))


if __name__ == "__main__":
    possibleCodes = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
                     "404": 0, "405": 0, "500": 0}
    lines = 1
    fileSize = 0

    try:
        for line in sys.stdin:
            try:
                status = line.split(" ")[-2]
                size = line.split(" ")[-1]
                fileSize += int(size)
                possibleCodes[status] += 1
            except Exception:
                continue
            if lines % 10 == 0:
                printOccurrence()
            lines += 1

    except KeyboardInterrupt:
        printOccurrence()
        raise

    printOccurrence()
