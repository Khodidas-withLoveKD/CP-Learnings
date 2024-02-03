"""
Converting a Real Number (between 0 and 1) to Binary String

Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,
print the binary representation. If the number cannot be represented accurately in binary
with at most 32 characters, print” ERROR:’

Examples:
Input :  (0.625)10
Output : (0.101)2

Input : (0.72)10
Output : ERROR
"""
from decimal import Decimal


max_32_bit_num = 2 ** 31 - 1
def fits_in_32_bits(num):
    return -max_32_bit_num <= num <= max_32_bit_num


def solve(real_num):
    ans = '0.'
    while real_num and len(ans) <= 33:
        mul = real_num * 2
        ans += str(mul)[0]
        # print(f'int(mul) = {int(mul)}')
        # print(f'real_num - int(mul) = {mul - int(mul)}')
        real_num = mul - int(mul)
        # print(f'ANS = {ans}')
        # print(f'len(ans) = {len(ans)}')

    print('ERROR' if len(ans) > 33 else ans)

solve(0.625)
solve(0.72)