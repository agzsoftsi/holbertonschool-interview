![](Top.png)

# Requirements

## General

> - Allowed editors: vi, vim, emacs
> - All your files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
> - All your files should end with a new line
> - The first line of all your files should be exactly #!/usr/bin/python3
> - A README.md file, at the root of the folder of the project, is mandatory
> - Your code should use the PEP 8 style (version 1.7.x)
> - You are not allowed to import any module
> - All modules and functions must be documented
> - All your files must be executable



## Whiteboarding

![](whiteboard1.jpg)

## Task

**0. Pascal's Triangle**

File: [0-rain.py](0-rain.py/) - [0-main.py](0-main.py/)

Create a function def pascal_triangle(n): that returns a list of lists of integers representing the Pascal’s triangle of n:

- Returns an empty list if n <= 0
- You can assume n will be always an integer


```sh
guillaume@ubuntu:~/0x1F$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle

def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))

guillaume@ubuntu:~/0x1F$ 
guillaume@ubuntu:~/0x1F$ ./0-main.py
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
guillaume@ubuntu:~/0x1F$ 
```