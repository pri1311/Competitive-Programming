#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
//#define MOD 998244353

bool isValid(int r, int c, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &visited)
{
    return (r < n && r >= 0) && (c < m && c >= 0) && arr[r][c] != 0 && !visited[r][c];
}

int minPath(vector<vector<int>> &arr, int r, int c, int n, int m)
{
    vector<vector<int>> vec(n, vector<int>(m, -1));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    vec[r][c] = 0;
    visited[r][c] = 1;
    int start = -1, end = -1;
    q.push({r, c});
    pair<int, int> p;
    while (!q.empty())
    {
        p = q.front();
        r = p.first;
        c = p.second;
        // cout << r << c<< " ";
        q.pop();
        if (arr[r][c] == 2)
        {
            start = r;
            end = c;
        }
        if (arr[r][c] != 2)
            visited[r][c] = 1;
        if (isValid(r, c + 1, n, m, arr, visited))
        {
            if (arr[r][c + 1] != 2)
                visited[r][c + 1] = 1;
            q.push({r, c + 1});
            if (vec[r][c + 1] == -1)
            {
                vec[r][c + 1] = vec[r][c] + 1;
            }
            else
                vec[r][c + 1] = min(vec[r][c + 1], vec[r][c] + 1);
        }
        if (isValid(r + 1, c, n, m, arr, visited))
        {
            if (arr[r + 1][c] != 2)
                visited[r + 1][c] = 1;
            q.push({r + 1, c});
            if (vec[r + 1][c] == -1)
            {
                vec[r + 1][c] = vec[r][c] + 1;
            }
            else
                vec[r + 1][c] = min(vec[r + 1][c], vec[r][c] + 1);
        }
        if (isValid(r - 1, c, n, m, arr, visited))
        {
            if (arr[r - 1][c] != 2)
                visited[r - 1][c] = 1;
            q.push({r - 1, c});
            if (vec[r - 1][c] == -1)
            {
                vec[r - 1][c] = vec[r][c] + 1;
            }
            else
                vec[r - 1][c] = min(vec[r - 1][c], vec[r][c] + 1);
        }
        if (isValid(r, c - 1, n, m, arr, visited))
        {
            if (arr[r][c - 1] != 2)
                visited[r][c - 1] = 1;
            q.push({r, c - 1});
            if (vec[r][c - 1] == -1)
            {
                vec[r][c - 1] = vec[r][c] + 1;
            }
            else
                vec[r][c - 1] = min(vec[r][c - 1], vec[r][c] + 1);
        }
    }
    if (start == -1)
        return -1;
    return vec[start][end];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    int n, m;
    int r, c;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        cin >> r >> c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        if (arr[r][c] == 0)
            cout << "-1\n";
        else
            cout << minPath(arr, r, c, n, m);
    }
    return 0;
}