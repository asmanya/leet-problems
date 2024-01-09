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
    void dfs(TreeNode* root, int low, int high, int& result){
        if(root == NULL) {
            return;
        }
        if(root->val >= low && root->val <= high) {
            result += root->val;
            dfs(root->left, low, high, result);
            dfs(root->right, low, high, result);
        }
        else if(root->val < low) {
            dfs(root->right, low, high, result);
        }
        else if(root->val > high) {
            dfs(root->left, low, high, result);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int result = 0;
        dfs(root, low, high, result);
        return result;
    }       
};