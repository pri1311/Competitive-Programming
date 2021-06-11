#include <bits/stdc++.h>

using namespace std;

#define int long long
#define mod 1000000007

#define MSET(table, i) memset(table, i, sizeof(table))

const int N = 1e3 + 5;
int dp[N][6];
int n, x;

int solve(int id, int rem)
{
    if (id == n + 1)
        return (rem == 0);
    if (dp[id][rem] != -1)
        return dp[id][rem];

    int ans = 0;
    for (int i = 1; i <= x; i++)
        ans += solve(id + 1, (rem + i) % 5), ans %= mod;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    MSET(dp, -1);
    cout << solve(1, 0);
}