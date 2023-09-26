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

def print_2d_arr(arr):
    for row in arr:
        print(row)


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
    ans = do_mcm(0, n - 1)
    # print_2d_arr(dp)
    return ans


def solve_mcm_using_bottom_up(arr):
    n = len(arr)
    dp = [[0 for _ in range(n)] for _ in range(n)]

    # will solve for all the two length arr
    # which will help solving for 3 length and so on...
    # the segment should start from 2 and go on till 0 + segment == n-1
    for segment in range(2, n):
        for i in range(n-1):  # i will start from 0 and go till n-2
            # the segment will be i, j
            # where j = i + segment
            # and should go only if j < n
            j = i + segment
            if j < n:
                dp[i][j] = math.inf
                # print(f'i = {i} | j = {j}')
                # k should be in such a way that i+k < j
                for k in range(1, j - i):
                    # print(f'i = {i} | j = {j} | k = {k}')
                    cost = dp[i][i+k] + dp[i+k][j] + (arr[i] * arr[i+k] * arr[j])
                    dp[i][j] = min(cost, dp[i][j])
                    # print(f'cost = {cost} | dp[{i}][{j}] = {dp[i][j]}')

    # print_2d_arr(dp)
    return dp[0][n-1]


# arr = [1, 2, 3, 4]
# arr = [1, 2, 3, 4, 3]
arr = [1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5]
print(f'Recursion ANS = {solve_mcm_using_recursion(arr)}')
print(f'Top Down ANS = {solve_mcm_using_dp_top_down(arr)}')
print(f'Bottom UP ANS = {solve_mcm_using_bottom_up(arr)}')
