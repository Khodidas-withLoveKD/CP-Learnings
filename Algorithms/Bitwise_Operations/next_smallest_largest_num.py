"""
https://www.geeksforgeeks.org/closest-next-smaller-greater-numbers-number-set-bits/

Closest (or Next) smaller and greater numbers with same number of set bits
Given a positive integer n, print the next smallest and the previous largest number
that has the same number of 1 bit in their binary representation.

Examples:

Input : n = 5
Output : Closest Greater = 6
         Closest Smaller = 3
Note that 5, 6 and 3 have same number of
set bits.

Input : n = 11
Output : Closest Greater = 13
         Closest Smaller = 7
"""

# the approach is straightforward
# the magic lies in the least significant zero left or right
# shifting it left will decrease the value, vice versa for right


def get_ls_zero_index(num):
    index = -1
    for i, bit in enumerate(num):
        if bit == '0':
            index = i

    return index


def get_next_smallest_and_largest_num_using_binary(num):
    bin_num = bin(num)[2:]

    ls_zero_index = get_ls_zero_index(bin_num)
    print(f'zero_index = {ls_zero_index}')
    smallest = largest = num
    if ls_zero_index != -1:
        # shift the zero to left, decrease the value
        print(f'bin_num = {bin_num}')
        smallest_bin = bin_num[:ls_zero_index - 1] + '0' + '1' + bin_num[ls_zero_index + 1:]
        print(f'smallest_bin = {smallest_bin}')
        smallest = int(smallest_bin, 2)

        # shift the zero to right to increase the value
        if ls_zero_index != len(bin_num) - 1:  # the ls_zero_index is not last then shift right
            largest_bin = bin_num[:ls_zero_index] + '1' + '0' + bin_num[ls_zero_index + 2:]
            print(f'largest_bin = {largest_bin}')
            largest = int(largest_bin, 2)

    print(f'smallest = {smallest} | num = {num} | largest = {largest}')
    print(f'=======')


testcases = [5, 11, 2, 3]
for tc in testcases:
    get_next_smallest_and_largest_num_using_binary(tc)















