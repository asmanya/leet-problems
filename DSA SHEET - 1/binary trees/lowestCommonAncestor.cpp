#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool getPath(TreeNode* root, int x, vector<TreeNode*>& ans) {
        if(!root) return false;
        ans.push_back(root);

        if(root->val == x) return true;
        if(getPath(root->left, x, ans) || getPath(root->right,x , ans)) {
            return true;
        }
        ans.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecP, vecQ, res;
        getPath(root, p->val, vecP);
        getPath(root, q->val, vecQ);

        for(int i = 0; i < min(vecP.size(), vecQ.size()); i++) {
            if(vecP[i] == vecQ[i]) {
                res.push_back(vecP[i]);
            }
        }
        return res.back();
    }
};