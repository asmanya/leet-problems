#include<iostream>
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
private:
    void traverse(TreeNode* root, vector<int>& inOrder) {
        if(root == NULL){
            return;
        }
        traverse(root->left, inOrder);
        inOrder.push_back(root->val);
        traverse(root->right, inOrder);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        traverse(root, inOrder);
        return inOrder;
    }
};