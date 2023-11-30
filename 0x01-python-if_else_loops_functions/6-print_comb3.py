#!/usr/bin/python3
for number1 in range(9):
    for number2 in range(number1 + 1, 10):
        if number1 * 10 + number2 < 89:
            print("{:d}{:d}".format(number1, number2), end=", ")
print("{:d}".format(89))
