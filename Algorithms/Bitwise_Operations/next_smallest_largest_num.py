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
        index, zeros_count, ones_count = len(bin_num), 0, 0
        for i, bit in enumerate(bin_num[::-1]):
            if bit == '0':
                zeros_count += 1
                if ones_count > 0:
                    index = i
                    break
            else:
                ones_count += 1

        return index, zeros_count, ones_count

    def get_next_bigger_by_bit_manipulation(num):
        bin_num = bin(num)[2:]
        # print_bin_and_num(num, 'num')
        # find the rightmost zero which has atleast one 1 on right
        index, zeros_count, ones_count = get_zeros_index_and_ones_count(bin_num)
        # print(f'index = {index} | ones_count = {ones_count}')
        if ones_count == 0:
            return 0
        # make the index as 1 to increase the num
        swap_mask = 1 << index
        # print_bin_and_num(swap_mask, 'swap_mask')
        num = num | swap_mask
        # print_bin_and_num(num, 'After swap num')
        # will keep the zeros to the leftmost and ones on the rightmost
        # to keep the num big and as close as possible to original num
        # shift only the ones to someleft


        reset_mask = -1 << index
        # print_bin_and_num(reset_mask, 'reset_mask')
        num = num & reset_mask
        # print_bin_and_num(num, 'After reset num')
        ones_mask = (1 << ones_count-1) - 1
        # print_bin_and_num(ones_mask, 'ones_mask')
        num = num | ones_mask
        # print_bin_and_num(num, 'after ones_mask num')

        # if ones_count > 1:
        #     ones_mask = 1 << (ones_count-2)
        #     print_bin_and_num(ones_mask, 'ones_mask')
        # # make the all the zeros
        # # num = num & reset_mask
        #     print_bin_and_num(num, 'After swap num')
        # # add all the ones_count - 1 nums to the right most
        #     num = num | ones_mask
        #     print_bin_and_num(num, 'After adding ones_mask')

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
        if zeros_count == 0:
            return -1
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
    print(f'=====\nnum = {num} | Bigger = {next_bigger} | Smaller = {next_smaller} \n====')


def get_next_nums_book_soln_bit_manipulation(num):
    def get_zeros_and_ones_count(num):
        zeros_count = ones_count = 0
        # zeros count has to be done first very intentionally
        # get zeros count
        while num & 1 == 0 and num != 0:
            zeros_count += 1
            num >>= 1
            # print(f'num = {num}')
        # print(f'zeros_count = {zeros_count}')

        # get the ones count,
        while num & 1 == 1:
            ones_count += 1
            num >>= 1
            # print(f'num = {num}')
        # print(f'ones_count = {ones_count}')

        return zeros_count, ones_count

    def get_next_bigger_num(num):
        # STEP 1: get the count of 0s and 1s
        zeros_count, ones_count = get_zeros_and_ones_count(num)
        if zeros_count + ones_count == 0:
            return -1
        # STEP 2: get the index where the rightmost zero has at least one 1 on the right
        index = zeros_count + ones_count  # amazing
        set_ones_mask = 1 << index
        num |= set_ones_mask
        # flip that index to 1 and reset the right ones
        flip_mask = ~((1 << index) - 1)
        # print_bin_and_num(flip_mask, 'flip_mask')
        num &= flip_mask
        # print_bin_and_num(num, 'after flip_mask num')
        # now index is 1 and have to move the other zeros closer to it and ones far from it
        # STEP 4: Create the mask and apply
        ones_mask = (1 << ones_count-1) - 1
        # print_bin_and_num(ones_mask, 'ones_mask')
        num |= ones_mask
        # print_bin_and_num(num, 'after ones_mask num')

        return num

    def get_ones_and_zeros_count(num):
        # notice we try to find ones count first
        ones_count, zeros_count = 0, 0
        while num & 1 == 1:
            ones_count += 1
            num >>= 1

        while num & 1 == 0 and num != 0:
            zeros_count += 1
            num >>= 1

        return ones_count, zeros_count

    def get_next_smaller_num(num):
        # will use the similar appraoch as big one
        ones_count, zeros_count = get_ones_and_zeros_count(num)
        if zeros_count == 0:
            return -1
        # now we want the zero on left and ones on right
        # flip the index bit and reset the right of it
        index = ones_count + zeros_count
        reset_and_flip_mask = ~((1 << (index+1)) - 1)
        num &= reset_and_flip_mask
        # append ones to the rightmost
        ones_mask = ((1 << ones_count+1) - 1) << (zeros_count-1)
        num |= ones_mask

        return num

    next_bigger = get_next_bigger_num(num)
    next_smaller = get_next_smaller_num(num)
    print(f'--\nnum = {num} | bigger = {next_bigger} | smaller = {next_smaller} \n--')


def get_next_nums_by_arithmetic(num):
    def get_zero_first_and_ones_count(num):
        zeros_count, ones_count = 0, 0
        while num & 1 == 0 and num != 0:
            zeros_count += 1
            num >>= 1

        while num & 1 == 1:
            ones_count += 1
            num >>= 1

        return zeros_count, ones_count

    def get_next_bigger_by_arithmetic(num):
        zeros_count, ones_count = get_zero_first_and_ones_count(num)

        if zeros_count + ones_count == 0:
            return -1

        # if n = 1001100 (76)
        # make it 1010000
        # add 11 to it -> 2 ** (zeros_count) - 1 => n = 1001111
        # add 1 to it => n = 101_000_00
        # add ones_count-1 ones to it -> 2 ** (ones_count - 1) - 1 => n = 101_000_01
        # final = 2 ** (zeros_count) - 1 + 1 + 2**(ones_count-1) - 1
        return num + (1 << zeros_count) + (1 << (ones_count-1)) - 1

    def get_ones_first_and_zeros_count(num):
        zeros_count, ones_count = 0, 0
        while num & 1 == 1:
            ones_count += 1
            num >>= 1

        while num & 1 == 0 and num != 0:
            zeros_count += 1
            num >>= 1

        return ones_count, zeros_count

    def get_next_smaller_by_arithmetic(num):
        ones_count, zeros_count = get_ones_first_and_zeros_count(num)
        if zeros_count == 0:
            return -1

        # if n = 100_100_011 -> convert n = 100_011_000
        # start from right to make it work
        # reset the right trailing zeros -> n -= 2 ** (ones_count) - 1 => n = 100_100_000
        # make the 1 bit to zero and also do something to bring the ones to the left -> n -= 1 => n = 100_011_111
        # make the trailing zeros_count 1s to 0 -> n -= 2**(zeros_count-1) - 1 => n = 100_011_000
        # final n - 2**(ones_count) + 1 - 1 - 2**(zeros_count-1) + 1
        return num - (1 << ones_count) + 1 - (1 << (zeros_count-1))

    next_bigger = get_next_bigger_by_arithmetic(num)
    next_smaller = get_next_smaller_by_arithmetic(num)
    print(f'--\nnum = {num} | bigger = {next_bigger} | smaller = {next_smaller}\n--')


testcases = [73, 5, 11, 2, 3, 15, 0, 1]
greater = [74, 6, 13, 4, 5, 23, -1, 2]
smaller = [70, 3, 7, 1, -1, -1, -1, -1]

for num in testcases:
    get_next_nums_by_arithmetic(num)











