#include <bits/stdc++.h>

using namespace std;

class TreeNode {
    public:
        char data;
        int freq;
        TreeNode * left, *right;

        TreeNode() {}

        TreeNode(char data, int freq) {
            this->data = data;
            this->freq = freq;
            this->left = this->right = NULL;
        }
};

class Compare {
    public:
        bool operator() (TreeNode* a, TreeNode* b) {
            return a->freq > b->freq;
        }
};

TreeNode* createHuffmanTree(priority_queue<TreeNode*, vector<TreeNode*>, Compare> pq) {
    TreeNode *root;
    if (pq.size() == 1) return pq.top();
    while (pq.size() > 1) {
        TreeNode *node1, *node2;
        node1 = pq.top();
        pq.pop();
        node2 = pq.top();
        pq.pop();
        TreeNode *temp = new TreeNode('+', node1->freq + node2->freq);
        temp->left = node1;
        temp->right = node2;
        pq.push(temp);   
        root = temp;      
    }
    return root;
}

void printCodes(TreeNode *root, int arr[], int top) {
     // Assign 0 to the left node
    // and recur
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left,
                   arr, top + 1);
    }
  
    // Assign 1 to the right
    // node and recur
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
  
    // If this is a leaf node,
    // then we print root->data
  
    // We also print the code
    // for this character from arr
    if (!root->left && !root->right) {
        cout << root->data << ": "<<top;
        // for (int i = 0; i < top; i++) {
        //     cout << arr[i];
        // }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    priority_queue<TreeNode*, vector<TreeNode*>, Compare> pq;
    char c;
    int freq;
    for (int i = 0; i < n; i++) {
        cin>>c;
        cin>>freq;
        TreeNode * node = new TreeNode(c, freq);
        pq.push(node);
    }
    if (n == 1) {
        cout<<c<<": 1";
    }
    else {
        TreeNode *head = createHuffmanTree(pq);
        int arr[1000], top = 0;
        printCodes(head, arr, top);
    }
    return 0;
}