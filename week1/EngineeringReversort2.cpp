#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int;
vi construct(int n, int cost, int min_element)
{
    // construct an array with the elements from M,....n..
    // when reversort gives a cost of "cost".
    if (n == 1)
    {
        vi result;
        result.push_back(min_element);
        return result;
    }
    else
    {
        vi result;
        if (cost == n * (n + 1) / 2 - 1)
        {
            // cout << "Hello1\n";
            for (int i = 2; i <= n; i += 2)
                result.push_back(i + min_element - 1);
            if (n % 2 == 0)
                for (int i = n - 1; i >= 1; i -= 2)
                    result.push_back(i + min_element - 1);
            else
                for (int i = n; i >= 1; i -= 2)
                    result.push_back(i + min_element - 1);

            return result;
        }
        else if (cost > n * (n - 1) / 2 - 1)
        {
            // cout << "Hello2\n";
            result.push_back(min_element);
            int diff = cost - (n * (n - 1) / 2) + 1;
            vi subresult = construct(n - 1, cost - diff, min_element + 1);
            // for (int i = 0; i < subresult.size(); i++)
            // {
            //     // cout << subresult[i] << "  ";
            // }
            result.insert(result.end(), subresult.begin(), subresult.end());
            reverse(result.begin(), result.begin() + diff);
            // for (int i = 0; i < result.size(); i++)
            // {
            //     // cout << subresult[i] << "  ";
            // }
            return result;
        }
        else
        {
            // cout << "Hello3\n";
            result.push_back(min_element);
            vi subresult = construct(n - 1, cost - 1, min_element + 1);
            result.insert(result.end(), subresult.begin(), subresult.end());
            return result;
        }
    }
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

        int n, cost;
        cin >> n >> cost;
        if (cost < n - 1 || cost > ((n * (n + 1)) / 2) - 1)
        {
            cout << "Case #" << i + 1 << ": IMPOSSIBLE\n";
        }
        else
        {
            cout << "Case #" << i + 1 << ": ";
            vi result = construct(n, cost, 1);
            for (auto element : result)
            {
                cout << element << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}