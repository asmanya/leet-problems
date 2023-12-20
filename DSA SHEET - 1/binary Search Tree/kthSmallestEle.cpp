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
public:
    int kthSmallest(TreeNode* root, int k) {
        int val = 1, ans;
        help(root, k, val, ans);
        return ans;
    }
    void help(TreeNode* root, int k, int& val, int& ans) {
        if(!root) return;
        help(root->left, k, val, ans);
        if(val == k) {
            ans = root->val;
        }
        val = val+1;
        help(root->right, k, val, ans);
    }
};