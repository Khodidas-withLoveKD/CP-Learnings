from collections import deque

# no of nodes
N = 15
# assuming we have continuous nodes here 0 - 14
adj_list = [[] for _ in range(N)]


def add_edge(edge1, edge2):
    adj_list[edge1].append(edge2)
    adj_list[edge2].append(edge1)


def create_graph():
    # create a function to add edges
    add_edge(0, 2)
    add_edge(2, 1)
    add_edge(2, 6)
    add_edge(3, 5)
    add_edge(4, 5)
    add_edge(5, 6)
    add_edge(7, 6)
    add_edge(7, 8)
    add_edge(8, 9)
    add_edge(10, 9)
    add_edge(11, 9)
    add_edge(8, 12)
    add_edge(13, 12)
    add_edge(12, 14)


def do_bidirectional_search(src, dest):
    q = deque([src, dest])
    visited = [-1] * N
    visited[src] = 0  # 0 for nodes in path of src
    visited[dest] = 1  # 1 for dest
    while q:
        curr = q.popleft()

        for adj_node in adj_list[curr]:
            if visited[adj_node] == -1:  # not visited, mark it as visited
                visited[adj_node] = visited[curr]
                q.append(adj_node)
            elif visited[adj_node] != visited[curr]:  # already visited
                return True  # found path
    return False


def main():
    create_graph()
    src, dest = 0, 14
    print(do_bidirectional_search(src, dest))


main()
