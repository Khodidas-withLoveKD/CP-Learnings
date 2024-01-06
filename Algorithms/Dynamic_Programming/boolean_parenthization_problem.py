"""
https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
"""


def print_arr(arr):
    for row in arr:
        print(row)


def print_both_arrs(arr1, arr2):
    print('Trues')
    print_arr(arr1)
    print('FALSEs')
    print_arr(arr2)


def get_ways_to_paranthize_expression(expr):
    n = len(expr)
    opr_len = (n // 2)
    symbols_len = n - opr_len
    # print(f'opr_len = {opr_len} | symbols_len = {symbols_len}')
    T = [[0 for _ in range(symbols_len)] for _ in range(symbols_len)]
    F = [[0 for _ in range(symbols_len)] for _ in range(symbols_len)]

    for i in range(symbols_len):
        T[i][i] = 1 if expr[2 * i] == 'T' else 0
        F[i][i] = 1 if expr[2 * i] == 'F' else 0
    # print_both_arrs(T, F)

    # increase seg_len from 2 to sl:
    for seg_len in range(2, symbols_len + 1):
        # print('============')
        # print(f'seg_len = {seg_len}')
        # for each index of symbols
        for i in range(symbols_len):
            # print(f'i ABOVE = {i}')
            # each partition index(k) should go from i to i + seg_len - 1
            if i + seg_len - 1 >= symbols_len:
                break

            j = i + seg_len - 1
            # print(f'j ABOVE= {j}')
            for k in range(i, j):
                # print(f'k = {k}')
                # do all the calculations
                #  will be based on the sybol itself
                # the symbol will be next to partition_index
                opr = expr[2 * k + 1]  # TODO: correct this
                # print(f'seg_len = {seg_len} | i = {i}, j = {j}, k = {k} | opr = {opr}')

                # get the total
                total_i_k = T[i][k] + F[i][k]
                # print(f'T[{i}][{k}] + F[{i}][{k}] = total_i_k = {total_i_k}')

                total_k_j = T[k + 1][j] + F[k+1][j]
                # print(f'T[{k+1}][{j}] + F[{k+1}][{j}] = total_k_j = {total_k_j}')

                if opr == '&':
                    T[i][j] += T[i][k] * T[k+1][j]
                    F[i][j] += (total_i_k * total_k_j) - T[i][k] * T[k+1][j]  # TODO: Correct this
                elif opr == '|':
                    F[i][j] += F[i][k] * F[k+1][j]
                    T[i][j] += (total_i_k * total_k_j) - F[i][k] * F[k+1][j]
                elif opr == '^':
                    T[i][j] += T[i][k] * F[k+1][j] + T[k+1][j] * F[i][k]
                    F[i][j] += T[i][k] * T[k+1][j] + F[i][k] * F[k+1][j]
                # print_both_arrs(T, F)
                # print('-------')

    # print_both_arrs(T, F)

    # ans is the range 0 to n-1
    # TODO: to check this
    print(f'ans = {T[0][symbols_len-1]}')


arr = ['T|F^T', 'T|T&F^T', 'T^F|F'] #'T|F^T'
for expr in arr:
    get_ways_to_paranthize_expression(expr)


