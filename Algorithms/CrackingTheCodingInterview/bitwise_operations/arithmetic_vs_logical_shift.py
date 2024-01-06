def arithmetic_right_shift(num, times):
    for _ in range(times):
        num >>= 1

    return num


def logical_right_shift(num, times):
    for _ in range(times):
        num = num >> 1

    return num


num = -93242
count = 40
print(arithmetic_right_shift(num, count))
print(logical_right_shift(num, count))