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
    for (ll j = 0; j < t; j++)
    {

        ll n, l;
        cin >> n >> l;
        ll a[n], k[l];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < l; i++)
            cin >> k[i];
        ll Length = *max_element(k, k + l);
        ll MaxHeight[Length + 1];
        MaxHeight[0] = 0;
        ll z = 0;
        ll height = 0;

        for (ll i = 1; i <= Length; i++)
        {
            while (z < n)
            {
                if (i >= a[z])
                {
                    height += a[z];
                    z++;
                }
                else
                    break;
            }
            MaxHeight[i] = height;
        }
        if (j < t - 1)
        {

            for (ll i = 0; i < l; i++)
            {
                cout << MaxHeight[k[i]] << " ";
            }
            cout << endl;
        }
        else
        {
            for (ll i = 0; i < l - 1; i++)
            {
                cout << MaxHeight[k[i]] << " ";
            }
            cout << MaxHeight[k[l - 1]];
        }
    }
    return 0;
}
