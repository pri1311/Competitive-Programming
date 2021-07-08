#include <bits/stdc++.h>
using namespace std;
 
//#define int int64_t
//#define MOD 998244353
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int temp;
        long int sum = 0;
        vector<int> a;
        for (int i = 0; i < n; i++){
            cin >> temp;
            sum += temp;
            a.push_back(temp);
        }
        long int res = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= sum; j++){
                if (a[i] <= j){
                    dp[i][j] = max(a[i] + dp[i-1][j-a[i]], dp[i-1][j]);
                    res = min(res, abs(sum - (2 * dp[i][j])));
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}