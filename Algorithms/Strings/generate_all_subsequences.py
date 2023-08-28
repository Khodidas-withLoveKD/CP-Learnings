def generate_subsequence(i, curr_subsequence):
    if i == n:
        ans.append(curr_subsequence)
        return

    generate_subsequence(i+1, curr_subsequence)
    generate_subsequence(i+1, curr_subsequence + our_str[i])


our_str = "abcd"
n = len(our_str)
ans = []

generate_subsequence(0, "")

for s in ans:
    print(s)
