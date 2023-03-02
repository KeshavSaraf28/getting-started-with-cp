#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> dfs_until_value(vector<vector<int>> &matrix, pair<int, int> start_idx, int target_value)
{
    vector<pair<int, int>> stack;
    set<pair<int, int>> visited;
    int current_value = matrix[start_idx.first][start_idx.second];

    stack.push_back(start_idx);

    while (!stack.empty())
    {
        auto curr_idx = stack.back();
        stack.pop_back();
        int i = curr_idx.first;
        int j = curr_idx.second;
        matrix[i][j] = target_value;
        visited.insert(curr_idx);

        for (auto pairs : vector<pair<int, int>>{{i - 1, j}, {i, j - 1}, {i, j + 1}, {i + 1, j}})
        {
            if (pairs.first >= 0 && pairs.first < matrix.size() && pairs.second >= 0 && pairs.second < matrix[0].size() && visited.find({pairs.first, pairs.second}) == visited.end() && matrix[pairs.first][pairs.second] == current_value)
            {
                stack.push_back({pairs.first, pairs.second});
            }
        }
    }

    return matrix;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int i, j, target_value;
        cin >> i >> j >> target_value;

        auto result = dfs_until_value(matrix, {i, j}, target_value);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == m - 1)
                    cout << result[i][j];
                else
                    cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
