"""
There are 2 basic ops:
1. insert
-> Insert at the leaf, go on till comparing to root
-> For each iteration takes O(logn) time -> depends on height of the tree
-> So, for inserting all n elements takes O(nlogn) time

2. Delete
-> Delete the root, add the last element at root and go from root to leaf comparing
-> For each iteration takes O(logn) time -> depends on height of the tree
-> So, for deleting all n elements takes O(nlogn) time

-> If you store the removed elements they will be sorted. That is the idea behind heapsort
"""


class HeapSort:
    def __init__(self, maxsize):
        self.maxsize = maxsize
        # heap is represented as array
        self.Heap = [-1] * maxsize
        # index to keep track of last_index
        self.last_index = -1

    def parent(self, index):
        return ((index + 1) // 2) - 1

    def left_child(self, index):
        return (2 * index) + 1

    def right_child(self, index):
        return (2 * index) + 2

    def swap(self, index1, index2):
        self.Heap[index1], self.Heap[index2] = self.Heap[index2], self.Heap[index1]

    # Will try to create a max_heap and min_heap in same file
    def heap_push(self, curr_elem):
        if self.last_index >= self.maxsize - 1:
            raise Exception('Heap full!!')
        # insert at last
        self.last_index += 1
        self.Heap[self.last_index] = curr_elem
        current_elem_index = self.last_index
        # add at a proper place
        # compare that num with parent
        # For max heap -> swap if child is greater
        while current_elem_index > 0 and curr_elem > self.Heap[self.parent(current_elem_index)]:
            self.swap(current_elem_index, self.parent(current_elem_index))
            current_elem_index = self.parent(current_elem_index)

        print(f'After Inserting Heap = {self.Heap}')

    def heap_pop(self):
        if self.last_index < 0:
            raise Exception('Heap Empty')
        # remove the first element
        # and store it at last index
        self.swap(self.last_index, 0)
        self.last_index -= 1
        # find the largest of all the three childs and then swap with it
        # curr_elem = self.Heap[self.last_index + 1]
        curr_elem_index = 0
        left_child_index = self.left_child(curr_elem_index)
        right_child_index = self.right_child(curr_elem_index)

        while left_child_index <= self.last_index and \
                (self.Heap[left_child_index] > self.Heap[curr_elem_index] or
                 (right_child_index <= self.last_index and self.Heap[right_child_index] > self.Heap[curr_elem_index])):
            if right_child_index <= self.last_index and self.Heap[right_child_index] > self.Heap[left_child_index]:
                self.swap(curr_elem_index, right_child_index)
                curr_elem_index = right_child_index
            else:
                self.swap(curr_elem_index, left_child_index)
                curr_elem_index = left_child_index
            left_child_index = self.left_child(curr_elem_index)
            right_child_index = self.right_child(curr_elem_index)

        print(f'After Deleting Heap = {self.Heap}')

    def __str__(self):
        return str(f'Heap = {self.Heap}')


heapsort = HeapSort(6)
print(heapsort)
heapsort.heap_push(10)
heapsort.heap_push(20)
heapsort.heap_push(15)
heapsort.heap_push(25)
heapsort.heap_push(40)
heapsort.heap_push(60)
print(heapsort)

# heapsort.heap_push(12)
heapsort.heap_pop()
heapsort.heap_pop()
heapsort.heap_pop()
heapsort.heap_pop()
heapsort.heap_pop()
heapsort.heap_pop()
# heapsort.heap_pop()
print('And you have your array sorted in ascending :)')

