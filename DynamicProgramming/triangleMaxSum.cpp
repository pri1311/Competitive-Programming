#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int getHeight(int i) {
    int a = 0;
    int c = 0;
    while (true){
        c ++;
        if (i >= a && i < 2*a +1){
            return c;
        }
        else{
            a = 2*a + 1;
        }
    }
    return c;
}
 
int maxSum(int a[], int index, int n) {
    int m;
    if (index <(n*(n+1))/2) {
        m = (n*(n-1))/2;
        int j = getHeight(index);
        if (index >= m) return dp[index] = a[index];
        
        else{
            if (dp[index+j] == -1){
                dp[index + j] = maxSum(a,index +j,n);
            }
            if (dp[index+j+1] == -1){
                dp[index + j +1] = maxSum(a,index +j+1,n);
            }
            return dp[index] = a[index] + max(dp[index + j], dp[index + j +1]);
        }
    }
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int m = (n*(n+1))/2;
    int a[m];
    dp.assign(m,-1);
    for(int i = 0; i < m; i++){
        cin>>a[i];
    }
    cout<<maxSum(a,0,n);
    return 0;
}
