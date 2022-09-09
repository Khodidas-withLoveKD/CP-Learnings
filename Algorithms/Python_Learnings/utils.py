import math


def find_max(numbers):
    max_num = -math.inf
    # max_num = numbers[0]
    for num in numbers:
        if num > max_num:
            max_num = num
    return max_num
