class HeapSort:

    def __init__(self, maxsize):
        self.max_size = maxsize
        self.Heap = [-1] * self.max_size
        self.last_index = 0

    def parent(self, index):
        return (index + 1) // 2 - 1

    def left_child(self, index):
        return 2 * index + 1

    def right_child(self, index):
        return 2 * index + 2

    def swap(self, index1, index2):
        self.Heap[index1], self.Heap[index2] = self.Heap[index2], self.Heap[index1]

    def heap_push(self, elem):
        if self.last_index >= self.max_size:
            raise Exception('Heap full!!')

        self.Heap[self.last_index] = elem
        curr_index = self.last_index
        self.last_index += 1

        while curr_index > 0 and self.Heap[curr_index] < self.Heap[self.parent(curr_index)]:
            # bubble up
            self.swap(curr_index, self.parent(curr_index))
            curr_index = self.parent(curr_index)
        print(f'After Inserting Heap = {self.Heap}')

    def heap_pop(self):
        if self.last_index == 0:
            raise Exception('Heap empty!!')

        self.last_index -= 1
        self.swap(0, self.last_index)

        # push down
        curr_index = 0
        left_child = self.left_child(curr_index)
        right_child = self.right_child(curr_index)
        while left_child < self.last_index and \
                (self.Heap[curr_index] > self.Heap[left_child]
                    or (right_child < self.last_index
                 and self.Heap[curr_index] > self.Heap[right_child])):
            if right_child < self.last_index and self.Heap[right_child] < self.Heap[left_child]:
                self.swap(right_child, curr_index)
                curr_index = right_child
            else:
                self.swap(left_child, curr_index)
                curr_index = left_child

            left_child = self.left_child(curr_index)
            right_child = self.right_child(curr_index)

        print(f'After Deleting Heap = {self.Heap}')

    def __str__(self):
        return str(self.Heap)


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
print('And you have your array sorted in descending :)')
