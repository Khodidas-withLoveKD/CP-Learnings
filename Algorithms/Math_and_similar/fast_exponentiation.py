"""
Fast Exponentiation: https://www.youtube.com/watch?v=-3Lt-EwR_Hw
"""
import time


def power(i, a):
    if i == 0:
        return 1   # a ** 0 = 1
    if i == 1:
        return a  # a ** 1 = a
    else:
        ans = power(i // 2, a)
        return ans * ans * (a if i % 2 else 1)


def linar_exponentiation(i, a):
    ans = 1
    for j in range(i):
        ans *= a
    return ans


testcases = [0, 1, 2, 4, 7, 10, 20, 200, 2000]
for testcase in testcases:
    start_time = time.time()
    print(power(testcase, 2))
    f_e_time = time.time() - start_time

    start_time = time.time()
    print(linar_exponentiation(testcase, 2))
    l_e_time = time.time() - start_time

    print(f'FE Time = {f_e_time} | LE Time = {l_e_time}')
