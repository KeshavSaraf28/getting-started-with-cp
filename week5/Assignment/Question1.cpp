#include <bits/stdc++.h>
using namespace std;

int bfs_shortest_path_length(int n, vector<vector<int>> &matrix)
{
    queue<int> q;
    unordered_set<int> visited;
    int path_length = -1;
    q.push(0);
    visited.insert(0);
    while (!q.empty())
    {
        path_length += 1;
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            int cur = q.front();
            q.pop();
            if (cur == n - 1)
            {
                return path_length;
            }
            for (int i = 0; i < n; i++)
            {
                if (matrix[cur][i] == 1 && visited.find(i) == visited.end())
                {
                    q.push(i);
                    visited.insert(i);
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        matrix[x - 1][y - 1] = 1;
        matrix[y - 1][x - 1] = 1;
    }
    if (matrix[0][n - 1] == 0)
    {
        cout << bfs_shortest_path_length(n, matrix) << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0 && i != j)
                {
                    matrix[i][j] = 1;
                }
                else
                {
                    matrix[i][j] = 0;
                }
            }
        }

        cout << bfs_shortest_path_length(n, matrix) << endl;
    }
    return 0;
}