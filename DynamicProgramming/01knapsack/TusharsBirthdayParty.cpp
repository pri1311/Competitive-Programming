#include <bits/stdc++.h>
using namespace std;
 
//#define int int64_t
//#define MOD 998244353
vector<vector<int>> dp;

void knapsack(vector<int> friends, vector<int> capacity, vector<int> cost, int n){
    for (int i = 1; i < 1001; i++)
        dp[0][i] = INT_MAX/2; //Don’t use INT_MAX for the base case, because as you add the dish cost to this INT_MAX, you overflow the int limit, and get the wrong answer. Instead, I suggest you to use INT_MAX/2.
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < 1001; j++)
            {
                // cout << "hello";
                if (j - capacity[i - 1] >= 0)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - capacity[i - 1]] + cost[i - 1]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    int n;
    int temp;
    // cin >> t;
    while (t--) {
        cin >> n;
        vector<int> friends, capacity, cost;
        for (int i = 0; i < n; i++){
            cin >> temp;
            friends.push_back(temp);
        }
        for (int i = 0; i < n; i++){
            cin >> temp;
            capacity.push_back(temp);
        }
        for (int i = 0; i < n; i++){
            cin >> temp;
            cost.push_back(temp);
        }
        dp.assign(n + 1, vector<int>(1001, 0));
        int res = 0;
        knapsack(friends, capacity, cost, n);
        for (int i = 0; i < n; i++){
            res += dp[n][friends[i]];
        }
        cout<< res;
    }
    return 0;
}