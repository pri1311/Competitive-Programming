#include <bits/stdc++.h>
using namespace std;
 
//#define int int64_t
//#define MOD 998244353

int karatsuba (int a, int b, int n) {
    if (n == 1) return a * b;
    int ah = a / pow(10,n/2);
    int al = a % (int)pow(10,n/2);
    int bh = b / pow(10,n/2);
    int bl = b % (int)pow(10, n/2);
    int temp = karatsuba(ah, bh, n/2);
    int temp2 = karatsuba(al, bl, n/2);
    int temp3 = karatsuba (ah + al, bh + bl, n/2) - temp - temp2;
    return temp*pow(10,n) + temp3*pow(10,n/2) + temp2;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a,b;
    cin >> a >> b;
    cout<<karatsuba(a,b,n);
    return 0;
}