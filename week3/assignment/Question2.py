t = int(input())

while t:
    t -= 1
    n = int(input())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))

    flag = 0
    for i in range(n):
        if a[i] > b[i]:
            flag = 1
            break

    if flag == 0:
        for i in range(n):
            if a[i] != b[i]:
                if b[(i+1) % n] >= b[i] - 1:
                    pass
                else:
                    flag = 1
                    break

    if flag == 0:
        print("YES")
    else:
        print("NO")
