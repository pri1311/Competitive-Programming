#include <bits/stdc++.h>
using namespace std;

 
int getMedian(int a[], int b[],int n) {
    if (n==1){
        return (a[0]+b[0])/2;
    }
    else if (n == 2){
        return (max(a[0],a[1])+min(b[0],b[1]))/2;
    }
    else {
        int mediana, medianb;
        if (n%2==0){
            mediana == (a[n/2] + a[(n+1)/2])/2;
            medianb == (b[n/2] + b[(n+1)/2])/2;
        }
        else {
            mediana = a[n/2];
            medianb = b[n/2];
        }
        if (medianb == mediana) return mediana;
        else if (mediana > medianb){
            if (n % 2 == 0)
                return getMedian(b + n/2 - 1, a, n - n/2 + 1);
            return getMedian(b + n/2, a, n - n/2);
        }
        else {
            if (n % 2 == 0)
                return getMedian(a + n/2 - 1, b, n - n/2 +1);
            return getMedian(a + n/2, b, n - n/2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    int b[n];
    for (int i=0;i<m;i++){
        cin>>b[i];
    }
    cout<<getMedian(a,b,n);
    return 0;
}