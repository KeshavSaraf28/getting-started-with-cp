#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
typedef long long ll;

class DSU
{
private:
    vi parent;
    int number_of_sets;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
            parent.push_back(i);
        number_of_sets = n;
    }

    int findset(int u)
    {

        if (parent[u] == u)
            return u;
        else
        {
            parent[u] = findset(parent[u]);
            return parent[u];
        }
    }

    void unions(int u, int v)
    {
        u = findset(u);
        v = findset(v);
        if (u != v)
        {
            parent[u] = v;
            number_of_sets--;
        }
    }
    int total_sets() { return number_of_sets; }
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
        DSU answer(n);
        for (int i = 0; i < m; i++)
        {

            int u, v;
            cin >> u >> v;
            answer.unions(u, v);
        }
        cout << answer.total_sets() << "\n";
    }
    return 0;
}