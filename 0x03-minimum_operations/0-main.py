#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 26 
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 12 
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

# Test cases

n = 8
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 14
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 15
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 21
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 24
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 7
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 9
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 1
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 25
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 50
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))
