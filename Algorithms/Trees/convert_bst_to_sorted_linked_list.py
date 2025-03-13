"""
Flatten BST to sorted list

https://www.geeksforgeeks.org/flatten-bst-to-sorted-list-increasing-order/
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
"""

"""
Approach 1:
Will do the in-order traversal because that says ki koni pachi kon aavse
Store them
and Create a linked List of that again
"""

class Node:
    def __init__(self, data):
        self.data = data
        self.right = None


def traverse(traversal, node):
    if node is None:
        return

    # traverse in-order
    traverse(traversal, node.left)
    traversal.append(node.data)
    traverse(traversal, node.right)


def create_linked_list():
    # you need to pont the markers properly


def flatten_tree(root):
    # the list which keeps track of order of traversal
    traversal = []

    traverse(traversal, root)

    # you have the sorted order. Create a linked list out of it
    create_linked_list(traversal)
    # Rebase commit 1
    # Rebase commit 2
    # master commit 1
    # master commit 2
