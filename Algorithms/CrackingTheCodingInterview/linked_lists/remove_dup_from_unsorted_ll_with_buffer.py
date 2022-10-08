# we can use set to keep track of the already occurred elements

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = None


class LinkedList:
    def __init__(self, nodes=None):
        self.head = None
        if nodes:
            self.head = ListNode(nodes.pop(0))
            curr = self.head
            for node in nodes:
                curr.next = ListNode(node)
                curr = curr.next

    def get_head(self):
        return self.head

    def __repr__(self):
        nodes = []
        curr = self.head
        while curr:
            nodes.append(str(curr.val))
            curr = curr.next
        nodes.append('None')
        return '->'.join(nodes)


# all the input over here
# iterables = [1, 1, 2, 3, 3, 4, 5]
# iterables = [1, 2, 3, 3, 4, 5]
# iterables = [1]
iterables = []

dups = set()
ll = LinkedList(iterables)
pred = ll.get_head()

curr = pred
while curr:
    if curr.val in dups:
        pred.next = curr.next
    else:
        dups.add(curr.val)
        pred = curr
    curr = curr.next

print(ll)


