#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
//#define MOD 998244353

string LongPalin(string s)
{
    int n = s.length();
    int start = 0;
    int end = 0;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    string res = to_string(s[0]);
    for (int i = 0; i < n; i++)
    {
        vec[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            vec[i][i + 1] = 1;
            if (end - start + 1 == 1)
            {
                start = i;
                end = i + 1;
            }
        }
    }
    for (int i = n - 3; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (s[i] == s[j] && vec[i + 1][j - 1] == 1)
            {
                vec[i][j] = 1;
                // cout << i << " " << j << "\n";
                if (j - i + 1 >= end - start + 1)
                {
                    start = i;
                    end = j;
                }
            }
        }
    }
    return s.substr(start, end - start + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << LongPalin("aaaabbaa");
    return 0;
}

// Time and Space complexity: O(N*N)