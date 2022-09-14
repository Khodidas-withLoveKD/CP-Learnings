from collections import deque
from queue import Queue

print('==== QUEUE USING LIST ====')

list_queue = []
print(f'initial queue = {list_queue}')
list_queue.append(1)
print(f'Adding queue.append(1) | queue = {list_queue}')
list_queue.append(2)
print(f'Adding queue.append(2) | queue = {list_queue}')
list_queue.append(3)
print(f'Adding queue.append(3) | queue = {list_queue}')
print('--- Removing Items ---')
print(f'queue.pop(0) = {list_queue.pop(0)} | queue = {list_queue}')
print(f'queue.pop(0) = {list_queue.pop(0)} | queue = {list_queue}')
print(f'queue.pop(0) = {list_queue.pop(0)} | queue = {list_queue}')
# BUT List is slower. Why? Think around removing

print('\n===== USING DEQUE ====')
dq_queue = deque()
print(f'initial queue = {dq_queue}')
dq_queue.append(1)
print(f'Adding queue.append(1) | queue = {dq_queue}')
dq_queue.append(2)
print(f'Adding queue.append(2) | queue = {dq_queue}')
dq_queue.append(3)
for i in range(3):
    print(dq_queue[i])
print(f'Adding queue.append(3) | queue = {dq_queue}')
print('--- Removing Items ---')
print(f'queue.pop(0) = {dq_queue.popleft()} | queue = {dq_queue}')
print(f'queue.pop(0) = {dq_queue.popleft()} | queue = {dq_queue}')
print(f'queue.pop(0) = {dq_queue.popleft()} | queue = {dq_queue}')
# print(f'queue.pop(0) = {dq_queue.popleft()} | queue = {dq_queue}')
print(f'size = {len(dq_queue)}')

print('\n==== USING Queue from queue ====')
qq = Queue(maxsize=3)
print(f'initial queue = {qq}')
print(f'initial size = {qq.qsize()}')
qq.put(1)
print(f'Adding queue.put(1) | queue = {qq}')
qq.put(2)
print(f'Adding queue.put(2) | queue = {qq}')
qq.put(3)
print(f'Adding queue.put(3) | queue = {qq}')
# Adding the below line will make the program wait
# qq.put(4)
# print(f'Adding queue.put(4) | queue = {qq}')
# Adding below line will raise Queue Full error
# qq.put_nowait(4)
print('--- Removing Items ---')
print(f'is Queue Full = {qq.full()}')
print(f'is Queue Empty = {qq.empty()}')
print(f'queue.get(0) = {qq.get()} | queue = {qq}')
print(f'queue.get(0) = {qq.get()} | queue = {qq}')
print(f'queue.get(0) = {qq.get()} | queue = {qq}')
# Adding the below line will make the program wait
# print(f'queue.pop(0) = {qq.get()} | queue = {qq}')
# The below line will raise Queue Empty error
# print(f'queue.pop(0) = {qq.get_nowait()} | queue = {qq}')
print(f'is Queue Full = {qq.full()}')
print(f'is Queue Empty = {qq.empty()}')
qq.put(2)
print(f'Adding queue.put(2) | queue = {qq}')
print(f'is Queue Full = {qq.full()}')
print(f'is Queue Empty = {qq.empty()}')


