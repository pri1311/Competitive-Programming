#include <bits/stdc++.h>
using namespace std;
 
int optimalSchedule(int a[], int n, int r, int c){
    int opt[n+1];
    char sc[n+1];
    for (int i = 0; i < 4; i++){
        sc[i] = 'A';
        opt[i] = r * a[i];
    }
    for (int i = 4; i < n+1; i++){
        opt[i] = min(opt[i-1] + r * a[i], opt[i-4] + 4 * c);
        if (opt[i-4] + 4*c == opt[i] && opt[i-1] + r*a[i] != opt[i]){
            sc[i-1] = sc[i-2] = sc[i-3] = sc[i] = 'B';
            if (i>=7 && sc[i-7]!='B'){
                sc[i-4] = 'A';
                sc[i-5] = 'A';
                sc[i-6] = 'A';
            }
        }
        else{
            sc[i] = 'A';
        }
    }
    cout<<"Schedule:\n";
    for (int i = 1; i < n+1; i++){
        cout<<sc[i]<<" ";
    }
    cout<<endl;
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
    int result = optimalSchedule(a, n, r, c);
    cout<<"Maximum profit: "<<result;
    return 0;
}