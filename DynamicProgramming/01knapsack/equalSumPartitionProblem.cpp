#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int subsetSum(int w[], int sum, int n){
    if (sum == 0) return 1;
    if (sum!=0 && n==0) return 0;
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < sum+1; j++){
            if (j == 0 || i == 0) dp[i][j] = 0;
            else {
                if (w[i] <= j){
                    dp[i][j] = max(w[i] + dp[i-1][j-w[i]], dp[i-1][j]);
                    if (dp[i][j] == sum) return 1;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n = 0;
    cin>> n;
    int w[n+1];
    w[0] = 0;
    int s = 0;
    for (int i = 1; i < n+1; i++){
        cin>>w[i];
        s += w[i];
    }
    if (s%2 != 0) cout<<"NO";
    else{
        sort(w, w+n);
        dp.assign(n+1, vector<int>(s+1, -1));
        if (subsetSum(w,s/2,n)) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}