#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int knapsack(int w[], int p[], int c, int n){
    if (n == 0 || c == 0){
        return 0;
    }
    if (dp[n][c] != -1){
        return dp[n][c];
    }
    if (w[n] <= c){
        return dp[n][c] = max(p[n]+ knapsack(w,p,c- w[n],n-1), knapsack(w,p,c,n-1));
    }
    if (w[n] > c){
        return dp[n][c] = knapsack(w,p,c,n-1);
    }
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n = 0;
    cin>> n;
    int w[n], p[n];
    for (int i = 0; i < n; i++){
        cin>>w[i];
    }
    for (int i = 0; i < n; i++){
        cin>>p[i];
    }
    int c = 0;
    cin>>c;
    dp.assign(n+1, vector<int>(c+1, -1));
    cout <<knapsack(w,p,c,n);
    return 0;
}