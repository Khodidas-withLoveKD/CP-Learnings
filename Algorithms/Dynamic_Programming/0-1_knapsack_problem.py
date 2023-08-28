def knapSack_using_top_down(W, wt, val, n):
    # code here
    def add_item(i, curr_wt):
        if i >= n:
            return 0

        if dp[curr_wt][i] != -1:
            return dp[curr_wt][i]

        item_included_value = 0
        item_included_wt = curr_wt + wt[i]
        if item_included_wt <= W:
            item_included_value = val[i] + add_item(i + 1, item_included_wt)

        item_not_included_value = add_item(i + 1, curr_wt)
        dp[curr_wt][i] = max(item_included_value, item_not_included_value)
        return dp[curr_wt][i]

    dp = [[-1 for i in range(N + 1)] for _ in range(W + 1)]
    return add_item(0, 0)


def knapsack_using_bottom_up(W, wt, val, n):
    # will do a bottom up approach
    # so will require an array to store it
    dp = [[0 for _ in range(W + 1)] for _ in range(N + 1)]
    # initialized with 0 as the base case has 0
    # so if there is 0 item or 0 weight the ans is 0
    # start
    for i in range(1, N+1):
        for j in range(W+1):
            item_included_value = 0
            if j - wt[i-1] >= 0:
                # max of weight inlcuding the item or excluding the item
                item_included_value = val[i-1] + dp[i-1][j - wt[i-1]]  # current val + best val till the previous item and subtracting the current weight
            item_excluded_value = dp[i-1][j]
            dp[i][j] = max(item_included_value, item_excluded_value)

    return dp[N][W]

N = 3
W = 4
wt = [4, 5, 1]
val = [1, 2, 3]
print(knapSack_using_top_down(W, wt, val, N))
print(knapsack_using_bottom_up(W, wt, val, N))