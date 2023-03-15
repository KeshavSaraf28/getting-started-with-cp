#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ii pair<int, int>
typedef long long ll;

int minimum_spannng_tree_cost(vector<vector<pair<int, int>>> AL, int n, int m)
{
    int w, v, cost = 0;
    int visited[n] = {0};
    visited[0] = 1;
    int total_visited = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (auto &it : AL[0])
        pq.push(make_pair(it.second, it.first));
    while (!pq.empty())
    {
        auto &it = pq.top();
        v = it.second;
        w = it.first;
        pq.pop();
        if (visited[v] == 0)
        {
            visited[v] = 1;
            cost += w;
            total_visited++;
            for (auto &it : AL[v])
                pq.push({it.second, it.first});
        }
        if (total_visited == n - 1)
            break;
    }

    return cost;
};

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
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> AL(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u -= 1;
            v -= 1;
            AL[u].push_back(make_pair(v, w));
            AL[v].push_back(make_pair(u, w));
        }
        cout << minimum_spannng_tree_cost(AL, n, m) << endl;
    }
    return 0;
}