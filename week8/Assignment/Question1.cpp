#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18; // large enough

class max_flow
{
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t)
    { // find augmenting path

        d.assign(V, -1); // initialize distance array
        d[s] = 0;        // s is the source, so d[s] = 0

        queue<int> q({s}); // load s on the queue

        p.assign(V, {-1, -1}); // record BFS sp tree

        while (!q.empty())
        {

            int u = q.front();
            q.pop(); // current vertex to be processed

            if (u == t)
                break; // stop as sink t reached

            for (auto &idx : AL[u])
            {
                // auto &[v, cap, flow] = EL[idx];
                auto &edge = EL[idx];
                int v = get<0>(edge);
                ll cap = get<1>(edge);
                ll flow = get<2>(edge);

                if ((cap - flow > 0) && (d[v] == -1))
                { // positive residual edge + unexplored

                    d[v] = d[u] + 1; // set distance
                    q.push(v);       // push on queue
                    p[v] = {u, idx}; // set parent information
                }
            }
        }

        return d[t] != -1; // has an augmenting path
    }

    ll send_one_flow(int s, int t, ll f = INF)
    { // send one flow from s->t

        if (s == t)
            return f; // bottleneck edge f found

        // auto &[u, idx] = p[t];
        auto &parent = p[t];
        int u = get<0>(parent);
        int idx = get<1>(parent);
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);

        ll pushed = send_one_flow(s, u, min(f, cap - flow));
        flow += pushed;

        auto &rflow = get<2>(EL[idx ^ 1]); // back edge
        rflow -= pushed;                   // back flow

        return pushed;
    }

public:
    max_flow(int initialV) : V(initialV)
    {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true)
    {
        if (u == v)
            return; // safeguard: no self loop

        EL.emplace_back(v, w, 0);       // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1); // remember this index

        EL.emplace_back(u, directed ? 0 : w, 0); // back edge
        AL[v].push_back(EL.size() - 1);          // remember this index
    }

    ll edmonds_karp(int s, int t)
    {

        ll maxf = 0; // maxf stands for max_flow

        while (BFS(s, t))
        { // an O(V*E^2) algorithm

            ll f = send_one_flow(s, t); // find and send 1 flow f
            if (f == 0)
                break; // if f == 0, stop
            maxf += f; // if f > 0, add to maxf
        }

        return maxf;
    }
};

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;

    max_flow maxf(17);

    for (int i = 0; i < n; i++)
    {

        char u_c, v_c;
        int u, v, cap;
        cin >> u_c >> v_c >> cap;

        u = u_c - 'A' + 1;
        v = v_c - 'A' + 1;
        if (u == 19)
            u = 0;
        else if (u == 20)
            u = 16;
        if (v == 19)
            v = 0;
        else if (v == 20)
            v = 16;
        maxf.add_edge(u, v, cap);
    }

    cout << maxf.edmonds_karp(0, 16);
    return 0;
}
