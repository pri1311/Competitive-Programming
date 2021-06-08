#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int low, int mid, int high, int size){
    int i=low, j=mid+1, k=low;
    bool flag = false;
    if (low==0 && high==size-1) flag= true;
    int temp[size]={0};
    while (i<=mid && j<=high){
        if (a[i]<=a[j]){
            temp[k]=a[i];
            i++;
            k++;
        } else{
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while (i<=mid){
        temp[k]=a[i];
            i++;
            k++;
    }
    while (j<=high){
        temp[k]=a[j];
            j++;
            k++;
    }
    for (int i=low; i<=high; i++){
        a[i]=temp[i];
    }
    if (flag){
        for (int i=0;i<size;i++){
            cout<<a[i]<<" ";
        }
    }
}

void mergeSort(int a[], int low, int high, int size){
    if (low < high){
        int mid = (low+high)/2;
        mergeSort(a,low,mid, size);
        mergeSort(a,mid+1,high, size);
        merge(a,low,mid,high, size);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1,n);
}

// Time complexity: O(nlogn)
// Space complexity: O(n)