#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k = 0;
    cin >> n;
    int arr[n] = {0};
    for (int j = 0; j < n + 1; j++)
    {
        arr[k] = 1;
        k += j;
        k = k % n;
    }
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 1)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
