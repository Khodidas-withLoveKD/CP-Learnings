"""
Implementing FIND, INSERT, DELETE and getRandomNode methods in bst
"""
import random


class TreeNode:
    def __init__(self, key):
        self.val = key
        self.size = 1
        self.right = None
        self.left = None


class BinarySearchTree:
    def __init__(self, key):
        self.root = TreeNode(key)

    def insert(self, key):
        curr = self.root
        prev = None
        insert_at_left = False
        while curr:
            prev = curr
            if key < curr.val:
                curr = curr.left
                insert_at_left = True
            else:
                curr = curr.right
                insert_at_left = False

        if insert_at_left:
            prev.left = TreeNode(key)
        else:
            prev.right = TreeNode(key)

    def find(self, key):
        curr = self.root
        while curr:
            if curr.val == key:
                return curr.val
            if curr.left and key <= curr.left.val:
                curr = curr.left
            else:
                curr = curr.right
        print(f'Node with val: {key} does not exists')

    def delete(self, node, key):
        # node_to_be_deleted = self.find(key)
        if node is None:
            return node
        elif key < node.val:
            node.left = self.delete(node.left, key)
        elif key > node.val:
            node.right = self.delete(node.right, key)
        else:  # found the node
            # case 1: Node has no child
            if node.left is None and \
                    node.right is None:
                node = None
            # CASE 2: has one child
            # 2.1: has only left child
            elif node.right is None:
                node = node.left
            elif node.left is None:
                node = node.right
            # CASE 3: Node has two child
            else:
                # find the leftmost node in the right subtree
                successor = self.find_successor(node)
                # replace values
                node.key = successor.key
                # now replace the successor with its successor
                # and it will surely have either only right child or no child
                node.right = self.delete(node.right, successor.key)

        return node

    def find_successor(self, node):
        while node.left is not None:
            node = node.left
        return node

    def get_random_node(self):
        curr = self.root
        left_size = 0 if curr.left is None else curr.left.size
        index_to_get = random.randint(1, curr.size)

        if index_to_get < left_size:
            # go left
            random_node = curr.left.get_random_index()
        elif curr.size - left_size == index_to_get:
            # current node
            random_node = curr
        else:
            # go right
            random_node = curr.right.get_random_index()

        return random_node

    


# TC: single root
root = 20
bst = BinarySearchTree(root)
# print(bst.find(20))
# print(bst.find(10))

# insert
bst.insert(30)
bst.insert(10)
print(bst.find(10))

