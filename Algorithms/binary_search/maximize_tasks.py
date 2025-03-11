"""
You are given n tasks, each represented by an integer in the array tasks. There are m nodes available to process these tasks. Each node is proficient in completing different tasks, and the nodes must work in a balanced manner such that:

Every node must process as many tasks as possible without having an unfair distribution (i.e., the workload should be as balanced as possible).
No two nodes should process the same task more than once.
The tasks must be assigned to the nodes such that the maximum number of tasks is processed.
Your task is to find the minimum number of tasks that will remain unprocessed after all the nodes are assigned their tasks optimally.

Input:
The first line contains two integers n and m — the number of tasks and the number of nodes.
The second line contains n integers, representing the tasks array, where tasks[i] is the type of the i-th task.
Output:
Output a single integer — the number of tasks that will remain unprocessed after all nodes are assigned their tasks.
Constraints:
1 ≤ n ≤ 100,000 — the number of tasks.
1 ≤ m ≤ 100,000 — the number of nodes.
Each task is represented by an integer 1 ≤ tasks[i] ≤ n.
"""


