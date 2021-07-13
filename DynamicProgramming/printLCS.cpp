#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
//#define MOD 998244353

void printLCS(const vector<vector<int>> &dp, int n, int m, string s)
{
    if (n == 0 || m == 0)
        return;
    if (dp[n - 1][m - 1] == dp[n][m])
        printLCS(dp, n - 1, m - 1, s);
    else if (dp[n - 1][m] == dp[n][m])
        printLCS(dp, n - 1, m, s);
    else if (dp[n][m - 1] == dp[n][m])
        printLCS(dp, n, m - 1, s);
    else
    {
        printLCS(dp, n - 1, m - 1, s);
        cout << s[n - 1];
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int x = s1.length(), y = s2.length();
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[x][y] << "\n";
        printLCS(dp, x, y, s1);
    }
    return 0;
}