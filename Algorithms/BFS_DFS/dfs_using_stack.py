from collections import deque


def do_dfs(adj_list):
    stack = deque([0])
    ans = []
    visited = [False] * (len(adj_list))
    while stack:
        curr = stack[-1]
        if not visited[curr]:
            ans.append(curr)
            visited[curr] = True

        for adj_vertex in adj_list[curr]:
            if not visited[adj_vertex]:
                stack.append(adj_vertex)
                break
        else:  # visited all so pop the current one
            stack.pop()

    print(*ans)


# 7 vertices (0 to 6)
adj_list = [
    [1, 5],
    [2],
    [3, 4],
    [],
    [],
    [6],
    []
]
do_dfs(adj_list)