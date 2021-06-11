#include <bits/stdc++.h>
using namespace std;

//#define int int64_t
//#define MOD 998244353

int binarySearch(vector<int> &arr, int val, int low, int high, int n)
{
    if (low == high && low == 0)
    {
        if (arr[low] == val)
            return 0;
        else
            return -1;
    }
    if (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] > val && arr[mid - 1] <= val)
        {
            return mid - 1;
        }
        else if (val >= arr[mid])
        {
            return binarySearch(arr, val, mid + 1, high, n);
        }
        else
            return binarySearch(arr, val, low, mid - 1, n);
    }
    return -1;
}

int solve(vector<int> &A, int B)
{
    int n = A.size();
    if (A[n - 1] <= B)
        return n;
    if (A[0] > B)
        return 0;
    int res = binarySearch(A, B, 0, n - 1, n);
    while (res + 1 < n && A[res] == A[res + 1])
    {
        res++;
    }
    return res + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> a = {3, 4, 5, 17, 19, 22, 27, 33, 37, 42, 43, 46, 48};
    cout << solve(a, 22);
    return 0;
}