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


class BSTNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def print_linked_list(head):
    print('The Linked list:')
    while head:
        print(head.data)
        head = head.right


def generate_bst():
    root = BSTNode(5)
    root.left = BSTNode(3)
    root.left.left = BSTNode(2)
    root.left.right = BSTNode(4)
    root.left.left.left = BSTNode(1)
    root.right = BSTNode(7)
    root.right.left = BSTNode(6)
    root.right.right = BSTNode(9)
    root.right.right.left = BSTNode(8)

    return root


def method_1(root):
    def traverse(traversal, node):
        if node is None:
            return

        # traverse in-order
        traverse(traversal, node.left)
        traversal.append(node.data)
        traverse(traversal, node.right)

    def create_linked_list(traversal):
        # you need to pont the markers properly
        # create linked list based on the nodes present in list
        head = BSTNode(traversal[0])
        node = head
        for i in range(1, len(traversal)):
            new_node = BSTNode(traversal[i])
            node.right = new_node
            print(f'node = {node.data} | new_node = {new_node.data}')
            node = new_node

        return head

    def flatten_tree_to_linked_list_method_1(root):
        # Method 1: Create array and traverse
        # the list which keeps track of order of traversal
        traversal = []
        traverse(traversal, root)

        head = create_linked_list(traversal)

        print_linked_list(head)

    print('===== METHOD 1 =====')
    flatten_tree_to_linked_list_method_1(root)


def flatten_tree_to_linked_list_method_2(root):
    # Method 2: Need to keep track of what was the previous element visited
    # and attach it to next
    print('====== MEHTOD 2 ======')
    prev = None

    def inorder(node):
        if node is None:
            return
        nonlocal prev

        inorder(node.left)
        prev.left = None  # the left should be None for all
        # the right child point next
        # prev means whose right shall be current node
        prev.right = node
        prev = node
        inorder(node.right)

    def flatten(root):
        nonlocal prev

        dummy = BSTNode(-1)
        prev = dummy
        inorder(root)

        # exits the recursion. Delete the dummy node
        return dummy.right

    print_linked_list(flatten(root))


root = generate_bst()
method_1(root)
flatten_tree_to_linked_list_method_2(root)
