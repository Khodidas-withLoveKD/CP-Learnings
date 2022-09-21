from heapq import heapify, heappop, heappush, heappushpop, heapreplace, nlargest, nsmallest

li = [60, 40, 20, 5, 10, 4, 23, 6]
print(li)
heapify(li)
print(f'After heapify = {li}')

heappush(li, 1)
print(f'After heappush = {li}')

print(f'popping element = {heappop(li)}')
print(f'After heappop = {li}')

heappushpop(li, 1)
print(f'After heappushpop = {li}')

heapreplace(li, 1)
print(f'After heapreplace = {li}')

print(f'3 largest nums are = {nlargest(3, li)}')
print(f'3 smallest nums are = {nsmallest(3, li)}')


