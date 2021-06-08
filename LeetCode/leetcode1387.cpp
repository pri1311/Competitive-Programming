// 1387. Sort Integers by The Power Value
// link: https://leetcode.com/problems/sort-integers-by-the-power-value/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:   
    bool static cmp(pair<int, int>& a, 
         pair<int, int>& b) 
    { 
        if (a.second==b.second){
            return a.first<b.first;
        }
        return a.second <= b.second; 
    } 
 
    int sortmap(map<int, int>& M,int k) 
    { 

        vector<pair<int, int> > A; 
        for (auto& it : M) {
            A.push_back(it); 
        } 
        
        if (A.empty()) cout<<"hello";

        sort(A.begin(), A.end(), cmp); 
        
        int i=1;
        
        for (auto& it : A){
            if (i==k){
                return it.first;
            }
            i++;
        }
        
        return -1;
    }
    int getKth(int lo, int hi, int k) {
        queue<int> wl;
        map<int,int> res;
        map<int, int>::iterator itr; 
        int temp,count=0;
        for (int i=lo;i<=hi;i++){
            itr = res.find(i);
            if (itr==res.end()){
                temp=i;
                count=0;
                while(temp!=1){
                    if (temp%2==0){
                        temp/=2;
                    }
                    else{
                        temp=3*temp+1;
                    }
                    wl.push(temp);
                    count++;
                }
                res.insert(pair<int, int>(i, count));
                while(!wl.empty()){
                    count--;
                    temp=wl.front();
                    wl.pop();
                    itr = res.find(temp);
                    if (temp>=lo && temp<=hi &&itr==res.end()){
                        res.insert(pair<int,int>(temp,count));
                    }
                }
            }
        }
        
        return sortmap(res,k);
        
    }
};