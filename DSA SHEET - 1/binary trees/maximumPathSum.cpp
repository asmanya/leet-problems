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
    int check(TreeNode* root, vector<int>& ans) {
        if(root == NULL) {
            return 0;
        }
        int valLeft = check(root->left, ans);
        int valRight = check(root->right, ans);
        ans.push_back(max(root->val,max(valLeft + valRight + root->val, max(valLeft + root->val, valRight + root->val))));
        return max(root->val,max(root->val+ valLeft, root->val+ valRight));
    }
public:
    int maxPathSum(TreeNode* root) {
        vector<int> ans; 
        ans.push_back(root->val);
        if(root == NULL) throw runtime_error("invalid");
        check(root, ans);

        int max = INT_MIN;
        for(int i : ans) {
            if(i > max) {
                max = i;
            }
        }
        return max;
    }
};