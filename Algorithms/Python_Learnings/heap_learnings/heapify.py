class Heapsort:
    def __init__(self, iterable):
        self.Heap = iterable
        self.last_index = len(iterable) - 1
        self.create_heap()

    def left_child(self, index):
        return 2 * index + 1

    def right_child(self, index):
        return 2 * index + 2

    def is_leaf_node(self, index):
        return self.left_child(index) > self.last_index

    def swap(self, index1, index2):
        self.Heap[index1], self.Heap[index2] = self.Heap[index2], self.Heap[index1]

    def create_heap(self):
        for index in range((self.last_index + 1) // 2 - 1, -1, -1):
            self.heapify(index)
            print(f'After Create Heap = {self.Heap}')

    def heapify(self, curr_index):
        if not self.is_leaf_node(curr_index):
            left_child = self.left_child(curr_index)
            right_child = self.right_child(curr_index)
            if self.Heap[left_child] > self.Heap[curr_index] or \
                    (right_child <= self.last_index and self.Heap[right_child] > self.Heap[curr_index]):
                if right_child <= self.last_index and \
                        self.Heap[right_child] > self.Heap[left_child]:
                    self.swap(right_child, curr_index)
                    self.heapify(right_child)
                else:
                    self.swap(left_child, curr_index)
                    self.heapify(left_child)
        print(f'After Heapify Heap = {self.Heap}')


iterables = [5, 10, 20, 15, 25, 40, 60]
heapsort = Heapsort(iterables)

