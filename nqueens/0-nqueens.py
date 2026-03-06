#!/usr/bin/python3
"""N Queens problem solver"""

import sys


def solve_nqueens(n):
    """Find all solutions to the N Queens problem using backtracking."""
    solutions = []
    queens = []

    def is_safe(row, col):
        """Check if placing a queen at (row, col) is safe."""
        for r, c in queens:
            if c == col or abs(r - row) == abs(c - col):
                return False
        return True

    def backtrack(row):
        """Place queens row by row."""
        if row == n:
            solutions.append([[r, c] for r, c in queens])
            return
        for col in range(n):
            if is_safe(row, col):
                queens.append([row, col])
                backtrack(row + 1)
                queens.pop()

    backtrack(0)
    return solutions


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    for solution in solve_nqueens(n):
        print(solution)
