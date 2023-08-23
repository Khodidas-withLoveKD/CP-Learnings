def knapSack(W, wt, val, n):
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


N = 3
W = 4
wt = [4, 5, 1]
val = [1, 2, 3]
print(knapSack(W, wt, val, N))
