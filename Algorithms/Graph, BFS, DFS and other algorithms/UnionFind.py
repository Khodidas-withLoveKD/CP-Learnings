# UnionFind or Disjoint Sets
# https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
"""
Task
-----
We are given 10 individuals say, a, b, c, d, e, f, g, h, i, j

Following are relationships to be added:
a <-> b
b <-> d
c <-> f
c <-> i
j <-> e
g <-> j

Given queries like whether a is a friend of d or not. We basically need to create following 4 groups and maintain a quickly accessible connection among group items:
G1 = {a, b, d}
G2 = {c, f, i}
G3 = {e, g, j}
G4 = {h}

Find whether x and y belong to the same group or not, i.e. to find if x and y are direct/indirect friends.
"""


from collections import defaultdict


# we can use array method or node method where both forms a tree

# for above example
n = 10
parent = [i for i in range(n)]  # at first each node is parent of itself
relations = [(0,1), (1,3), (2,5), (2,7), (8,4), (6,8)]


def find(i):
    while i != parent[i]:
        print(f'parent[{i}] = {parent[i]}')
        i = parent[i]

    return i


def union(x, y):
    x_parent = find(x)
    y_parent = find(y)
    print(f'--------\n{x_parent = } | {y_parent = }')
    parent[y_parent] = x_parent


# create groups
for x, y in relations:
    union(x, y)

print(f'========\n{parent = }')
# check the groups
groups = defaultdict(list)
for i in range(n):
    val = find(i)
    groups[val].append(i)


for parent in groups:
    print(f'parent = {parent} | childs = {groups[parent]}')
