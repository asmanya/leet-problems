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
    void recur(TreeNode* root, int depth, int& maxi) {
        if(root == NULL) {
            return;
        }
        maxi = max(maxi, depth);
        recur(root->left, depth + 1, maxi);
        recur(root->right, depth + 1, maxi);
    }
public:
    int maxDepth(TreeNode* root) {
        int maxi = 0;
        recur(root, 1, maxi);
        return maxi;
    }
};