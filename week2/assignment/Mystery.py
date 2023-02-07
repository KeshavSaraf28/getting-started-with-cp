def mystery(L):
    m = 0
    n = len(L)
    for i in range(n):
        m = i
        for j in range(i, n):
            if L[j] > L[m]:
                m = j
        L[i:m+1] = L[i:m+1][::-1]

    return L


L = list(map(int, input().split()))
print(mystery(L))
