// 167. Two Sum II - Input array is sorted
// link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int BinarySearch(vector<int>& numbers,int value, int i,int low, int high){
        if (low<=high){
            int mid=(low+high)/2;
            if (value==numbers[mid] && mid!=i){
                return mid;
            }
            else if (value<numbers[mid]){
                return BinarySearch(numbers,value,i,low,mid-1);
            }
            else return BinarySearch(numbers,value,i,mid+1,high);
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int index;
        for (int i=0;i<numbers.size();i++){
            index= BinarySearch(numbers,target-numbers[i],i,0,numbers.size()-1);
            if (index!=-1){
                res.push_back(i+1);
                res.push_back(index+1);
                return res;
            }
        }
    return res;
    }
};