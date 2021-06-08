#include <bits/stdc++.h>

using namespace std;
 
//#define int int64_t
//#define MOD 998244353
 
int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int cost[2][n];
    int dist[2][n];
    int path[2][n-1];
    for (int i = 0; i < n; i++){
        cout<<"Enter cost for first line: ";
        cin>>cost[0][i];
        cout<<"Enter cost for second line: ";
        cin>>cost[1][i];
        if (i != n-1){
            cout<<"Enter cost for going from first line to second: ";
            cin>>dist[0][i];
            cout<<"Enter cost for going from second line to first: ";
            cin>>dist[1][i];
        }
    }
    dist[0][n-1] = dist[1][n-1] = INT_MAX;
    int icost1, icost2, iout1, iout2;
    cout<<"Enter input cost for first line: ";
    cin>>icost1;
    cout<<"Enter input cost for second line: ";
    cin>>icost2;
    cout<<"Enter out cost for first line: ";
    cin>>iout1;
    cout<<"Enter out cost for second line: ";
    cin>>iout2;
    int a = icost1 + cost[0][0],b = icost2 + cost[1][0];
    for (int i = 0; i < n-1; i++){
        int temp1 = a + cost[0][i+1];
        int temp2 = b + cost[0][i+1] + dist[1][i];
        int temp3 = b + cost[1][i+1];
        int temp4 = a + cost[1][i+1] + dist[0][i];
        // cout<<temp1<<" "<<temp2<<" "<<temp3<<" "<<temp4<<"\n";
        if (temp1 > temp2){
            a = temp2;
            path[0][i] = 2;
        }
        else {
            a = temp1;
            path[0][i] = 1;
        }
        if (temp3 > temp4){
            b = temp4;
            path[1][i] = 1;
        }
        else {
            b = temp3;
            path[1][i] = 2;
        }
    }
    a += iout1;
    b += iout2;
    if (a > b){
        cout<<"Minimum cost is: "<<b<<"\n2 ";
        for (int i = 0; i < n-1; i++){
            cout<<path[1][i]<<" ";
        }
    }
    else {
        cout<<"Minimum cost is: "<<a<<"\n1 ";
        for (int i = 0; i < n-1; i++){
            cout<<path[0][i]<<" ";
        }
    }
    return 0;
}