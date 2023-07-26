# learning counters
from collections import Counter


li = [1, 2, 3, 1, 3, 2, 1, 1, 5, 5, 5]
counter = Counter(li)
print(counter)
print(f'counter[1] = {counter[1]}')
print(f'counter.most_common(2) = {counter.most_common(2)}')
li_to_be_added = [0, 0, 1]
print(f'Counter before any change = {counter}')
counter.update(li_to_be_added)
print(f'After additon - Updated counter = {counter}')
li_to_be_subtracted = [0, 0, 1]
counter.subtract(li_to_be_subtracted)
print(f'After subtraction - updated counter = {counter}')
print(f'counter[100] = {counter[100]}')  # acts as a defaultdict

print(f'counter.elements = {counter.elements()}')
print(f'counter.items = {counter.items()}')
print(f'counter.keys = {counter.keys()}')
print(f'counter.values = {counter.values()}')
