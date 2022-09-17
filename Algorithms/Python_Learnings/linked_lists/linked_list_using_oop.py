class LinkedList:
    # def __init__(self):
    #    self.head = None
    # Changing the above define in such a way ki LinkedList is created
    # from and iterable itself
    def __init__(self, nodes=None):
        self.head = None
        if nodes is not None:
            node = Node(nodes.pop(0))
            self.head = node
            for value in nodes:
                node.next = Node(value)
                node = node.next

    def __repr__(self):
        nodes = []
        curr_node = self.head
        while curr_node is not None:
            nodes.append(str(curr_node.data))
            curr_node = curr_node.next
        nodes.append('None')
        return '->'.join(nodes)


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        return str(self.data)


print('==== START ====')
ll = LinkedList()
first_node = Node(1)
ll.head = first_node
second_node = Node(2)
first_node.next = second_node
third_node = Node(3)
second_node.next = third_node
print(f'LinkedList = {ll}')

print(f'==== CREATING LINKED LIST FROM ITERABLES ====')
nodes_list = [1, 2, 3, 4, 5]
ll_from_list = LinkedList(nodes_list)
print(f'LinkedList = {ll_from_list}')

nodes_string = list("HELLO I'm KD")
ll_from_string = LinkedList(nodes_string)
print(f'LinkedList = {ll_from_string}')
