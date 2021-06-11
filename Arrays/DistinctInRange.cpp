#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
//#define MOD 998244353
int countDistinct(int l, int h, int n, int a[])
{
    h = min(h, n - 1);
    unordered_set<int> s;
    // Traverse the input array
    int res = 0;
    for (int i = l; i <= h; i++)
    {

        // If not present, then put it in
        // hashtable and increment result
        if (s.find(a[i]) == s.end())
        {
            s.insert(a[i]);
            res++;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    int n, q;
    while (t--)
    {
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m, b, c;
        while (q--)
        {
            cin >> m;
            if (m == 2)
            {
                cin >> b >> c;
                a[b - 1] = c;
            }
            else
            {
                cin >> b >> c;
                cout << countDistinct(b - 1, c - 1, n, a) << "\n";
            }
        }
    }
    return 0;
}