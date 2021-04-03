#include <bits/stdc++.h>
using namespace std;
 
int optimalSchedule(int a[], int n, int r, int c){
    int opt[n+1];
    for (int i = 0; i < 4; i++){
        opt[i] = r * a[i];
    }
    for (int i = 4; i < n+1; i++){
        opt[i] = min(opt[i-1] + r * a[i], opt[i-4] + 4 * c);
    }
    return opt[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int r,c;
    cin>>r>>c;
    int n;
    cin>>n;
    int a[n+1];
    a[0] = 0;
    for (int i = 1; i < n+1; i++){
        cin>>a[i];
    }
    cout<<optimalSchedule(a, n, r, c);
    return 0;
}