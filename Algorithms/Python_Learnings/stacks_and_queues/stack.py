from collections import deque
from queue import LifoQueue


print('==== USING LIST ====')
stack = []
stack.append(1)
stack.append(2)
stack.append(3)
print(f'After inserting stack = {stack}')
print(f'Pop(): {stack.pop()} | now stack = {stack}')
print(f'Pop(): {stack.pop()} | now stack = {stack}')
print(f'Pop(): {stack.pop()} | now stack = {stack}')
# print(f'Pop(): {stack.pop()} | now stack = {stack}')

print('\n==== USING DEQUE ====')
dq_stack = deque()
dq_stack.append(1)
dq_stack.append(2)
dq_stack.append(3)
print(f'stack after appending | dq = {dq_stack}')
while dq_stack:
    print(f'Pop(): {dq_stack.pop()} | now stack = {dq_stack}')


print('\n==== USING LifoQueue from queue ====')
lifo_queue_stack = LifoQueue(maxsize=3)
print(f'initial stack = {lifo_queue_stack}')
print(f'initial size = {lifo_queue_stack.qsize()}')
lifo_queue_stack.put(1)
print(f'Adding stack.put(1) | queue = {lifo_queue_stack}')
lifo_queue_stack.put(2)
print(f'Adding stack.put(2) | queue = {lifo_queue_stack}')
lifo_queue_stack.put(3)
print(f'Adding stack.put(3) | queue = {lifo_queue_stack}')
# Adding the below line will make the program wait
# qq.put(4)
# print(f'Adding queue.put(4) | queue = {qq}')
# Adding below line will raise Queue Full error
# qq.put_nowait(4)
print('--- Removing Items ---')
print(f'is stack Full = {lifo_queue_stack.full()}')
print(f'is stack Empty = {lifo_queue_stack.empty()}')
print(f'stack.pop(0) = {lifo_queue_stack.get()} | stack = {lifo_queue_stack}')
print(f'stack.pop(0) = {lifo_queue_stack.get()} | stack = {lifo_queue_stack}')
print(f'stack.pop(0) = {lifo_queue_stack.get()} | stack = {lifo_queue_stack}')
# Adding the below line will make the program wait
# print(f'queue.pop(0) = {lifo_queue_stack.get()} | queue = {qq}')
# The below line will raise Queue Empty error
# print(f'queue.pop(0) = {lifo_queue_stack.get_nowait()} | queue = {qq}')
print(f'is stack Full = {lifo_queue_stack.full()}')
print(f'is stack Empty = {lifo_queue_stack.empty()}')
lifo_queue_stack.put(2)
print(f'Adding stack.put(2) | stack = {lifo_queue_stack}')
print(f'is stack Full = {lifo_queue_stack.full()}')
print(f'is stack Empty = {lifo_queue_stack.empty()}')

