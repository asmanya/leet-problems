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
    void f(TreeNode* root, int& sum) {
        if(root->left == nullptr && root->right == nullptr) return;
        if(root->left && root->left->left == nullptr && root->left->right == nullptr) sum += root->left->val;

        if(root->left) f(root->left, sum);
        if(root->right) f(root->right, sum);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        f(root, sum);

        return sum;
    }
};