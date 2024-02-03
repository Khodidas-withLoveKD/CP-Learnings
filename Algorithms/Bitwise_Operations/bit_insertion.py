"""
Given two 32-bit numbers, N and M, and two-bit positions, i and j.
Write a method to insert M into N such that M starts at bit j and ends at bit i.
You can assume that the bits j through i have enough space to fit all of M. Assuming index start from 0.
Examples:

a)  N = 1024 (10000000000),
    M = 19 (10011),
    i = 2, j = 6
    Output : 1100 (10001001100)
b)  N = 1201 (10010110001)
    M = 8 (1000)
    i = 3, j = 6
    Output: 1217 (10011000001)
"""

# approach
"""
Conserve the bit position from n-1 to i+1 and j-1 to 0
so reset the bit from i to j
do an AND of that changed num with M
"""

def solve(org_num, num, j, i):
    # create the mask to preserve bit from n-1 to i
    mask1 = -1 << (j + 1)
    print(f'mask1 = {mask1}')
    print(f'mask1 BIN = {bin(mask1)}')
    # the mask to preserve bit from j-1 to 0
    mask2 = (1 << i) - 1
    print(f'mask 2 = {mask2}')
    print(f'mask2 BIN = {bin(mask2)}')

    # the mask that will make the zeros from i to j
    mask = mask1 | mask2
    print(f'mask = {mask}')
    print(f'mask BIN = {bin(mask)}')
    # modify the org_num accordingly
    modified_num = org_num & mask
    print(f'modified_num = {modified_num}')
    print(f'modified_num BIN = {bin(modified_num)}')
    # push the num by i bits
    num <<= i
    print(f'num = {num}')
    print(f'num BIN = {bin(num)}')
    # do the OR with num
    modified_num = modified_num | num
    print(f'modified_num = {modified_num}')
    print(f'modified_num BIN = {bin(modified_num)}')
    print(f'ANS = {modified_num}')
    print("======")


solve(1024, 19, 6, 2)
solve(1201, 8, 6, 3)
