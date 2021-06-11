#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
//#define MOD 998244353

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
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
            cin >> b >> c;
            if (m == 1)
            {
                a[b - 1] = c;
            }
            else
            {
                priority_queue<int, vector<int>,
                               greater<int>>
                    pq;
                for (int i = b - 1; i < c; i++)
                {
                    pq.push(a[i]);
                }
                int minVal = 1;
                b = pq.top();
                pq.pop();
                c = pq.top();
                pq.pop();
                minVal = b ^ c;
                while (!pq.empty())
                {
                    b = c;
                    c = pq.top();
                    pq.pop();
                    minVal = min(minVal, b ^ c);
                }
                cout << minVal << "\n";
            }
        }
    }
    return 0;
}