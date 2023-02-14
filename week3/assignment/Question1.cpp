#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
typedef long long ll;

void operation(vi &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == x)
            arr[i] = 0;
    return;
}

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
        vi arr;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        int no_of_op = 0;
        int change = 1;
        while (change)
        {
            change = 0;
            for (int i = n - 1; i > 0; i--)
            {
                if (arr[i] < arr[i - 1])
                {
                    no_of_op += 1;
                    operation(arr, arr[i - 1]);
                    change = 1;
                }
            }
        }
        cout << no_of_op << endl;
    }

    return 0;
}