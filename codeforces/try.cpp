#include <bits/stdc++.h>
using namespace std;
 
//#define int int64_t
#define MOD 1000000007
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << (long long int)(pow(n, k)) % MOD << "\n";
    }
    return 0;
}