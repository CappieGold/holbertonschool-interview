#!/usr/bin/python3
"""
Making Change - Dynamic Programming Solution
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list): List of coin values (infinite quantity of each)
        total (int): Target amount to make

    Returns:
        int: Fewest number of coins needed,
             or -1 if impossible, or 0 if total <= 0
    """
    # Cas de base
    if total <= 0:
        return 0

    # Initialiser le tableau dp
    # dp[i] = nombre minimum de pièces pour faire le montant i
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # 0 pièce pour faire 0

    # Pour chaque montant de 1 à total
    for amount in range(1, total + 1):
        # Essayer chaque pièce
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    # Si dp[total] est encore infini, c'est impossible
    return dp[total] if dp[total] != float('inf') else -1
