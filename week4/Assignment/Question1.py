import sys
sys.stdin = open("input.txt", 'r')
sys.stdout = open("output.txt", 'w')
MOD = 10**9 + 7


class DSU:
    def __init__(self, n):
        self.parent = [i for i in range(n+1)]
        self.rank = [0]*(n+1)
        self.number_of_sets = n
        self.setsize = [1]*(n+1)

    def findset(self, u):
        if self.parent[u] == u:
            return u
        else:
            self.parent[u] = self.findset(self.parent[u])
            return self.parent[u]

    def unions(self, u, v):
        u, v = self.findset(u), self.findset(v)
        if u != v:
            if self.rank[u] > self.rank[v]:
                u, v = v, u
            if self.rank[u] == self.rank[v]:
                self.rank[v] += 1
            self.parent[u] = v
            self.number_of_sets -= 1
            self.setsize[v] += self.setsize[u]

    def total_sets(self):
        return self.number_of_sets

    def setsize(self, i):
        return self.setsize[self.findset(i)]


# Read the number of test cases
t = int(input())

# Process each test case
for _ in range(t):
    # Read the input for this test case
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    X = list(map(int, input().split()))

    # Count the number of possible permutations of C
    ans = DSU(n)
    for i in range(n):
        ans.unions(A[i], B[i])
    unique = []
    for i in range(n):
        if ans.findset(i+1) not in unique and ans.setsize[ans.findset(i+1)] > 1:
            unique.append(ans.findset(i+1))

    # Output the result modulo 10^9+7
    print((2**len(unique)) % MOD)
