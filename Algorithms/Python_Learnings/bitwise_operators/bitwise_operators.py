# global vars
a = 0b1010
b = 0b0110
a_as_num = 10
b_as_num = 6

# AND
print('=== AND ====')
print(f'BINARY a & b = {a & b}')
print(f'NUM a & b = {a_as_num & b_as_num}')

# OR
print('=== OR ====')
print(f'BINARY a | b = {a | b}')
print(f'NUM a | b = {a_as_num | b_as_num}')

# XOR
print('=== XOR ====')
print(f'BINARY a ^ b = {a ^ b}')
print(f'NUM a ^ b = {a_as_num ^ b_as_num}')

# NOT
print('=== NOT ====')
print(f'BINARY ~a = {~a} | a = {a}')
print(f'NUM ~a = {~a_as_num} | a = {a_as_num}')

# LEFT_SHIFT
print('=== LEFT_SHIFT ====')
print(f'BINARY a << 2 = {a << 2}')
print(f'NUM a << 2 = {a_as_num << 2}')

# RIGHT_SHIFT
print('=== RIGHT_SHIFT ====')
print(f'BINARY a >> 2 = {a >> 2}')
print(f'NUM a >> 2 = {a_as_num >> 2}')

