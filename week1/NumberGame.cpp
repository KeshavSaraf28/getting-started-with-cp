#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define db double
typedef long long ll;
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
    db golden = (1 + sqrt(5)) / 2;
    for (int i = 0; i < t; i++)
    {
        db a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        ll ans;
        ans = 0;
        for (int j = b1; j < b2 + 1; j++)
        {
            if (a1 > golden * j || (golden - 1) * j > a2)
            {
                ans += (ll)(a2 - a1 + 1);
            }
            else
            {
                ans += max((ll)0, (ll)(a2 - floor(golden * j)));
                ans += max((ll)0, (ll)(floor((golden - 1) * j) - a1 + 1));
            }
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}