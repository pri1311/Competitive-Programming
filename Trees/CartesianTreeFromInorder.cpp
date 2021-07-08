#include <bits/stdc++.h>
using namespace std;
 


//  Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getMax(int low, int high, vector<int> arr) {
    if (low > high) return -1;
    int res = -1;
    int maxVal = INT_MIN;
    for (int i = low; i <= high; i++)
    {
        if (arr[i] > maxVal) {
            maxVal =arr[i];
            res = i;
        }
    }
    return res;
}

TreeNode* createTree(int low, int high, vector<int> arr) {
    int n = getMax(low, high, arr);
    if (n == -1) return NULL;
    TreeNode *root = new TreeNode(arr[n]);
    root->left = createTree(low, n-1, arr);
    root->right = createTree(n+1, high, arr);
    return root;
}

TreeNode* buildTree(vector<int> &A) {
    return createTree(0, A.size()-1,A);
}

void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->val << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}

int main () {
    vector<int> A = { 9, 3, 7, 1, 8, 12, 10, 20, 15, 18, 5};
    TreeNode *root = buildTree(A);
    printInorder(root);
}
