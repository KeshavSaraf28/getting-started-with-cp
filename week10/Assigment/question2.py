MOD = 1000000007


def fibonacci(n, F):
    if F[n] == -1:
        if n == 1:
            ans = 1
        elif n == 2:
            ans = 1
        else:
            ans = fibonacci(n-1, F) % MOD + fibonacci(n-2, F) % MOD
        F[n] = ans
    return F[n]


n = int(input())
F = [-1]*(n+2)
ans = 1
for i in range(2, n+1):
    ans += fibonacci(i+1, F)
    ans %= MOD
print(ans)
