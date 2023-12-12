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
 

// This is also known as BFS
class Solution {
private:
    void traverse(TreeNode* root, vector<vector<int>>& res) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> terms;
            for(int i = 0; i < size; i++) {
                TreeNode* ref = q.front();
                q.pop();
                if(ref->left != NULL) q.push(ref->left);
                if(ref->right != NULL) q.push(ref->right);
                terms.push_back(ref->val);
            }
            res.push_back(terms);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        traverse(root, res);
        return res;
    }
};