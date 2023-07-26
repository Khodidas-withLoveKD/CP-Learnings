# should be used as a replacement of def where we want to make the code clear and precise and short

# example
def add(a, b):
    return a + b
# can be written as
add_l = lambda a, b: a + b


def filter_odd_by_loop(arr):
    new_arr = []
    for num in arr:
        if num % 2:
            new_arr.append(num)

    return new_arr

filter_odd_by_filter_and_lambda = lambda x : x % 2 == 1

def filte_odd_by_filter_and_normal_func(x):
    return x % 2 == 1


print(f'add(2,3) = {add(2,3)}')
print(f'add_l(2,3) = {add_l(2,3)}')
arr = [1,2,3,4,5,6,7]

print(f'Odd in list by list compreshension = {[x for x in arr if x % 2 == 1]}')
print(f'filter by lambda = {list(filter(filter_odd_by_filter_and_lambda, arr))}')
print(f'filter by func = {list(filter(filte_odd_by_filter_and_normal_func, arr))}')

