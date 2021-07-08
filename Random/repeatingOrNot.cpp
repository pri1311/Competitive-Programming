#include <bits/stdc++.h>
using namespace std;
 
//#define int int64_t
//#define MOD 998244353
// bool duplicateOrDistinct(vector<int> arr) {
//     sort(arr.begin(), arr.end());
//     if (arr.size() < 2)
//         return false;
//     for (int i = 1; i < arr.size(); i++){
//         if (arr[i] == arr[i-1])
//             return true;
//     }
//     return false;
// }

bool duplicateOrDistinct(vector<int> arr) {
    map<int, int> m;
    for (auto &num : arr){
        m[num]++;
        if (m[num] == 2)
            return true;
    }
    return false;
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        int temp;
        for (int i = 0; i < n; i++){
            cin >> temp;
            a.push_back(temp);
        }
        temp = 0;
        for (auto &num: a){
            temp ^= num;
        }
        cout << duplicateOrDistinct(a);
    }
    return 0;
}