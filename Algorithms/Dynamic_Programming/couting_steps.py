# https://www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/
"""
A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

Examples:

Input : 4
Output : 7
Explanation:
Below are the seven ways
 1 step + 1 step + 1 step + 1 step
 1 step + 2 step + 1 step
 2 step + 1 step + 1 step
 1 step + 1 step + 2 step
 2 step + 2 step
 3 step + 1 step
 1 step + 3 step

Input : 3
Output : 4
Explanation:
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step
"""


def count_steps_using_recursion(n):
    def climb(i, n):
        if i > n:
            return 0
        if i == n:
            return 1

        return climb(i+1, n) + climb(i+2, n) + climb(i+3, n)

    ans = climb(1, n) + climb(2, n) + climb(3, n)
    print(f'recursion ans = {ans}')


def count_steps_using_dynamic_programming(n):
    cache = [0] * (n+1)
    cache[n] = 1
    for i in range(n-1, 0, -1):
        for j in range(1, 4):
            if i + j <= n:
                cache[i] += cache[i+j]

    ans = cache[1] + cache[2] + cache[3]
    print(f'DP ans = {ans}')


def counting_steps_using_four_variables(n):
    # defining first three steps
    a = 1
    b = 2
    c = 4
    d = 0

    if n == 0 or n == 1 or n == 2:
        print(n)
        return
    if n == 3:
        print(c)
        return

    for _ in range(4, n + 1):
        d = a + b + c
        a = b
        b = c
        c = d
    print(d)


testcases = [3, 4, 5, 6, 7, 8, 9, 10]
answers = [4, 7, 13, 24, 44, 81, 149, 274]

for testcase in testcases:
    # count_steps_using_recursion(testcase)
    # count_steps_using_dynamic_programming(testcase)
    counting_steps_using_four_variables(testcase)
