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
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            // cout << arr[j];
        }

        int maxdiff = 0;
        for (int k = 0; k < n - 1; k++)
        {
            // cout << arr[k] << " " << arr[k + 1] << "hi\n";
            maxdiff = max(maxdiff, arr[k] - arr[k + 1]);
        }

        maxdiff = max(maxdiff, *max_element(arr + 1, arr + n) - arr[0]);
        maxdiff = max(maxdiff, arr[n - 1] - (*min_element(arr, arr + n - 1)));
        if (i == t - 1)
            cout << maxdiff;
        else
            cout << maxdiff << "\n";
    }

    return 0;
}