#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int;
int TroubleSort(vector<int> arr)
{
    vi odd, even;
    vi result;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            even.push_back(arr[i]);
        }
        else
        {
            odd.push_back(arr[i]);
        }
    }
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            result.push_back(even[even.size() - 1]);
            even.pop_back();
        }
        else
        {
            result.push_back(odd[odd.size() - 1]);
            odd.pop_back();
        }
    }

    int flag = -1;
    for (int i = 0; i < result.size() - 1; i++)
    {
        if (result[i] > result[i + 1])
        {
            flag = i;
            break;
        }
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vi arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cout << "Case #" << i + 1 << ": ";
        int k = TroubleSort(arr);
        if (k == -1)
        {
            cout << "OK\n";
        }
        else
        {
            cout << k << endl;
        }
    }
    return 0;
}