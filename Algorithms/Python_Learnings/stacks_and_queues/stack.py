from collections import deque

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

