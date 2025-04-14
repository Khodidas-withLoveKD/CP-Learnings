
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


"""
SOMETIME LATER in 2025
"""

val = 10


def outer():
    val = 20

    def inner():
        print(f'Inside Inner | After {val = }')

    print(f' Inside Outer | Before {val = }')
    val = 5
    print(f'Inside Outer | After {val = }')

outer()
