import sys
sys.stdin = open("input.txt", 'r')
sys.stdout = open("output.txt", 'w')


def dfs_until_value(matrix, start_idx, target_value):
    stack = [start_idx]
    visited = set()
    current_value = matrix[start_idx[0]][start_idx[1]]

    while stack:
        curr_idx = stack.pop()
        i, j = curr_idx
        matrix[i][j] = target_value
        # if matrix[i][j] != target_value:
        #     return matrix
        visited.add(curr_idx)
        # Check the four adjacent cells (up, down, left, right)
        for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
            if 0 <= x < len(matrix) and 0 <= y < len(matrix[0]) and (x, y) not in visited and matrix[x][y] == current_value:
                stack.append((x, y))

    # If we get here, we didn't find the target value
    return matrix


if __name__ == '__main__':

    t = int(input())
    while t > 0:
        t -= 1
        n, m = map(int, input().split())
        matrix = []
        for i in range(n):
            matrix.append(list(map(int, input().strip().split())))
        start_idx = list(map(int, input().strip().split()))
        target_value = start_idx[2]
        start_idx.pop(-1)
        result = dfs_until_value(matrix, tuple(start_idx), target_value)
        for i in result:
            print(*i)
