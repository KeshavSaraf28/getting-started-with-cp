#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int;

int reversort(vi &L)
{
    int cost = 0;
    for (int i = 0; i < L.size() - 1; i++)
    {
        int m = *min_element(L.begin() + i, L.end());
        auto x = find(L.begin() + i, L.end(), m);
        reverse(L.begin() + i, x + 1);
        cost += distance(L.begin(), x) - i + 1;
    }
    return cost;
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
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int length = 0;
        std::cin >> length;
        vi list;
        for (int j = 0; j < length; j++)
        {
            int number = 0;
            cin >> number;
            list.push_back(number);
        }
        cout << "Case #" << i << ": " << reversort(list) << endl;
    }

    return 0;
}