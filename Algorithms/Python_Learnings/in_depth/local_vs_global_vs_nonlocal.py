
def outer_function():
    # global num
    # print(f'OUTER_FUNCTION = {num}')
    num = 5
    print(f'OUTER_FUNCTION = {num}')

    def inner_function():
        # global num
        nonlocal num
        print(f'INNER_FUNCTION = {num}')
        num = 3
        print(f'INNER_FUNCTION = {num}')


    inner_function()
    print(f'AFTER INNER IN OUTER = {num}')


num = 1
print(f'OUTSIDE ALL FUNCTIONS = {num}')

outer_function()