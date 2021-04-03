#include <bits/stdc++.h>
using namespace std;

int getHeight(int i) {
    int a = 0;
    int c = 0;
    while (true){
        c ++;
        if (i >= a && i < 2*a +1){
            break;
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
        if (index >= m) return a[index];
        else return a[index] + max(maxSum(a,index +j,n), maxSum(a,index + j+1,n));
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
    for(int i = 0; i < m; i++){
        cin>>a[i];
    }
    cout<<maxSum(a,0,n);
    return 0;
}