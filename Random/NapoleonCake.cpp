#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin>>n;
        int a[n];
        for (int i = 0; i < n ; i++){
            cin>>a[i];
        }
        int b[n] = {0};
        int x = a[n-1];
        for (int i = n-1; i >= 0; i--){
            x = max(x, a[i]);
            if (x) {
                b[i] = 1;
                x--;
            }
        }
        for (int i = 0; i < n ; i++){
            cout<<b[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}