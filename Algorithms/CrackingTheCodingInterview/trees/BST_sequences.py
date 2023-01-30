"""
A binary search tree was created by traversing through an array from left to right and inserting each element.
Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.

Ex:
    2
  /  \
 1    3

 ans: [2,1,3] and [2,3,1]
"""


def get_permutations_of(nums):
    # it is sure that there will be lot of duplicates
    # so, we have to generate non duplicate permutations only
    all_perms = [[]]
    for num in nums:
        new_perm = []
        for each_perm in all_perms:
            for i in range(len(each_perm) + 1):
                if i-1 >= 0 and each_perm[i-1] == num:
                    break  # to avoid duplicates
                new_perm.append(each_perm[:i] + [num] + each_perm[i:])
        all_perms = new_perm
    return all_perms


def get_all_sequences(nums):
    # the root is all ways at the top
    # nums will be having all the possible permutations
    # we will attach these permutations one after other
    if len(nums) < 2:
        return [nums]

    # gen left and right subtrees | nums[0] will be the root of that subtree
    left_subtree = [num for num in nums if num < nums[0]]
    right_subtree = [num for num in nums if num > nums[0]]

    # get all permutations of left_subtree and right_subtree
    left_subtree_permutations = get_all_sequences(left_subtree)
    right_subtree_permutations = get_all_sequences(right_subtree)
    # mark all left subtree nodes as 0 and right as 1
    marked_array = [0] * len(left_subtree)
    for i in range(len(right_subtree)):
        marked_array.append(1)
    # generate all permutation of marked_array
    marked_permutations = get_permutations_of(marked_array)
    # now for every 0 in marked_permutation, mark it with left_subtree_permutations
    # and replace 1 for the right one
    # do the right subtree permutations marking for every perm in left_subtree
    unmarked_permutations = []
    for marked_permutation in marked_permutations:
        for left_subtree_permutation in left_subtree_permutations:
            for right_subtree_permutation in right_subtree_permutations:
                # mark 0 with l_s_p and 1 vice versa
                new_perm = [nums[0]]
                l, r = 0, 0
                for num in marked_permutation:
                    if num == 0:
                        new_perm.append(left_subtree_permutation[l])
                        l += 1
                    else:
                        new_perm.append(right_subtree_permutation[r])
                        r += 1
                unmarked_permutations.append(new_perm)

    return unmarked_permutations


# for simplicity purpose we will make the bst from the array itself
# and we also assume that there are no duplicates

# arr = [2, 1, 3]
arr = [4, 2, 1, 3, 6, 5, 7]
# arr = [4, 3, 1, 2]
# test with dups -> does not works
# arr = [1, 2, 1]

all_sequences = get_all_sequences(arr)
print(f'Total permutations = {len(all_sequences)}')
print(f'All Sequences: \n{all_sequences}')
