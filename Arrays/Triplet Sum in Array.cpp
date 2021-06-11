// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find if there exists a triplet in the
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        if (n <= 2)
            return false;
        if (n == 3)
            return A[0] + A[1] + A[2] == X;
        sort(A, A + n);
        int temp, j, k;
        for (int i = n - 1; i >= 2; i--)
        {
            if (A[i] < X)
            {
                temp = X - A[i];
                j = i - 1;
                k = 0;
                while (k < j)
                {
                    if (A[k] + A[j] == temp)
                        return true;
                    if (A[k] + A[j] > temp)
                        j--;
                    else
                        k++;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
// } Driver Code Ends