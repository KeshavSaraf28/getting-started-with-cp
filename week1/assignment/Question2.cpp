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
        int n, m;
        cin >> n >> m;
        int result = 0;
        if (n < m)
        {
            swap(n, m);
        }
        result += (n / 3) * m;
        n = n % 3;
        if (m < 3)
        {
            if (n == 0)
            {
            }
            else if (n == 1)
            {
                result += 1;
            }
            else
            {
                if (m == 1)
                    result += 1;
                else
                    result += 2;
            }
            if (i != t - 1)
                cout << result << endl;
            else
                cout << result;
        }
        else
        {
            result += (m / 3) * n;
            m = m % 3;
            if (m == 0 || n == 0)
            {
            }
            else if (n == 2 && m == 2)
            {
                result += 2;
            }
            else
            {
                result += 1;
            }
            if (i != t - 1)
                cout << result << endl;
            else
                cout << result;
        }
    }
    return 0;
}