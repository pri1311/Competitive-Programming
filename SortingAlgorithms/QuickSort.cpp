#include <bits/stdc++.h>

using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[high];
    int j=low;
    for (int i=low; i<high;i++){
        if (a[i]<=pivot){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[j],a[high]);
    return j;
}

void quickSort(int a[], int low, int high){
    if (low < high){
        int p= partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

// Time complexity: O(nlogn)
// Space complexity: O(logn)