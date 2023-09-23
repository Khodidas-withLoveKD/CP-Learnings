import math


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


arr = [1, 2, 3, 4]
print(f'FINAL ANS = {do_mcm(0, len(arr) - 1)}')
