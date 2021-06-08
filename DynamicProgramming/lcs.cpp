#include <bits/stdc++.h>
using namespace std;
 
//#define int int64_t
//#define MOD 998244353

vector<vector<int>> dp;

int lcs(int n, int m, string x, string y){
    if (n == 0 || m == 0) return 0;
    else if (dp[m][n] != -1) return dp[m][n];

    if (x[n-1] == y[m-1]) {
        return dp[m][n] = lcs(n - 1, m - 1, x, y) + 1;
    }
    int left, right;
    if (dp[m][n-1] != -1) left = dp[m][n-1];
    else left = dp[m][n-1] = lcs(n-1,m,x,y);
    if (dp[m-1][n] != -1) right = dp[m-1][n];
    else right = dp[m-1][n] = lcs(n,m-1,x,y);
    return dp[m][n] = max(left, right);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string x, y;
    cin>>x>>y;
    int n = x.length(), m = y.length();
    dp.assign(m+1,vector<int>(n+1, -1));
    lcs(n,m,x,y);
    cout<<dp[m-1][n-1];
    return 0;
}