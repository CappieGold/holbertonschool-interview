#!/usr/bin/python3
"""
Module that calculates the minimum number of operations
to achieve n H characters
"""


def minOperations(n):
    """
    Calculate the fewest number of Copy All and Paste operations
    needed to reach exactly n 'H' characters starting from one 'H'.

    If n is less than or equal to 1,
    returns 0 since no operations are needed or
    it's impossible to build up to n > 1 from one character without operations.
    """
    if n <= 1:
        return 0

    ops = 0
    divisor = 2
    while divisor * divisor <= n:
        while n % divisor == 0:
            ops += divisor
            n //= divisor
        divisor += 1
    if n > 1:
        ops += n

    return ops
