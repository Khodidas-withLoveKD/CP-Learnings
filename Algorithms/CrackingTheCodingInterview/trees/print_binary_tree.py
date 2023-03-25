# printing binary tree in this form
# https://www.techiedelight.com/c-program-print-binary-tree/

# think big, start small
# let's create Tree first
# before that create Node first
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# Constants
FOUR_SPACES = "    "
BRANCH = "|-- "
ROOT_BRANCHING = " --"


class PrintTreeStructure:
    def __init__(self, prev_node_repr):
        self.repr = prev_node_repr + FOUR_SPACES
        # self.val = val


def print_tree(curr, prev_node_repr):
    # go to the rightmost first
    # if has right
    if curr.right:
        # go right
        right_node_print_structure = PrintTreeStructure(prev_node_repr)
        print_tree(curr.right, right_node_print_structure.repr)
    else:
        # print curr
        # print the its repr
        print(prev_node_repr + BRANCH + curr.val)
        # go back from here

    # print the root of that subtree
    print()  # newline
    print(prev_node_repr + curr.val + ROOT_BRANCHING)
    # print the left one
    # will continue from here



# create tree
# (difficulty) level 0
root = Node(1)
print_tree(root)
# (difficulty) level 1
root.left = Node(2)
root.right = Node(3)
"""
    |-- 2  
1 --
    |-- 3
"""
print_tree(root, "")
