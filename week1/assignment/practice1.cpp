#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int;
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
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        if (i != t - 1)
            cout << (n * (n - 1)) / 2 << "\n";
        else
            cout << (n * (n - 1)) / 2;
    }
    return 0;
}