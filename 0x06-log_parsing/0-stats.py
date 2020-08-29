#!/usr/bin/python3
"""
Task - Script that reads stdin line by line and computes metrics
"""

import sys


if __name__ == "__main__":
    st_code = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0}
    count = 1
    file_size = 0

    def parse_line(line):
        """ Read, parse and grab data"""
        try:
            parsed_line = line.split()
            status_code = parsed_line[-2]
            if status_code in st_code.keys():
                st_code[status_code] += 1
            return int(parsed_line[-1])
        except Exception:
            return 0

    def print_stats():
        """print stats in ascending order"""
        print("File size: {}".format(file_size))
        for key in sorted(st_code.keys()):
            if st_code[key]:
                print("{}: {}".format(key, st_code[key]))

    try:
        for line in sys.stdin:
            file_size += parse_line(line)
            if count % 10 == 0:
                print_stats()
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
