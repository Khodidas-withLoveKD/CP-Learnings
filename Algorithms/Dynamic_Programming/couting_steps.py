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
    print(ans)


testcases = [3, 4, 5, 6, 7, 8, 9, 10]
ans = [4, 7, 13, 24, 44, 81, 149, 274]
for testcase in testcases:
    count_steps_using_recursion(testcase)
