def get_LIS_by_recursion(i, prev_index):
    # base case: when no nums remained to check
    if i == n:
        return 0

    include = 0
    if prev_index == -1 or arr[prev_index] < arr[i]:
        include = 1 + get_LIS_by_recursion(i+1, i)

    exclude = 0 + get_LIS_by_recursion(i+1, prev_index)

    return max(exclude, include)


def get_length_of_LIS_by_bottom_up(arr):
    n = len(arr)
    dp = [1] * n

    for i in range(n-1, -1, -1):
        for j in range(n-1, i-1, -1):
            if arr[i] < arr[j]:
                dp[i] = max(dp[i], 1 + dp[j])

    # print(dp)
    return max(dp)


# arr = [4, 1, 2 ,3]
arr = [4, 2, 6, 7, 3, 4, 5]
n = len(arr)
print(get_LIS_by_recursion(0, -1))
print(get_length_of_LIS_by_bottom_up(arr))