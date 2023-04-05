#include <bits/stdc++.h>
#define vi vector<int>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll fibonacci(int n, vi &F)
{
    if (F[n] == -1)
    {
        if (n == 1)
        {
            F[n] = 1;
        }
        else if (n == 2)
        {
            F[n] = 1;
        }
        else
        {
            F[n] = (fibonacci(n - 1, F) % MOD + fibonacci(n - 2, F) % MOD) % MOD;
        }
    }
    return F[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vi F(n + 2, -1);
    ll ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans += fibonacci(i + 1, F);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}