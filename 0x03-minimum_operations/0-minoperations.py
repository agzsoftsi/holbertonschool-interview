#!/usr/bin/python3
"""
In a text file, there is a single character H. Your text editor
can execute only two operations in this file: Copy All and Paste.
Given a number n, write a method that calculates the fewest number
of operations needed to result in exactly n H characters in the file.

"""


def countProcess(num):
    """ Return list of process until n H """
    con = 1
    p_list = []
    val = num
    while val != 1:
        con += 1
        if val % con == 0:
            while (val % con == 0 and val != 1):
                val /= con
                p_list.append(con)

    return p_list


def minOperations(n):
    """ Return sum of process until n H """
    if n < 2 or type(n) is not int:
        return 0
    values = countProcess(n)
    return sum(values)
