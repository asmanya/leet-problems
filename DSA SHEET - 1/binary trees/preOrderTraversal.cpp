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
    void traverse(TreeNode* root, vector<int>& preOrder) {
        if(root == NULL){
            return;
        }
        preOrder.push_back(root->val);
        traverse(root->left, preOrder);
        traverse(root->right, preOrder);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        traverse(root, preOrder);
        return preOrder;
    }
};