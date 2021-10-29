#!/usr/bin/python3
"""
    Given a pile of coins of different values, determine the
    fewest number of coins needed to meet a given amount total
"""

import sys


def makeChange(coins, total):
    """
        Method to determine the fewest number of coins needed
        to meet a given amount total
    """
    if (total < 0):
        return 0

    amountCoins = len(coins)  # Lenght or Quantity of Coins

    # table[i] will be storing the minimum number of coins required
    # for i value.
    table = [0 for i in range(total + 1)]

    # Base case
    table[0] = 0

    # Initialize all array values as infinite
    for i in range(1, total + 1):
        table[i] = sys.maxsize

    # Check all coins smaller than i
    for i in range(1, total + 1):

        for j in range(amountCoins):
            if (coins[j] <= i):
                sub_res = table[i - coins[j]]
                # idxCoins = i - coins[j]
                # print("i = {0} | coins[j] = {1}".format(i, coins[j]))
                # print("sub_res =  {0} | i - coins[j] = {1}".format(sub_res,
                #  idxCoins))
                if (sub_res != sys.maxsize and
                        sub_res + 1 < table[i]):
                    table[i] = sub_res + 1

    if table[total] == sys.maxsize:
        return -1

    return table[total]
