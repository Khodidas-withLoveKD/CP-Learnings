def generate_subsequence(i, curr_subsequence):
    if i == n:
        ans.append(curr_subsequence)
        return

    generate_subsequence(i+1, curr_subsequence + our_str[i])
    generate_subsequence(i+1, curr_subsequence)


def get_ss(s, i):
    j = 0
    ss = ""
    # we will check each bit and check if it is set
    # if set, add that char to ss
    bit_checker = 1 << (len(s) - 1)
    while bit_checker > 0:
        if i & bit_checker:  # if the last bit is set
            ss += s[j]
        j += 1
        bit_checker = bit_checker >> 1

    if ss:
        ans.append(ss)


def gen_subsequence_using_bit_manipulation(our_str):
    # go from 1 to len of string in binary form as it will be more efficient
    subsequences = []
    for i in range(1, 1 << len(our_str)):
        subsequences.append(get_ss(our_str, i))

our_str = "abcd"
n = len(our_str)
ans = []

generate_subsequence(0, "")
gen_subsequence_using_bit_manipulation(our_str)

for s in ans:
    print(s)
