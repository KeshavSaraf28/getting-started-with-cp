#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

class DSU
{
public:
    vector<ll> parent, rank, setsize;
    ll number_of_sets;

    DSU(ll n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        setsize.resize(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            setsize[i] = 1;
        }
        number_of_sets = n;
    }

    ll findset(ll u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        else
        {
            parent[u] = findset(parent[u]);
            return parent[u];
        }
    }

    void unions(ll u, ll v)
    {
        u = findset(u);
        v = findset(v);
        if (u != v)
        {
            if (rank[u] > rank[v])
            {
                swap(u, v);
            }
            if (rank[u] == rank[v])
            {
                rank[v]++;
            }
            parent[u] = v;
            number_of_sets--;
            setsize[v] += setsize[u];
        }
    }

    ll total_sets()
    {
        return number_of_sets;
    }

    ll get_setsize(ll i)
    {
        return setsize[findset(i)];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Read the number of test cases
    ll t;
    cin >> t;

    // Process each test case
    while (t--)
    {
        // Read the input for this test case
        ll n;
        cin >> n;
        vector<ll> A(n), B(n), X(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> B[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> X[i];
        }

        // Count the number of possible permutations of C
        DSU ans(n);
        for (ll i = 0; i < n; i++)
        {
            ans.unions(A[i], B[i]);
        }
        set<ll> unique;
        for (ll i = 1; i <= n; i++)
        {
            if (ans.get_setsize(i) > 1)
            {
                unique.insert(ans.findset(i));
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (X[i] != 0)
            {
                unique.erase(ans.findset(X[i]));
            }
        }
        // cout << (ll)(pow(2, unique.size())) % MOD << "\n";
        ll answer=1;
        for(ll i = 0; i < unique.size(); i++)
        {
            answer = (answer * 2) % MOD;
        }
        cout << answer << "\n";
    }

    return 0;
}
