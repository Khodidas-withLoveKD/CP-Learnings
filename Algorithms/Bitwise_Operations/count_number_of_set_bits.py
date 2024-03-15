"""https://www.geeksforgeeks.org/count-set-bits-in-an-integer/"""


def get_no_of_set_bits(num):
    # Using the Brian-Kernighan's Algorithm
    count = 0
    n = num
    while n:
        count += 1
        n &= n-1

    print(f'num = {num} | set bits = {count} | bin = {bin(n)[2:]}')


testcases = [15, 2, 3, 73, 0]
for n in testcases:
    get_no_of_set_bits(n)
