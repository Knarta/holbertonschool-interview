#!/usr/bin/python3
"""
Coin change: fewest coins to make total (unlimited supply per denomination).
"""


def makeChange(coins, total):
    """
    Return the fewest number of coins needed to meet total.
    Return 0 if total <= 0, -1 if total cannot be made.
    """
    if total <= 0:
        return 0

    # dp[i] = minimum number of coins to make amount i
    dp = [total + 1] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], 1 + dp[amount - coin])

    return -1 if dp[total] > total else dp[total]
