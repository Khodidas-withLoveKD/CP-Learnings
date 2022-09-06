i = 1
while i <= 5:
    print('*' * i)
    i += 1
print('Done')


print('------\n ======FOR LOOPS=====')
for char in 'Khodidas':
    print(char)
for item in ['Khodidas', 'Kiran', 'Pooju']:
    print(item)
for item in [1, 2, 3]:
    print(item)
print('==== Using Range ===')
for i in range(2, 10, 2):
    print(i)

print('==== SHOPPING CART EXERCISE ====')
shopping_cart = [10, 20, 30, 40, 50]
total = 0
for price in shopping_cart:
    total += price
print('Total = ', total )

print('==== F SHAPE CHALLENGE =====')
# x_counts = [5, 2, 5, 2, 2]
# To print 'L'
x_counts = [2, 2, 2, 2, 10]
for num in x_counts:
    print('x' * num)

print('==== F SHAPE CHALLENGE WIHTOUT EXPRESSIONS =====')
for x_count in x_counts:
    for i in range(x_count):
        print('x', end='')
    print()


