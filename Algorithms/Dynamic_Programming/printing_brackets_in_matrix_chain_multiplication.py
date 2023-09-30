import math


# first part is forming the dp matrix
def get_min_multiplication_pattern_bracket(arr):
    # will form the memo table
    # base case is i == j => 0 as doing mul with one element is not possible
    n = len(arr)
    dp = [[0 for _ in range(n)] for _ in range(n)]
    bracket_point = [[j for i in range(n)] for j in range(n)]

    # will increase the range i to j in such that i-j is one than 2 and so on....
    for seg_len in range(2, n):
        for i in range(n-1):  # i is the start
            # the breaker point k will lie between i and j
            j = i + seg_len
            if j < n:
                dp[i][j] = math.inf
                for k in range(i, j):
                    curr_cost = dp[i][k] + dp[k][j] + (arr[i] * arr[k] * arr[j])
                    if curr_cost < dp[i][j]:
                        dp[i][j] = curr_cost
                        bracket_point[i][j] = k

    print(dp[0][n-1])
    return bracket_point, dp[0][n-1]


def get_bracketed_string(i, j, bracket_points):
    global alpha
    # make a bracket of type (A(BC))D etc
    # our condition for creating, pass i, j and bracket_point(k)
    # create a string from given i and then create bracketed strings from i+1 to j
    if i == j or i == j - 1:
        print(alpha, end="")
        alpha = chr(ord(alpha) + 1)
        return None

    print("(", end="")
    # print(f'alpha = {alpha}')
    # alpha_prev = alpha
    # alpha = chr(ord(alpha) + 1)  # increase_alpha
    get_bracketed_string(i, bracket_points[i][j], bracket_points)
    get_bracketed_string(bracket_points[i][j], j, bracket_points)

    print(")", end="")


alpha = "A"
arr = [1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5]  # [3,3,3]  # [1, 2, 3, 4, 5]  # [40, 20, 30, 10, 30]
bracket_points, cost = get_min_multiplication_pattern_bracket(arr)
n = len(arr)
# print_brackets(0, n-1, bracket_points)
get_bracketed_string(0, n-1, bracket_points)
