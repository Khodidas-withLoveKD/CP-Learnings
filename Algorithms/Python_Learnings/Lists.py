import math

names = ['khodidas', 'loves', 'Kiran', 'so', 'much']
print(names)
print(names[0])
print(names[-1])
print(names[1:])
print(names[-2: -4])
print(names[-4: -2])
# modify list element
names[0] = 'KD'
print(names)

print('=== FIND LARGEST NUMBER IN A LIST ====')
numbers = [1, 23, 4, 75, 7, 3, 56, 0]
max_num = -math.inf
# max_num = numbers[0]
for num in numbers:
    if num > max_num:
        max_num = num
print(f'Largest: {max_num}')

print('===== 2D LISTS (MATRIX) =====')
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
print(matrix[0][1])
matrix[0][1] = 234
print(matrix[0][1])
print('---- Printing Matrix ----')
for row in matrix:
    for item in row:
        print(item, end=' ')
    print()

print('====== LIST METHODS ======')
numbers = [1, 3, 3, 67, 45, 3, 6, 8]
numbers.append(20)
print(numbers)
numbers.insert(2, 22)
print(numbers)
numbers.remove(3)  # removes first instance
print(numbers)
numbers.reverse()
print(f'Reversed List = {numbers}')
numbers.sort()
print(numbers)
print(f'Count = {numbers.count(3)}')
numbers.sort(reverse=True)
print(numbers)
numbers.pop()
print(f'After removing last = {numbers}')
numbers.pop(2)
print(f'After removing numbers[2] = {numbers}')
# two check for occurence
# gives index
print(f'45 is at {numbers.index(45)}')
# print(f'100 is at {numbers.index(100)} i.e, not present')
# gives Boolean
print(f'Is 45 there? {45 in numbers}')
# numbers.clear()
# print(f'Numbers = {numbers}')

print('--- Checking the diff for using copy and directly assigning ----')
numbers_2 = numbers.copy()
numbers_3 = numbers
numbers.append(100)
print(numbers_2)
print(numbers_3)

print('===== EXERCISE: REMOVE DUPLICATES IN A LIST ====')
dup_list = [1, 2, 3, 4, 2, 3, 4, 3, 4, 4]
dup_list_2 = dup_list.copy()
# check for each elem
# if count > 1 mark as dup
# keep on removing that elem until count > 1
# The below Time Complexity is not correct but have to think which is faster
for elem in dup_list:  # O(n)
    while dup_list.count(elem) > 1:  # O(n)
        dup_list.remove(elem)        # O(n)

print(f'After removing dups {dup_list}')

print('----- METHOD 2 For removing dups ------')
uniques = []
for elem in dup_list_2:
    if elem not in uniques:
        uniques.append(elem)
print(f'After removing dups by method 2 {uniques}')

