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
    for (ll i = 0; i < t; i++)
    {
        ll n, m;
        cin >> n >> m;
        ll arr[n] = {0};
        ll Totaljob = m;
        for (ll j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            arr[x - 1]++;
        }
        ll Extrajob[n] = {0};
        ll Freejob = 0;
        ll time = 0;
        while (Freejob < Totaljob)
        {
            time++;
            Freejob = 0;
            for (ll j = 0; j < n; j++)
            {
                if (arr[j] == 0)
                {
                    Extrajob[j]++;
                    Freejob += Extrajob[j] / 2;
                }
                else
                {
                    arr[j]--;
                    Totaljob--;
                }
            }
        }
        if (i < t - 1)
            cout << time << endl;
        else
        {
            cout << time;
        }
    }
    return 0;
}