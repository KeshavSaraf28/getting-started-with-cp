#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
typedef long long ll;

int money(vi a, int n, vi &memo)
{
    int ans = 0;
    if (memo[n - 1] == -1)
    {
        if (n == 1)
            ans = a[0];
        else if (n == 2)
            ans = a[1];
        else if (n == 3)
            ans = a[2] + a[0];
        else
            ans = max(money(a, n - 2, memo) + a[n - 1], money(a, n - 3, memo) + a[n - 1]);
        memo[n - 1] = ans;
    }
    return memo[n - 1];
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vi memo(n, -1);
        cout << max(money(a, n, memo), money(a, n - 1, memo)) << endl;
    }
    return 0;
}
