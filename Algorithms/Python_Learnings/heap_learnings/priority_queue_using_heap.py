from heapq import heapify, heappush, heappop, nsmallest

heap = [1, 7, 3, 6, 8, 10]
print(f'Before Heap = {heap}')
heapify(heap)
print(f'After heapify heap = {heap}')

heappush(heap, 5)
print(f'After heappush heap = {heap}')

print(f'First element heap = {nsmallest(1, heap)[0]}')
# to print max heap make elements negative
