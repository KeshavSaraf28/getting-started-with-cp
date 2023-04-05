def money(a, n):
    if memo[n-1] == -1:
        if n == 1:
            ans = a[0]
        elif n == 2:
            ans = a[1]
        elif n == 3:
            ans = a[2]+a[0]
        else:
            ans = max(money(a, n-2)+a[n-1], money(a, n-3)+a[n-1])
        memo[n-1] = ans
    return memo[n-1]


t = int(input())
while(t):
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    memo = [-1]*n
    print(max(money(a, n-1), money(a, n)))
