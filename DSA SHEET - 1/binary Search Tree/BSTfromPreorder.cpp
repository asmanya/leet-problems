#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void insert(TreeNode* &root, int key) {
        if(root == NULL) {
            TreeNode* node = new TreeNode(key);
            root = node;
        }
        if(root->val > key) {
            insert(root->left, key);
        }
        if(root->val < key) {
            insert(root->right, key);
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i : preorder) {
            insert(root, i);
        }
        return root;
    }
};