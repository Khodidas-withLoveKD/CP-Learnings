"""
https://www.geeksforgeeks.org/find-longest-sequence-1s-binary-representation-one-flip/

Give an integer n. We can flip exactly one bit. Write code to find the length of the
longest sequence of 1 s you could create.

Examples:
Input : 1775
Output : 8
Binary representation of 1775 is 11011101111.
After flipping the highlighted bit, we get
consecutive 8 bits. 11011111111.
Input : 12
Output : 3
Input : 15
Output : 5
Input : 71
Output: 4
Binary representation of 71 is 1000111.
After flipping the highlighted bit, we get
consecutive 4 bits. 1001111.
"""


def get_zeros_arr(bits):
    zeros = []
    for i, bit in enumerate(bits):
        if bit == '0':
            zeros.append(i)

    return zeros


def get_longest_1s_length(num):
    # get the bin repr
    bits = bin(num)[2:]
    print(f'bits = {bits}')
    # get the position of zeros
    zeros = get_zeros_arr(bits)
    print(f'zeros = {zeros}')
    left_i, right_i = -1, 1
    ans = -1 if len(zeros) else len(bits)
    # traverse through all the zeros position
    for i, curr_pos in enumerate(zeros):
        right_i = zeros[i+1] if i < len(zeros) - 1 else len(bits)
        ones_len = right_i - left_i - 1
        print(f'ones_len = {ones_len}')
        ans = max(ans, ones_len)
        # after everything is done prepare for next
        left_i = curr_pos

    print(f'ans = {ans}')
    # keep track of left_i, curr_i, right_i

test_cases = [1775, 12, 15, 71]
ans = [8, 3, 5, 4]

for test_case in test_cases:
    get_longest_1s_length(test_case)
