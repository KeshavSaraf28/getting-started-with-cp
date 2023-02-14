#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n], b[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        ll flag = 0;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (ll i = 0; i < n; i++)
            {
                if (a[i] != b[i])
                {
                    if (b[(i + 1) % n] < b[i] - 1)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}