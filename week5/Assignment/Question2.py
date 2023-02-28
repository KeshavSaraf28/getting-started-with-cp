import sys
sys.stdin = open("input.txt", 'r')
sys.stdout = open("output.txt", 'w')


def bfs_shortest_path_length(matrix, n):
    queue = [0]
    visited = set()
    path_length = -1
    visited.add(0)
    while queue:
        path_length += 1
        for j in range(len(queue)):
            cur = queue.pop(0)
            # print("current and path: ", cur, path_length)
            if cur == n-1:
                return path_length
            for i in range(n):
                if matrix[cur][i] == 1 and i not in visited:
                    queue.append(i)
                    visited.add(i)
    return -1


n, m = map(int, input().split())
matrix = [[0 for i in range(n)] for j in range(n)]
for i in range(m):
    x, y = map(int, input().split())
    matrix[x-1][y-1] = 1
    matrix[y-1][x-1] = 1
# for i in matrix:
#     print(*i)
if matrix[n-1][0] == 0:
    print(bfs_shortest_path_length(matrix, n))
else:
    for i in range(n):
        for j in range(n):
            if matrix[i][j] == 0 and i != j:
                matrix[i][j] = 1
            else:
                matrix[i][j] = 0
    # for i in matrix:
    #     print(*i)
    print(bfs_shortest_path_length(matrix, n))
