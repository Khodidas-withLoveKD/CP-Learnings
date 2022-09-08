# tuples are immutable version of list
# So, you cannot append or remove anything, check the methods it provides
numbers = (1, 2, 3, 3, 2)
print(numbers.count(3))
print(numbers.index(2, 2, 5))
print(numbers[0])
print(numbers)
# numbers[0] = 10
