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


def print_bin_and_num(num, name):
    print(f'{name} = {num} | {name}_bin = {bin(num)}')

def get_next_smallest_and_largest_num_using_binary_str_manipulation(num):
    # this method gives incorrect answers
    bin_num = bin(num)[2:]

    ls_zero_index = get_ls_zero_index(bin_num)
    # print(f'zero_index = {ls_zero_index}')
    smallest = largest = num
    if ls_zero_index != -1:
        # shift the zero to left, decrease the value
        # print(f'bin_num = {bin_num}')
        smallest_bin = bin_num[:ls_zero_index - 1] + '0' + '1' + bin_num[ls_zero_index + 1:]
        # print(f'smallest_bin = {smallest_bin}')
        smallest = int(smallest_bin, 2)

        # shift the zero to right to increase the value
        if ls_zero_index != len(bin_num) - 1:  # the ls_zero_index is not last then shift right
            largest_bin = bin_num[:ls_zero_index] + '1' + '0' + bin_num[ls_zero_index + 2:]
            # print(f'largest_bin = {largest_bin}')
            largest = int(largest_bin, 2)

    print(f'smallest = {smallest} | num = {num} | largest = {largest}')
    print(f'=======')


def get_next_nums_by_bit_manipulation(num):
    def get_zeros_index_and_ones_count(bin_num):
        index, ones_count = len(bin_num), 0
        for i, bit in enumerate(bin_num[::-1]):
            if bit == '0':
                if ones_count > 0:
                    index = i
                    break
            else:
                ones_count += 1

        return index, ones_count

    def get_next_bigger_by_bit_manipulation(num):
        bin_num = bin(num)[2:]
        # print_bin_and_num(num, 'num')
        # find the rightmost zero which has atleast one 1 on right
        index, ones_count = get_zeros_index_and_ones_count(bin_num)
        # print(f'index = {index} | ones_count = {ones_count}')
        # make the index as 1 to increase the num
        swap_mask = 1 << index
        # print_bin_and_num(swap_mask, 'swap_mask')
        num = num | swap_mask
        # print_bin_and_num(num, 'After swap num')
        # will keep the zeros to the leftmost and ones on the rightmost
        # to keep the num big and as close as possible to original num
        reset_mask = -1 << index
        # print_bin_and_num(reset_mask, 'reset_mask')
        num = num & reset_mask
        # print_bin_and_num(num, 'After reset reset_mask')
        if ones_count > 1:
            ones_mask = 1 << (ones_count-2)
            # print_bin_and_num(ones_mask, 'ones_mask')
        # make the all the zeros
        # num = num & reset_mask
        # print_bin_and_num(num, 'After swap num')
        # add all the ones_count - 1 nums to the right most
            num = num | ones_mask
            # print_bin_and_num(num, 'After adding ones_mask')

        return num

    def get_ones_index_and_zeros_count(bin_num):
        index, zeros_count, ones_count = len(bin_num), 0, 0
        for i, bit in enumerate(bin_num[::-1]):
            if bit == '1':
                ones_count += 1
                if zeros_count > 0:
                    index = i
                    break
            else:
                zeros_count += 1

        return index, zeros_count, ones_count

    def get_next_smaller_by_bit_manipulation(num):
        # STEP 1: find the index and all
        bin_num = bin(num)[2:]
        # print_bin_and_num(num, 'num')
        # find the rightmost one which has at least one zero on right
        # find the index, and zeros_count
        index, zeros_count, ones_count = get_ones_index_and_zeros_count(bin_num)
        # print(f'index = {index} | zeros_count = {zeros_count} | ones_count = {ones_count}')
        # swap the one with zero and reset the right bits
        # STEP 2: replace that one on index with 0 and reset
        swap_and_reset_mask = -1 << (index + 1)
        # print_bin_and_num(swap_and_reset_mask, 'swap_and_reset_mask')
        num &= swap_and_reset_mask
        # print_bin_and_num(num, 'after swap and reset mask NUM')
        # now shift all the ones near to index and push zero to the right
        # get the mask
        # all the left should be 1s
        ones_mask = (1 << ones_count) - 1
        # print_bin_and_num(ones_mask, 'OUTSIDE ones_mask')
        if zeros_count > 1:
            ones_mask = ones_mask << (zeros_count - 1)
            # print_bin_and_num(ones_mask, 'INSIDE IF ones_mask')

        num |= ones_mask
        # print_bin_and_num(num, 'num after ones_mask')

        return num

    next_bigger = get_next_bigger_by_bit_manipulation(num)
    next_smaller = get_next_smaller_by_bit_manipulation(num)
    # print(f' num = {num} | bigger = {next_bigger} \n=====')
    print(f'===========\nnum = {num} | Bigger = {next_bigger} | Smaller = {next_smaller} \n=========')

# TODO: get the edge cases
testcases = [73, 5, 11, 2, 3, 15, 0, 1]
greater = [74, 6, 13, 4, 5, 23, -1, 2]
smaller = [70, 3, 7, 1, -1, -1, -1, -1]

# get_next_nums_by_bit_manipulation(5)
for num in testcases:
    get_next_nums_by_bit_manipulation(num)











