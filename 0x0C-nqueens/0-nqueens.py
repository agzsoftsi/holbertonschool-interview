#!/usr/bin/python3
"""
   Description: The N queens puzzle is the challenge of placing N non-attacking
                queens on an N×N chessboard. Write a program that solves the N
                queens problem.
   Usage: nqueens N:
          If the user called the program with the wrong number of arguments,
          print Usage: nqueens N, followed by a new line, and exit with the
          status 1
   where N must be an integer greater or equal to 4:
          If N is not an integer, print N must be a number, followed by a new
          line, and exit with the status 1
          If N is smaller than 4, print N must be at least 4, followed by a new
          line, and exit with the status 1
   The program should print every possible solution to the problem:
          One solution per line
          Format: see example
          You don’t have to print the solutions in a specific order
   You are only allowed to import the sys module
"""


import sys


""" error handling for argv[1] """

if __name__ == "__main__":
    if len(sys.argv) == 1 or len(sys.argv) > 2:
        print("Usage: nqueens N")
        sys.exit(1)
    N = sys.argv[1]
    try:
        N_int = int(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N_int < 4:
        print("N must be at least 4")
        sys.exit(1)

""" n queens methods """

    coords = []

    def isSafe(coords, row, col):
        """ Checks if queen can be placed in coord of board.
            Returns True if can, else False
        """
        rows = []
        cols = []
        diag_r = []
        diag_l = []

        for square in coords:
            rows.append(square[0])
            cols.append(square[1])
            diag_r.append(square[0] + square[1])
            diag_l.append(square[1] - square[0])
        if row in rows or col in cols:
            return False
        if row + col in diag_r or col - row in diag_l:
            return False

        return True

    def solveNqueens(coords, col, safe_queens=[]):
        """ Creates array of queen positions
            Returns array
        """
        for x in range(N_int):
            if isSafe(coords, x, col):
                coords.append([x, col])
                if col == N_int - 1:
                    safe_queens.append(coords.copy())
                    del coords[-1]
                else:
                    solveNqueens(coords, col + 1)

        if len(coords):
            del coords[-1]
        return safe_queens

""" sets base case for recursion """

    coords = solveNqueens(coords, 0)

""" prints coords of squares for safe queens """
    for squares in coords:
        print(squares)