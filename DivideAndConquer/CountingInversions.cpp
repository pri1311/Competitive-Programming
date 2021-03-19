#include <bits/stdc++.h>

using namespace std;

long int c =0;

void merge(long int a[],long int low,long int mid,long int high,long int size){
    long int i=low, j=mid+1, k=low;
    bool flag = false;
    if (low==0 && high==size-1) flag= true;
    long int temp[size];
    while (i<=mid && j<=high){
        if (a[i]<=a[j]){
            temp[k++]=a[i++];
        } else{
            temp[k++]=a[j++];
            c+=(mid+1-i);
        }
    }
    while (i<=mid){
        temp[k++]=a[i++];
    }
    while (j<=high){
        temp[k++]=a[j++];
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

void mergeSort(long int a[],long int low,long int high,long int size){
    if (low < high){
        long int mid = (low+high)/2;
        mergeSort(a,low,mid, size);
        mergeSort(a,mid+1,high, size);
        merge(a,low,mid,high, size);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        long int n;
        c=0;
    cin>>n;
    long int a[n];
    for (long int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1,n);
    cout <<c<<endl;
    }
}

// Time complexity: O(nlogn)
// Space complexity: O(n)
