# import sys
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')


class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n+1)]
        # self.array=[i for i in range(n+1)]
        self.rank = [0]*n
        self.number_of_sets = n

    def findset(self, u):
        if self.parent[u] == u:
            return u
        else:
            self.parent[u] = self.findset(self.parent[u])
            return self.parent[u]

    def unions(self, u, v):
        u, v = self.findset(u), self.findset(v)
        if u != v:
            self.parent[u] = v
            self.number_of_sets -= 1

    def total_sets(self):
        return self.number_of_sets


t = int(input())
while(t):
    t -= 1
    n, m = input().strip().split()
    n, m = int(n), int(m)
    answer = DSU(n)
    for i in range(m):
        u, v = input().strip().split()
        u, v = int(u), int(v)
        answer.unions(u, v)
    print(answer.total_sets())
