#!/usr/bin/python3
import random
number = random.randint(-10000, 10000)
# Lets try to solve it
last_digit_number = number % 10
if number < 0:
        signe = '-'
    else:
        signe = ''

if last_digit_number > 5:
    print("Last digit of", number, "is", last_digit_number, "and is greater than 5")
elif last_digit_number == 0:
    print("Last digit of", number, "is", last_digit_number, "and is 0")
elif last_digit_number < 6 and last_digit_number != 0:
    print("Last digit of", number, "is", last_digit_number, "and is 0")
