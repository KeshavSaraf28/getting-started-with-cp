#include <bits/stdc++.h>
using namespace std;

int bfs_shortest_path_length(vector<vector<int>> &matrix, int n)
{
    queue<int> q;
    unordered_set<int> visited;
    int path_length = -1;
    q.push(0);
    visited.insert(0);
    while (!q.empty())
    {
        path_length++;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int cur = q.front();
            q.pop();
            if (cur == n - 1)
            {
                return path_length;
            }
            for (int j = 0; j < n; j++)
            {
                if (matrix[cur][j] == 1 && visited.find(j) == visited.end())
                {
                    q.push(j);
                    visited.insert(j);
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        matrix[x - 1][y - 1] = 1;
        matrix[y - 1][x - 1] = 1;
    }
    if (matrix[n - 1][0] == 0)
    {
        cout << bfs_shortest_path_length(matrix, n) << endl;
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
        cout << bfs_shortest_path_length(matrix, n) << endl;
    }
    return 0;
}
