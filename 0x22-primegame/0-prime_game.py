#!/usr/bin/python3
"""
    Maria and Ben are playing a game. Given a set of consecutive integers
    starting from 1 up to and including n, they take turns choosing a prime
    number from the set and removing that number and its multiples from the
    set. The player that cannot make a move loses the game.

    They play x rounds of the game, where n may be different for each round.
    Assuming Maria always goes first and both players play optimally,
    determine who the winner of each game is.

    Result: Ben has the most wins
"""


def isPrime(n):
    """
        Check if 'n' is a prime number
    """
    for i in range(2, int(n ** 1/2) + 1):
        if not n % i:
            return False
    return True


def calculateNumPrimes(n, primes):
    """
        Get all prime numbers to 'n'
    """
    upPrime = primes[-1]
    if n > upPrime:
        for i in range(upPrime + 1, n + 1):
            if isPrime(i):
                primes.append(i)
            else:
                primes.append(0)


def isWinner(x, nums):
    """
        Where x is the number of rounds and nums is an array of n
        Return: name of the player that won the most rounds
        If the winner cannot be determined, return None
    """
    players = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]

    calculateNumPrimes(max(nums), primes)

    for Round in range(x):
        sum_options = sum((i != 0 and i <= nums[Round])
                          for i in primes[:nums[Round] + 1])
        if (sum_options % 2):
            winner = "Maria"
        else:
            winner = "Ben"

        if winner:
            players[winner] += 1

    if players["Maria"] > players["Ben"]:
        return "Maria"
    elif players["Ben"] > players["Maria"]:
        return "Ben"

    return None
