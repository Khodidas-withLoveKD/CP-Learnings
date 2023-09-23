import math


def solve_mcm_using_recursion(arr):
    def do_mcm(i, n):
        ans = math.inf
        if n - 1 == i:
            return 0

        for j in range(1, n - i):
            cost_of_multiplying_current_partition = arr[i] * arr[i + j] * arr[n]
            cost_of_multiplying_left_partition = do_mcm(i, i + j)
            cost_of_multiplying_right_partition = do_mcm(i + j, n)
            total_cost = cost_of_multiplying_current_partition + \
                         cost_of_multiplying_left_partition + cost_of_multiplying_right_partition
            ans = min(ans, total_cost)

        return ans

    return do_mcm(0, len(arr) - 1)


def solve_mcm_using_dp_top_down(arr):
    def do_mcm(i, n):
        # if ans already calculated
        if dp[i][n] != -1:
            return dp[i][n]

        ans = math.inf
        if n - 1 == i:
            return 0

        for j in range(1, n - i):
            cost_of_multiplying_current_partition = arr[i] * arr[i + j] * arr[n]
            cost_of_multiplying_left_partition = do_mcm(i, i + j)
            cost_of_multiplying_right_partition = do_mcm(i + j, n)
            total_cost = cost_of_multiplying_current_partition + \
                         cost_of_multiplying_left_partition + cost_of_multiplying_right_partition
            ans = min(ans, total_cost)

        dp[i][n] = ans
        return dp[i][n]

    n = len(arr)
    dp = [[-1 for _ in range(n)] for _ in range(n)]
    return do_mcm(0, n - 1)

# arr = [1, 2, 3, 4]
arr = [1, 2, 3, 4, 3]
print(f'Recursion ANS = {solve_mcm_using_recursion(arr)}')
print(f'Top Down ANS = {solve_mcm_using_recursion(arr)}')
