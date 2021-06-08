#include <bits/stdc++.h>
using namespace std;
 
//#define int int64_t
#define MOD 998244353
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> d = {1,2,5};
    int m = d.size();
    long long int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if ( i == 0 && j == 0) dp[i][j] = 0;
            else if (i == 0) dp[i][j] = MOD;
            else if (j == 0) dp[i][j] = 0;
            else {
                if (d[i-1] <= j) {
                    dp[i][j] = min (dp[i-1][j], dp[i][j-d[i-1]] + 1);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    if (dp[m][n] == MOD) cout<<"-1\n";
    else cout << dp[m][n];
    return 0;
}