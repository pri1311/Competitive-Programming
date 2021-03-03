// 1557. Minimum Number of Vertices to Reach All Nodes
// link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> temp(n, 0);
        for (int i=0;i<edges.size();i++){
            temp[edges[i][1]]++;
        }
        vector<int>ans;
        for (int i=0;i<n;i++){
            if (temp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Time complexity: O(N+E)
// Space complexity: O(N)