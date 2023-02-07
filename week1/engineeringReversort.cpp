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
        result.push_back(min_element);

        if ((cost - 1) >= n - 2 && (cost - 1) <= (n * (n - 1) / 2) - 1)
        {
            // if the cost-1 is within bounds for n-1 elements.
            // then place min_element at beginning and pass it next recursion.
            // min_element will increased for next recursion
            vi subresult = construct(n - 1, cost - 1, min_element + 1);
            result.insert(result.end(), subresult.begin(), subresult.end());
            return result;
        }
        else
        {
            // add the subresult array to result array with min_element.
            // reverse first "diff" elements to get the desired array.
            int diff = cost - (n * (n - 1) / 2) + 1;
            vi subresult = construct(n - 1, cost - diff, min_element + 1);
            result.insert(result.end(), subresult.begin(), subresult.end());
            reverse(result.begin(), result.begin() + diff);
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