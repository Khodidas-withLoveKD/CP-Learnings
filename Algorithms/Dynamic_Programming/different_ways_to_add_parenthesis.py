# https://leetcode.com/problems/different-ways-to-add-parentheses

def do_operation(left, right, operator):
    val = 0
    if operator == '-':
        val = left - right
    elif operator == '+':
        val = left + right
    else:
        val = left * right

    return val


def get_possible_values_of_expression(expression):
    results = []
    is_number = True

    for i, ch in enumerate(expression):
        # if s[o] is number do nothing
        # else split from there and get the left and right numbers
        if ch in ('-', '+', '*'):
            is_number = False
            # split
            left_vals = get_possible_values_of_expression(expression[:i])
            right_vals = get_possible_values_of_expression(expression[i+1:])

            for left in left_vals:
                for right in right_vals:
                    results.append(do_operation(left, right, expression[i]))

    # out of loop
    return results if not is_number else [int(expression)] # directly returning int(exp) because then the expression will only contain number


def get_vals_from_expression(expression, expr_map):
    if expression in expr_map:
        vals = expr_map[expression]
    else:
        vals = get_all_possible_values_of_expression_using_dp(expression, expr_map)
        expr_map[expression] = vals

    return vals


def get_all_possible_values_of_expression_using_dp(expression, expr_map):
    results = []
    is_number = True

    for i, ch in enumerate(expression):
        if ch in ('-', '+', '*'):
            is_number = False
            # this was the repeating behaviour, let's store it
            left_vals = get_vals_from_expression(expression[:i], expr_map)
            right_vals = get_vals_from_expression(expression[i+1:], expr_map)

            for left in left_vals:
                for right in right_vals:
                    results.append(do_operation(left, right, expression[i]))

    return results if not is_number else [int(expression)]


expressions = ["1-2-3", "2-1-1", "2*3-4*5"]
for exp in expressions:
    all_values = get_all_possible_values_of_expression_using_dp(exp, {})
    print(f'Exp = {exp}\nans = {all_values}')
    print("--------")



