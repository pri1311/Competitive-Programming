#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
#define MOD 1000000007

bool isValid(char c)
{
    return (c == 'm') || c == 'a' || c == 'c' || c == 'b' || c == 'o' || c == 'k' || c == 'M' || c == 'A' || c == 'C' || c == 'B' || c == 'O' || c == 'K';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        string s;
        cin >> s;
        long long int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (isValid(s[i]))
            {
                res += ((n - i) % MOD);
            }
        }
        cout << res << "\n";
    }
    return 0;
}