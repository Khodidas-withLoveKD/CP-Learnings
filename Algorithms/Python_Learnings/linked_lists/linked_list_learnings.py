from collections import deque

print(f'=== USING DEQUE ====')
deque_ll = deque('abcde')
print(f'Linked list = {deque_ll}')
deque_ll.append('f')
print(f'Adding element at end | ll.apend(f) \nll = {deque_ll}')
deque_ll.appendleft('f')
print(f'Adding element at beginning | ll.apendleft(f) \nll = {deque_ll}')
deque_ll.pop()
print(f'Removing element from end | ll.pop() \nll = {deque_ll}')
deque_ll.popleft()
print(f'Removing element from beginning | ll.popleft() \nll = {deque_ll}')