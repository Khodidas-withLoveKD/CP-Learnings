from collections import deque

dq = deque([1, 2, 3])
print(f'Initially deque = {dq}')
dq.append(4)
print(f'after dq.append(4) | dq = {dq}')
dq.appendleft(0)
print(f'after dq.appendleft(0) | dq = {dq}')

print('Now removing elements')
dq.pop()
print(f'after dq.pop() | dq = {dq}')
dq.popleft()
print(f'after dq.popleft() | dq = {dq}')

print(f'dq.index(1,0,2) | dq = {dq.index(1,0,2)}')
# print(f'dq.index(1,1,2) | dq = {dq.index(1,1,2)}')

dq.extend([4, 5, 6, 7])
dq.reverse()
print(f'dq.reverse() | dq = {dq}')
dq.rotate(3)
print(f'dq.rotate(3) | dq = {dq}')
dq.rotate(-3)
print(f'dq.rotate(-3) | dq = {dq}')

