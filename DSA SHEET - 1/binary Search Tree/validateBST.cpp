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
    bool help(TreeNode* root, long long& prev) {
        if(!root) return true;
        bool first = help(root->left, prev);
        if(prev >= root->val) return false;
        prev = root->val;
        bool second = help(root->right, prev);
        return first && second;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return help(root, prev);
    }
};