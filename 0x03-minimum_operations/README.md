![](Top.png)

# Requirements

## General

> - Allowed editors: vi, vim, emacs
> - All your files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
> - All your files should end with a new line
> - The first line of all your files should be exactly #!/usr/bin/python3
> - A README.md file, at the root of the folder of the project, is mandatory
> - Your code should use the PEP 8 style (version 1.7.x)
> - All your files must be executable


## Whiteboarding

![](whiteboard1.jpg)

## Task

**0. Minimum Operations**

File: [0-minoperations.py](0-minoperations.py/) - [main_0.py](main_0.py/)

In a text file, there is a single character H. Your text editor can execute only two operations in this file: Copy All and Paste. Given a number n, write a method that calculates the fewest number of operations needed to result in exactly n H characters in the file.

- Prototype: def minOperations(n)
- Returns an integer
- If n is impossible to achieve, return 0

Example:

n = 9

H => Copy All => Paste => HH => Paste =>HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

Number of operations: 6

```sh
carrie@ubuntu:~/0x03-minoperations$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

n = 12
print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

carrie@ubuntu:~/0x03-minoperations$
```

```sh
carrie@ubuntu:~/0x03-minoperations$ ./0-main.py
Min number of operations to reach 4 characters: 4
Min number of operations to reach 12 characters: 7
carrie@ubuntu:~/0x03-minoperations$
```

