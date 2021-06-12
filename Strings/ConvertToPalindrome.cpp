//Given a string return true, if it is possible to remove only one character so that resulting string is a palindrome.

#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
//#define MOD 998244353

bool isPalin(int j, int k, string str, int n)
{
    for (int i = j; i <= k; i++)
    {
        // cout << str[i] << " " << str[j+k-i ];
        if (str[i] != str[k])
            return false;
        k--;
    }
    return true;
}

int solve(string A)
{
    int n = A.length();
    if (n == 3)
        return (A[0] == A[1] || A[1] == A[2] || A[0] == A[2]);
    int count = 0;
    int j = n - 1;
    for (int i = 0; i < n / 2;)
    {
        if (A[i] != A[j])
        {
            if (isPalin(i + 1, j, A, n) || isPalin(i, j - 1, A, n))
                return 1;
            else
                return 0;
        }
        i++;
        j--;
    }
    // if (n%2 == 0) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    string s;
    while (t--)
    {
        cin >> s;
        cout << solve(s);
    }
    return 0;
}