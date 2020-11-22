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

**0. Rain**

File: [0-rain.py](0-rain.py/) - [0-main.py](0-main.py/)

Given a list of non-negative integers representing walls of width 1, calculate how much water will be retained after it rains.

- Prototype: def rain(walls)
- walls is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
- If the list is empty return 0.

0-main.py

```sh
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))

```


Testing

```sh
jesse@ubuntu:~/0x10$ 
jesse@ubuntu:~/0x10$ ./0_main.py
6
jesse@ubuntu:~/0x10$ 
```