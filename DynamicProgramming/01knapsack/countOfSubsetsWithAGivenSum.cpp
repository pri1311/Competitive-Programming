#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int subsetSum(int w[], int sum, int n){
    int count = 0;
    if (sum == 0) return 0;
    if (sum!=0 && n==0) return 0;
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < sum+1; j++){
            if (j == 0 || i == 0) dp[i][j] = 0;
            else {
                if (w[i] <= j){
                    dp[i][j] = max(w[i] + dp[i-1][j-w[i]], dp[i-1][j]);
                    if (w[i] + dp[i-1][j-w[i]] == sum) count ++;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return count;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n = 0;
    cin>> n;
    int w[n+1];
    w[0] = 0;
    for (int i = 1; i < n+1; i++){
        cin>>w[i];
    }
    sort(w, w+n);
    int s = 0;
    cin>>s;
    dp.assign(n+1, vector<int>(s+1, -1));
    cout<<subsetSum(w,s,n);
    return 0;
}